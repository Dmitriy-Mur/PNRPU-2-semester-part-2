#include <iostream>
#include "Person.h"

Person::Person() {
    std::cout << "Call base Person constructor\n";
    name = "";
    age = 0;
}
Person::Person(std::string n, int a) {
    std::cout << "Call Person constructor with arguments\n";
    name = n;
    age = a;
}

Person& Person::operator=(const Person& p) {
    name = p.name;
    age = p.age;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Person& p) {
    out << "Name: " << p.name << ", Age: " << p.age;
    return out;
}

std::istream& operator>>(std::istream& in, Person& p) {
    std::cout << "Enter name: ";
    in >> p.name;
    std::cout << "Enter age: ";
    in >> p.age;
    return in;
}