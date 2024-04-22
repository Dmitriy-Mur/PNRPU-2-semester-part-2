#include <iostream>
#include "List.h"
using namespace std;

int main() {
	system("chcp 1251 > NULL");
	List<double> list;
	cout << "Введите размер множества: ";
	int size;
	cin >> size;
	list.MakeMultiset(size);
	cout << "Содержимое множества:\n";
	list.ShowMultiset();
	cout << "Добавляем среднее арифмитическое множества в контейнер\n";
	list.PushArithmeticMiddle();
	cout << "Содержимое множества:\n";
	list.ShowMultiset();
	cout << "Удаляем из множества элементы, значения которых входят в диапазон от 2 до 3\n";
	list.EraseIfInRange(2, 3);
	cout << "Содержимое множества:\n";
	list.ShowMultiset();
	cout << "К каждому элементу добавляем сумму минимального и максимального элементов\n";
	list.PlusMinAndMax();
	cout << "Содержимое множества:\n";
	list.ShowMultiset();
	return 0;
}