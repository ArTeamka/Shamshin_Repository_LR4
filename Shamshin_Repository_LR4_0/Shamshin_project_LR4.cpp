#include <iostream>
#include <map>
#include <functional>
using namespace std;

char ch1, ch2;

// Функции ввода данных (заглушки)
void EnterChar1() {

}
void EnterChar2() {

}

// Функции вывода ASCII и суммы кодов
void PrintASCII() {

}
void SumASCII() {

}

struct MenuItem {
    string title;
    function<void()> action;
};

int main() {
    map<int, MenuItem> menu = {
        {1, {"Ввод первого символа (ch1)", EnterChar1}},
        {2, {"Ввод второго символа (ch2)", EnterChar2}},
        {3, {"Вывод ASCII кодов символов", PrintASCII}},
        {4, {"Вывод суммы ASCII кодов", SumASCII}}
    };

    int choice = 0;
    while (true) {
        cout << "Меню:" << endl;
        for (const auto& item : menu) {
            cout << item.first << ". " << item.second.title << endl;
        }
        cout << "0. Выход" << endl;
        cout << "Введите номер пункта: ";
        cin >> choice;

        if (choice == 0) break;
        if (menu.find(choice) != menu.end()) {
            menu[choice].action();
        } else {
            cout << "Ошибка ввода!" << endl;
        }
    }
    return 0;
}