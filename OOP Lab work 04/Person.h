#pragma once
#include <iostream>

class Person {
protected:
    std::string name;
    int age;
public:
    Person();
    Person(std::string n, int a);
    Person(const Person& p) : name(p.name), age(p.age) {}
    virtual ~Person() {}
    std::string getName() const { return name; }
    int getAge() const { return age; }
    void setName(std::string n) { name = n; }
    void setAge(int a) { age = a; }
    Person& operator=(const Person& p);
    friend std::ostream& operator<<(std::ostream& out, const Person& p);
    friend std::istream& operator>>(std::istream& in, Person& p);
};
