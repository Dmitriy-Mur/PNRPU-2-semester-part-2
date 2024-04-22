#include <iostream>
#include "Pair.h"
#include <set>
using namespace std;

void PushArithmeticMiddle(multiset<Pair>& multiSet);
void EraseIfInRange(multiset<Pair>& multiSet, const double BeginValue, const double EndValue);
void PlusMinAndMax(multiset<Pair>& multiSet);
void ShowMultiset(const multiset<Pair>& multiSet);

int main() {
	system("chcp 1251 > NULL");
	multiset<Pair> multiSet;
	Pair arr[] = { Pair(7, 8.2), Pair(2, 0.3), Pair(-6, 1.5), Pair(8, 6.1) };
	for (Pair pair : arr) {
		multiSet.insert(pair);
	}
	cout << "Содержимое множества:\n";
	ShowMultiset(multiSet);
	cout << "Добавляем среднее арифмитическое множества в контейнер\n";
	PushArithmeticMiddle(multiSet);
	cout << "Содержимое множества:\n";
	ShowMultiset(multiSet);
	cout << "Удаляем из множества а элементы, значения которых входят в диапазон от 2 до 3\n";
	EraseIfInRange(multiSet, 2, 3);
	cout << "Содержимое множества:\n";
	ShowMultiset(multiSet);
	cout << "К каждому элементу добавляем сумму минимального и максимального элементов\n";
	PlusMinAndMax(multiSet);
	cout << "Содержимое множества:\n";
	ShowMultiset(multiSet);
	return 0;
}

void PushArithmeticMiddle(multiset<Pair>& multiSet) {
	if (!multiSet.size()) {
		cout << "Множество пусто!\n";
	}
	int SumFirst = 0;
	double SumSecond = 0;
	for (auto i = multiSet.begin(); i != multiSet.end(); i++) {
		SumFirst += (*i).GetFirst();
		SumSecond += (*i).GetSecond();
	}
	multiSet.insert(Pair(SumFirst / multiSet.size(), SumSecond / multiSet.size()));
}

void EraseIfInRange(multiset<Pair>& multiSet, const double BeginValue, const double EndValue) {
	auto i = multiSet.begin();
	while (i != multiSet.end()) {
		if (((*i).GetFirst() >= BeginValue && (*i).GetFirst() <= EndValue) || ((*i).GetSecond() >= BeginValue && (*i).GetSecond() <= EndValue)) {
			i = multiSet.erase(i);
		}
		else {
			i++;
		}
	}
}

void PlusMinAndMax(multiset<Pair>& multiSet) {
	if (multiSet.size() > 0) {
		multiset<Pair> tmp_multiset;
		Pair MaxValue = *(multiSet.begin());
		Pair MinValue = *(multiSet.begin());

		for (auto i = multiSet.begin(); i != multiSet.end(); i++) {
			if (MaxValue < *i) {
				MaxValue = *i;
			}
			else if (*i < MinValue) {
				MinValue = *i;
			}
		}

		for (auto i = multiSet.begin(); i != multiSet.end(); i++) {
			Pair c = (*i);
			c + MaxValue + MinValue;
			tmp_multiset.insert(c);
		}
		multiSet = tmp_multiset;
	}
}

void ShowMultiset(const multiset<Pair>& multiSet) {
	if (!multiSet.size()) {
		cout << "Множество пусто!\n";
	}
	for (auto i = multiSet.begin(); i != multiSet.end(); i++) {
		cout << *i << '\n';
	}
}