#include <iostream>
#include <vector>
#include <string>
#include "table.h"
using namespace std;

bool isInt(const string& s) {
    if (s.empty()) return false;

    int start = 0;
    if (s[0] == '-') start = 1;

    for (int i = start; i < s.length(); i++) {
        if (!isdigit(s[i])) return false;
    }
    return true;
}

bool isInRange(int value, int lower, int upper) {
    if (value < lower || value > upper) {
        return false;
    }
    return true;
}

// функция валидации данных перед вставкой в таблицу
bool validateInsert(string value, Column& column) {
    if (column.type == "int" && isInt(value)) {

        int lower, upper;
        if (column.name == "age") lower = 0, upper = 100;
        else if (column.name == "salary") lower = 0, upper = 1000000;

        if (isInRange(stoi(value), lower, upper)) return isInt(value);

        else {
            cout << "\nЗначение в колонке " << column.name << " вне допустимого диапазона " << lower << " - " << upper << endl;
            return false;
        }
    }
    else if (column.type == "string" && !isInt(value)) {
        for (char c : value) {
            if (isdigit(c)) {
                cout << "\nВ строке недопустимый символ для типа string: " << c << endl;
                return false;
            }
        }
    }
    else {
        cout << "\nНеверный тип данных для колонки " << column.name << ". Ожидался тип " << column.type << endl;
        return false;
    }
    return true;
}

// функция вставки новой строки в таблицу
void Table::insert(vector<string>& values) {

    if (values.size() != columns.size()) {
        cout << "\nНеверное количество данных\n";
        return;
    } 

    vector<string> row;

    for (int i = 0; i < columns.size(); i++) {
        
        if (!validateInsert(values[i], columns[i])) {
            cout << "\nОшибка при добавлении записи. Запись не добавлена.\n";
            return;
        }
        row.push_back(values[i]);
    }

    cout << "\nДобавлена новая запись.\n";
    rows.push_back(row);
}

void printCell(string value, int width) {
    cout << " " << value;
    
    int spaces = width - 1 - value.length(); 
    if (spaces < 0) spaces = 0;
    for (int i = 0; i < spaces; i++) cout << " ";
    
    cout << "|";
}

void printRow(vector<int>& widths, vector<string>& row) {
    cout << "|";
    for (int i = 0; i < row.size(); i++) {
        printCell(row[i], widths[i]);
    }
    cout << endl;
}

void printBorder(vector<int> widths) {
    cout << "+";
    for (int w : widths) cout << string(w, '-') << "+";
    cout << endl;
}

void printHeader(string title, int width) {
    string message = "Table [ " + title + " ]";
    cout << string(width, '=') << endl;
    int padding = (width - message.length()) / 2;
    if (padding < 0) padding = 0;
    cout << string(padding, ' ') << message << endl;
    cout << string(width, '=') << endl;
}

void Table::print() {

    if (columns.empty()) return;

    // вычисление ширины каждой колонки
    vector<int> widths;
    for (int i = 0; i < columns.size(); i++) {
        widths.push_back(getColumnWidth(i));
    }

    int tableWidth = 1;
    for (auto& w : widths) tableWidth += w + 1;

    cout << endl;
    printHeader(name, tableWidth);

    //строка с именами колонок
    printBorder(widths);

    cout << "|";
    for (int i = 0; i < columns.size(); i++) {
        printCell(columns[i].name, widths[i]);
    }
    cout << endl;

    // сами строки с разделением
    printBorder(widths);

    for (auto& row : rows) {
        printRow(widths, row);
        printBorder(widths);
    }
}