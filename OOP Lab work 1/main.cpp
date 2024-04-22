#include <iostream>
#include "MyClass.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	MyClass myClass;
	cout << "myClass.Init(4.56, 3):\n";
	myClass.Init(4.56, 3);
	myClass.Show();
	cout << "myClass.myClass.Read():\n";
	myClass.Read();
	myClass.Show();
	cout << "make_MyClass(4.1, 5):\n";
	myClass = make_MyClass(4.1, 5);
	myClass.Show();
	cout << "Введите номер элемента: ";
	int j;
	cin >> j;
	cout << "Элемент " << j << " = " << myClass.element(j) << '\n';
	MyClass* arr = new MyClass[5];
	cout << "arr[0] = myClass:\n";
	arr[0] = myClass;
	arr[0].Show();
	cout << "arr[1].Init(6.7, 4):\n";
	arr[1].Init(6.7, 4);
	arr[1].Show();

	return 0;
}