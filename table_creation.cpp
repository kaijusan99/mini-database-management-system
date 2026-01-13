#include <iostream>
#include <vector>
#include <string>
#include "table.h"
using namespace std;

void Table::init(string tableName) {
    name = tableName;
    rows.clear();
    columns.clear();
}

// функция для вычисления длины колонки по максимальной длине строки в этой колонке, включая имя колонки
int Table::getColumnWidth(int column) {
    int width = columns[column].name.length();
    for (auto& row : rows) {
        if (column < row.size() && row[column].length() > width) {
            width = row[column].length();
        }
    }
    return width + 2;
}

void Table::addColumn(string name, string type) {
    Column column;
    column.name = name;
    column.type = type;
    columns.push_back(column);
}