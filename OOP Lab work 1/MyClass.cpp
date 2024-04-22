#include "MyClass.h"
#include <iostream>

void MyClass::Init(double F, unsigned int S) {
	first = F; second = S;
}

void MyClass::Read() {
	std::cout << "First: ";
	std::cin >> first;
	std::cout << "Second: ";
	std::cin >> second;
}

void MyClass::Show() {
	std::cout << "First: " << first << '\n';
	std::cout << "Second: " << second << '\n';
}

double MyClass::element(int j) {
	return first * std::pow(second, j);
}

MyClass make_MyClass(double F, unsigned int S) {
	MyClass t;
	t.Init(F, S);
	return t;
}

