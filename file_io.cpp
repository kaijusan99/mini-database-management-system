#include <iostream>
#include <fstream> 
#include <sstream>
#include "table.h"

void Table::saveToFile(string filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "\nНе удалось открыть файл для записи\n";
        return;
    }

    for (auto& row : rows) {
        for (auto& value : row) {
            file << value << " ";
        }
        file << endl;
    }

    file.close();
    cout << "\nТаблица сохранена в файл " << filename << endl;
}

void Table::loadFromFile(string filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "\nНе удалось открыть файл\n";
        return;
    }

    rows.clear();

    string line;
    while (getline(file, line)) {
        vector<string> row;
        string value;
        stringstream ss(line);
        if ( isInt(value) && columns.size() > 0 && columns[0].type == "string" ||
             !isInt(value) && columns.size() > 0 && columns[0].type == "int" ) {
            cout << "\nОшибка: неверный формат данных в файле\n";
            return;
        }
        int i = 0;
        while (ss >> value) {
            if (i != columns.size()) {
                cout << "\nОшибка: количество столбцов в файле не соответсвует количеству в таблице\n";
                row.clear();
                return;
            }
            if (validateInsert(value, columns[i])) {
                row.push_back(value);
            }
            else {
                row.clear();
                return;
            }
            i++;
        }
        if (!row.empty())
            rows.push_back(row);
    }

    file.close();
    cout << "\nТаблица загружена из файла " << filename << endl;
}