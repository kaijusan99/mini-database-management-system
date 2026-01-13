#include <iostream>
#include <string>
#include <windows.h>
#include "table.h"

using namespace std;

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

int main() {
    // setlocale(LC_ALL, "Russian");
    // SetConsoleCP(1251);   
    // SetConsoleOutputCP(1251); 
    SetConsoleTitle(TEXT("Мини СУБД"));
    Table table;
    table.init("Users");
    table.addColumn("name", "string");
    table.addColumn("age", "int");
    table.addColumn("salary", "int");

    bool isEnded = false;
    while (!isEnded) { 

        clearScreen();
        printMenu(table.name);

        string choice;
        cin >> choice;
        if (isInt(choice) == false) {
            cout << "\nВведите номер, а не буквы!\n";
            pause();
            continue;
        }
        int choiceNum = stoi(choice);

        clearScreen();

        cout << endl;
        switch (choiceNum) {
            case 0: {
                isEnded = true;
                break;
            }
            case 1: {
                vector<string>data;
                string s;
                cout << "\nВы добавляете запись.\n";
                cout << "Введите данные пользователя по порядку [ Имя, Возраст, Зарплата ]: ";
                for (auto& column : table.columns) {
                    cin >> s;
                    data.push_back(s);
                }
                table.insert(data);
                pause();
                break;
            }
            case 2: {
                cout << "Вывод всех записей: \n";
                table.print();
                pause();
                break;
            }
            case 3: {
                cout << "Удаление записи. Введите номер: ";
                int number;
                cin >> number;
                table.deleteByNumber(number);
                pause();
                break;
            }
            case 4: {
                cout << "Поиск по полю.\n";
                cout << "Введите поле (название колонки): ";
                string field;
                cin >> field;

                cout << "Введите значение поля: ";
                string value;
                cin >> value;

                table.findByField(field, value);
                pause();
                break;
            }
            case 5: {
                cout << "Сортировка по полю.\n";
                cout << "Введите поле (название колонки): ";
                string field;
                cin >> field;

                cout << "\nСортировка по возрастанию(0) или убыванию(1): ";
                int choice;
                cin >> choice;
                
                if (choice == 0) table.sortByField(field);
                else if (choice == 1) table.sortByField(field, true);
                pause();
                break;
            }
            case 6: {
                cout << "Сохранение и загрузка в/из файла\n";
                cout << "  1. Сохранить файл\n";
                cout << "  2. Загрузить файл\n";
                cout << "  0. Вернуться\n";
                cout << "Выберите пункт меню -> ";
                int choice;
                cin >> choice;

                if (choice == 0) break;

                cout << "\nВведите название файла: ";
                string filename;
                cin >> filename;

                if (choice == 1) table.saveToFile(filename);
                else if (choice == 2) table.loadFromFile(filename);
                pause();
                break;
            }
            default: {
                cout << "\nНеверный пункт меню!\n";
                pause();
                break;
            }
        }
    }
    clearScreen();
    cout << "\nВы вышли из программы.\n";
    clearScreen();
}