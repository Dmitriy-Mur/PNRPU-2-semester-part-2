#include <iostream>
#include <string>
#include "Person.h"
#include "Student.h"

int main() {
    Person p1("Alice", 30);
    Person p2;

    std::cin >> p2;
    std::cout << "Person 1: " << p1 << std::endl;
    std::cout << "Person 2: " << p2 << std::endl;

    Student s1("Bob", 25, "Math", 3);
    std::cout << "Student: " << s1 << std::endl;
    s1.checkGrade();

    Person& ref = s1;
    std::cout << "Using base class reference: " << ref << std::endl;
    return 0;
}