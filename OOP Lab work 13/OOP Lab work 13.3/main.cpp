#include <iostream>
#include <algorithm>
#include <numeric>
#include <list>
#include <map>
using namespace std;

void PushArithmeticMiddle(map <int, int>& myMap);
void EraseIfInRange(map <int, int>& myMap, const int BeginValue, const int EndValue);
void PlusMinAndMax(map <int, int>& myMap);
void ShowMap(const map <int, int>& myMap);

int main() {
	system("chcp 1251 > NULL");
	map <int, int> myMap;
	myMap = { {7, 4}, {2, 3}, {-6, 1}, {8, 1} };
	cout << "Содержимое словаря:\n";
	ShowMap(myMap);
	cout << "Добавляем среднее арифмитическое словаря а в конец контейнера\n";
	PushArithmeticMiddle(myMap);
	cout << "Содержимое словаря:\n";
	ShowMap(myMap);
	cout << "Удаляем из словаря а элементы, значения которых входят в диапазон от 2 до 3\n";
	EraseIfInRange(myMap, 2, 3);
	cout << "Содержимое словаря:\n";
	ShowMap(myMap);
	cout << "К каждому элементу добавляем сумму минимального и максимального элементов\n";
	PlusMinAndMax(myMap);
	cout << "Содержимое словаря:\n";
	ShowMap(myMap);
	return 0;
}

void PushArithmeticMiddle(map <int, int>& myMap) {
	if (!myMap.size()) {
		cout << "Словарь пуст!\n";
		return;
	}
	int MaxKey = max_element(myMap.begin(), myMap.end(), [](const auto& p1, const auto& p2) {
		return p1.first < p2.first;
		})->first + 1;
	int MiddleSecond = accumulate(myMap.begin(), myMap.end(), 0, [](int value, const auto& p) {
		return value + p.second;
		}) / myMap.size();
		myMap[MaxKey] = MiddleSecond;
		myMap.insert({ MaxKey, MiddleSecond });
}

void EraseIfInRange(map <int, int>& myMap, const int BeginValue, const int EndValue) {
	for (auto p = myMap.begin(); p != myMap.end();) {
		if (BeginValue <= (*p).second && (*p).second <= EndValue) {
			p = myMap.erase(p);
		} else {
			p++;
		}
	};
}

void PlusMinAndMax(map <int, int>& myMap) {
	if (myMap.size()) {
		int MaxValue = max_element(myMap.begin(), myMap.end(), [](const auto& p1, const auto& p2) {
			return p1.second < p2.second;
			})->second;
		int MinValue = min_element(myMap.begin(), myMap.end(), [](const auto& p1, const auto& p2) {
			return p1.second < p2.second;
			})->second;
		for (auto& p : myMap) {
			p.second += MaxValue + MinValue;
		}
	}
}

void ShowMap(const map <int, int>& myMap) {
	if (!myMap.size()) {
		cout << "Словарь пуст!\n";
		return;
	}
	for (auto& p : myMap) {
		cout << p.first << " : " << p.second << '\n';
	}
}