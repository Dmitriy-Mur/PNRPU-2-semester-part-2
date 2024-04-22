#pragma once
#include <iostream>
#include "Person.h"

class Student : public Person {
private:
    std::string subject;
    int grade;
public:
    Student();
    Student(std::string n, int a, std::string sub, int g);
    void setSubject(std::string sub) { subject = sub; }
    void setGrade(int g) { grade = g; }
    void checkGrade();
    friend std::ostream& operator<<(std::ostream& out, const Student& s);
};
