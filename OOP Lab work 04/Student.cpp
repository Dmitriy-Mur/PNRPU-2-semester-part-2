#include <iostream>
#include "Student.h"

Student::Student() {
    std::cout << "Call base Student constructor\n";
    subject = "";
    grade = 0;
}

Student::Student(std::string n, int a, std::string sub, int g) {
    std::cout << "Call student constructor with arguments\n";
    name = n;
    age = a;
    subject = sub;
    grade = g;
}

void Student::checkGrade() {
    if (grade < 3)
        std::cout << "The grade is unsatisfactory." << std::endl;
    else
        std::cout << "The grade is satisfactory." << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Student& s) {
    out << "Name: " << s.name << ", Age: " << s.age << ", Subject: " << s.subject << ", Grade: " << s.grade;
    return out;
}