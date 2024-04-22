#include <iostream>
#include <string>
#include "Salary.h"
using namespace std;

int main() {
    system("chcp 1251>null");
    Salary salary;
    cout << "Введите ФИО: ";
    string fio;
    getline(cin, fio);
    salary.setFio(fio);
    cout << "Введите оклад: ";
    double casing;
    cin >> casing;
    salary.setCasing(casing);
    cout << "Введите премию: ";
    int bonus;
    cin >> bonus;
    salary.setBonus(bonus);
    cout << "Полученные поля:\n";
    cout << "ФИО:" << salary.getFio() << '\n';
    cout << "Оклад:" << salary.getCasing() << '\n';
    cout << "Премия:" << salary.getFio() << '\n';
    cout << "salary2(\"О.Ф.М.\", 25.300, 25):\n";
    Salary salary2("О.Ф.М.", 25.300, 25);
    cout << "ФИО:" << salary2.getFio() << '\n';
    cout << "Оклад:" << salary2.getCasing() << '\n';
    cout << "Премия:" << salary2.getFio() << '\n';
    cout << "salary3(salary2):\n";
    Salary salary3(salary2);
    cout << "ФИО:" << salary3.getFio() << '\n';
    cout << "Оклад:" << salary3.getCasing() << '\n';
    cout << "Премия:" << salary3.getFio() << '\n';

    return 0;
}
