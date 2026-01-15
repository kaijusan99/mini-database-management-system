#include <windows.h>
#include <string>
#include <iostream>
#include "table.h"

void printMenu(string tableName) {
    cout << "\n==================================================\n";
    cout << "                 М И Н И   С У Б Д               \n";
    cout << "==================================================\n";

    cout << "Таблица: " << tableName;
    cout << "\n==================================================\n";

    cout << "  1. Добавление записи\n";
    cout << "  2. Вывод всех записей\n";
    cout << "  3. Удаление записи по номеру\n";
    cout << "  4. Поиск по полю\n";
    cout << "  5. Сортировка по выбранному полю\n";
    cout << "  6. Сохранение и загрузка в/из файла\n";
    cout << "  0. Выход\n";
    cout << "==================================================\n";
    cout << "Выберите пункт меню -> ";
}

 
void clearScreen() {
    system("cls");
}

void pause() {
    cout << "\nНажмите Enter...";
    cin.ignore();
    cin.get();
}