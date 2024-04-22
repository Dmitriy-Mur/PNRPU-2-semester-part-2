#pragma once
#include <iostream>

class Salary {
private:
    std::string fio;
    double casing;
    int bonus;
public:
    Salary();
    Salary(std::string f, double c, int b);
    Salary(Salary& s);
    ~Salary();
    void setFio(std::string f);
    void setCasing(double c);
    void setBonus(int b);
    std::string getFio();
    double getCasing();
    int getBonus();
};
