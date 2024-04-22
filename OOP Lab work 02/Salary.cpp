#include "Salary.h"

Salary::Salary() {
    return;
}

Salary::~Salary() {
    return;
}

Salary::Salary(std::string f, double c, int b) {
    fio = f;
    casing = c;
    bonus = b;
}

Salary::Salary(Salary& s) {
    fio = s.fio;
    casing = s.casing;
    bonus = s.bonus;
}

void Salary::setFio(std::string f) {
    fio = f;
}

void Salary::setCasing(double c) {
    casing = c;
}

void Salary::setBonus(int b) {
    bonus = b;
}

std::string Salary::getFio() {
    return fio;
}

double Salary::getCasing() {
    return casing;
}

int Salary::getBonus() {
    return bonus;
}