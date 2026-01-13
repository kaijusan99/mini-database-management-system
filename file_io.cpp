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

        while (ss >> value) {
            row.push_back(value);
        }
        if (row.size() != columns.size()) {
            cout << "\nОшибка: количество столбцов в файле не соответствует таблице\n";
            continue;
        }
        if (!row.empty())
            rows.push_back(row);
    }

    file.close();
    cout << "\nТаблица загружена из файла " << filename << endl;
}