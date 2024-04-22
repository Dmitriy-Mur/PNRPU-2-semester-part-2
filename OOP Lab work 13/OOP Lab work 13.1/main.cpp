#include <iostream>
#include <algorithm>
#include <numeric>
#include <list>
#include "Pair.h"
using namespace std;

void PushArithmeticMiddle(list<Pair>& myList);
void EraseIfInRange(list<Pair>& myList, const double BeginValue, const double EndValue);
void PlusMinAndMax(list<Pair>& myList);
void ShowList(const list<Pair>& myList);

int main() {
	system("chcp 1251 > NULL");
	list<Pair> myList;
	Pair arr[] = { Pair(7, 8.2), Pair(2, 0.3), Pair(-6, 1.5), Pair(8, 6.1) };
	for (Pair pair : arr) {
		myList.push_back(pair);
	}
	cout << "Содержимое списка:\n";
	ShowList(myList);
	cout << "Добавляем среднее арифмитическое списка в конец контейнера\n";
	PushArithmeticMiddle(myList);
	cout << "Содержимое списка:\n";
	ShowList(myList);
	cout << "Удаляем из списка а элементы, значения которых входят в диапазон от 2 до 3\n";
	EraseIfInRange(myList, 2, 3);
	cout << "Содержимое списка:\n";
	ShowList(myList);
	cout << "К каждому элементу добавляем сумму минимального и максимального элементов\n";
	PlusMinAndMax(myList);
	cout << "Содержимое списка:\n";
	ShowList(myList);
	return 0;
}

void PushArithmeticMiddle(list<Pair>& myList) {
	if (!myList.size()) {
		cout << "Список пуст!\n";
		return;
	}
	Pair Middle = accumulate(myList.begin(), myList.end(), Pair(0, 0));
	Middle.SetFirst(Middle.GetFirst() / myList.size());
	Middle.SetSecond(Middle.GetSecond() / myList.size());
	myList.push_back(Middle);
}

void EraseIfInRange(list<Pair>& myList, const double BeginValue, const double EndValue) {
	auto i = remove_if(myList.begin(), myList.end(), [BeginValue, EndValue](Pair p) {
		return ((BeginValue <= p.GetFirst() && p.GetFirst() <= EndValue) || (BeginValue <= p.GetSecond() && p.GetSecond() <= EndValue));
		});
	myList.erase(i, myList.end());
}

void PlusMinAndMax(list<Pair>& myList) {
	if (myList.size()) {
		Pair max = *max_element(myList.begin(), myList.end());
		Pair min = *min_element(myList.begin(), myList.end());
		for (Pair& c : myList) {
			c + max + min;
		}
	}
}

void ShowList(const list<Pair>& myList) {
	if (!myList.size()) {
		cout << "Список пуст!\n";
		return;
	}
	for_each(myList.begin(), myList.end(), [](Pair p) {
		cout << p << '\n';
	});
}