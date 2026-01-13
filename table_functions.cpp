#include <iostream>
#include <vector>
#include <string>
#include "table.h"
using namespace std;

void Table::deleteByNumber(int number) {
    if (number < 0 || number >= rows.size()) {
        cout << "\nЗапись не найдена\n";
        return;
    }

    rows.erase(rows.begin() + number);
    cout << "\nУдалена запись номер " << number << endl;
}

void Table::findByField(string field, string value) {
    int index = -1;

    for (int i = 0; i < columns.size(); i++) {
        if (columns[i].name == field) index = i;
    }

    if (index == -1) {
        cout << "\nПоле не найдено\n";
        return;
    }

    Table result;
    result.init("Results");
    result.addColumn("name", "string");
    result.addColumn("age", "int");
    result.addColumn("salary", "int");
    for (int i = 0; i < rows.size(); i++) {
        if (rows[i][index] == value) result.rows.push_back(rows[i]);
    }

    if (!result.rows.empty()) {
        cout << "\nНайдены следующие записи:\n";
        result.print();
    }
    else cout << "\nРезультаты не найдены.\n";
}

void Table::sortByField(string field, bool reversed) {
    int index = -1;

    for (int i = 0; i < columns.size(); i++) {
        if (columns[i].name == field) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "\nПоле не найдено\n";
        return;
    }

    string type = columns[index].type;

    for (int i = 0; i < rows.size(); i++) {
        for (int j = 0; j < rows.size() - i - 1; j++) {

            // int
            if (type == "int") {
                int a = stoi(rows[j][index]);
                int b = stoi(rows[j + 1][index]);
                if (!reversed){
                    if (a > b) swap(rows[j], rows[j + 1]);
                }
                else {
                    if (a < b) swap(rows[j], rows[j + 1]);
                }
            }
            // string
            else { 
                if (!reversed){
                    if (rows[j][index] > rows[j + 1][index]) {
                        swap(rows[j], rows[j + 1]);
                    }
                }
                else {
                    if (rows[j][index] < rows[j + 1][index]) {
                        swap(rows[j], rows[j + 1]);
                    }
                }
            }
        }
    }
    cout << "\nТаблица отсортирована по полю " << field << endl;
}