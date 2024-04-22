#include <iostream>
#include <string>
#include "List.h"
using namespace std;

int main() {
	system("chcp 1251 > NULL");
	cout << "Введите длину списка:\n";
	int lenght;
	cin >> lenght;
	List listA(lenght);
	cout << "Введите значения элементов:\n";
	cin >> listA;
	cout << "Список A:\n";
	cout << listA << '\n';
	cout << "Введите значение, для добавления в конец списка а: ";
	int value;
	cin >> value;
	listA << value;
	cout << "Список A:\n";
	cout << listA << '\n';
	cout << "Введите индекс элемента, который ходите заменить: ";
	int number;
	cin >> number;
	cout << "Введите новое значение: ";
	cin >> value;
	listA[number] = value;
	cout << "Список a:\n";
	cout << listA << '\n';
	List listB(8);
	for (int i = 0; i < 8; i++)
		listB[i] = rand() % 15;
	cout << "Список b:\n";
	cout << listB << '\n';
	listA = listB;
	cout << "Список a = b:\n";
	cout << listA << '\n';
	cout << "1-ый элемент списка a:\n" << (*(listA.first()))->key << '\n';
	cout << "Вывод списка b с помощью итератора:\n";
	for (Iterator i = listB.first(); *i != NULL; ++i) {
		cout << (*i)->key << ' ';
	}
	cout << '\n';
	cout << "Cтавим итератор на первый элемент списка b\n";
	Iterator i = listB.first();
	cout << "Текущий элемент: " << (*i)->key << '\n';
	cout << "Смещаемся на 2 элемента вперед от текущего\n";
	i + 2;
	cout << "Текущий элемент: " << (*i)->key << '\n';
	cout << "a[0] * b[10] = " << listA[0] * listB[10] << '\n';
	return 0;
}