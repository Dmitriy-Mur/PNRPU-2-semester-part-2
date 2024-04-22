#include <iostream>
#include <set>
using namespace std;

void FillMultiset(multiset<double>&, int);
void PushArithmeticMiddle(multiset<double>& multiSet);
void EraseIfInRange(multiset<double>& multiSet, const double BeginValue, const double EndValue);
void PlusMinAndMax(multiset<double>& multiSet);
void ShowMultiset(const multiset<double>& multiSet);

int main() {
	srand(time(0));
	system("chcp 1251 > NULL");
	multiset<double> multiSet;
	int size;
	cout << "Введите размер множества:";
	cin >> size;
	FillMultiset(multiSet, size);
	cout << "Содержимое множества:\n";
	ShowMultiset(multiSet);
	cout << "Добавляем среднее арифмитическое множестава а в контейнер\n";
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

void FillMultiset(multiset<double>& multiSet, int size) {
	for (int i = 0; i < size; i++) {
		multiSet.insert(rand() % 1000 * 0.1);
	}
}

void PushArithmeticMiddle(multiset<double>& multiSet) {
	if (!multiSet.size()) {
		cout << "Множество пусто!\n";
	}
	double Sum = 0;
	for (auto i = multiSet.begin(); i != multiSet.end(); i++) {
		Sum += *i;
	}
	multiSet.insert(Sum / multiSet.size());
}

void EraseIfInRange(multiset<double>& multiSet, const double BeginValue, const double EndValue) {
	auto i = multiSet.begin();
	while (i != multiSet.end()) {
		if (*i >= BeginValue && *i <= EndValue) {
			i = multiSet.erase(i);
		}
		else {
			i++;
		}
	}
}

void PlusMinAndMax(multiset<double>& multiSet) {
	if (multiSet.size()) {
		multiset<double> tmp_multiset = multiSet;
		double MaxValue, MinValue;
		MaxValue = MinValue = *multiSet.begin();
		for (auto i = multiSet.begin(); i != multiSet.end(); i++) {
			if (*i > MaxValue) {
				MaxValue = *i;
			}
			else if (*i < MinValue) {
				MinValue = *i;
			}
		}
		multiSet = {};
		for (auto i = tmp_multiset.begin(); i != tmp_multiset.end(); i++) {
			double NewValue = *i + MaxValue + MinValue;
			multiSet.insert(NewValue);
		}
		tmp_multiset = {};
	}
}

void ShowMultiset(const multiset<double>& multiSet) {
	if (!multiSet.size()) {
		cout << "Множество пусто!\n";
	}
	for (auto i = multiSet.begin(); i != multiSet.end(); i++) {
		cout << *i << " ; ";
	}
	cout << '\n';
}
