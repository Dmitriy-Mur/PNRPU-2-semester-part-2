#include <iostream>
#include "Object.h"
#include "Person.h"
#include "Student.h"
#include "Vector.h"
using namespace std;

int main() {
	system("chcp 1251 > NULL");
	Vector v(5);
	Person p;
	cout << "Инициализируем экземпляр класса Person:\n";
	cin >> p;
	Student s;
	cout << "Инициализируем экземпляр класса Student:\n";
	cin >> s;
	cout << "Проверяем оценки...\n";
	s.BadMark();
	Object* o = &p;
	v.Add(o);
	o = &s;
	v.Add(o);
	cout << "Содержимое списка:\n";
	cout << v;
	return 0;
}