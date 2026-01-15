#include <iostream>
#include <string>
#include <windows.h>
#include "table.h"
#include "ui.h"

using namespace std;

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
                cout << "Введите данные пользователя по порядку [ Имя, Возраст, Зарплата ] через пробел. Чтобы закончить введите 0.\n";
                while (cin >> s && s != "0") {
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
                string number;
                cin >> number;
                if (!isInt(number)) {
                    cout << "\nВведите номер, а не буквы!\n";
                    pause();
                    break;
                }
                table.deleteByNumber(stoi(number));
                pause();
                break;
            }
            case 4: {
                cout << "Поиск по полю.\n";
                cout << "Введите поле (название колонки): ";
                string field;
                cin >> field;
                for (int i = 0; i < field.length(); i++) {
                    field[i] = tolower(field[i]);
                }
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
                for (int i = 0; i < field.length(); i++) {
                    field[i] = tolower(field[i]);
                }

                cout << "\nСортировка по возрастанию(0) или убыванию(1): ";
                string choice;
                cin >> choice;
                

                if (choice == "0") table.sortByField(field);
                else if (choice == "1") table.sortByField(field, true);
                else cout << "\nНеверный ввод!\n";
                pause();
                break;
            }
            case 6: {
                cout << "Сохранение и загрузка в/из файла\n";
                cout << "  0. Вернуться\n";
                cout << "  1. Сохранить файл\n";
                cout << "  2. Загрузить файл\n";
                cout << "Выберите пункт меню -> ";
                string choice;
                cin >> choice;
                if (!isInt(choice)) {
                    cout << "\nВведите номер, а не буквы!\n";
                    pause();
                    break;
                }
                if (choice != "0" && choice != "1" && choice != "2") {
                    cout << "\nНеверный пункт меню!\n";
                    pause();
                    break;
                }
                if (choice == "0") break;

                cout << "\nВведите название файла: ";
                string filename;
                cin >> filename;
                if (isInt(filename)) {
                    cout << "\nВведите название файла с расширением, а не цифры!\n";
                    pause();
                    break;
                }

                if (choice == "1") table.saveToFile(filename);
                else if (choice == "2") table.loadFromFile(filename);
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