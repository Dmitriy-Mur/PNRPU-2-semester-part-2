#pragma once
#include <iostream>
#include <set>
using namespace std;

template <typename T>
class List {
private:
	multiset<T> multiSet;
	int Size = 0;
public:
	List() {};
	~List() {};
	void MakeMultiset(int size);
	void ShowMultiset();
	void PushArithmeticMiddle();
	void EraseIfInRange(const double BeginValue, const double EndValue);
	int GetSize();
	void PlusMinAndMax();
};

template <typename T>
void List<T>::MakeMultiset(int size) {
	for (size_t i = 0; i < size; i++) {
		multiSet.insert(rand() % 100);
	}
	Size = size;
}

template <typename T>
void List<T>::ShowMultiset() {
	if (!multiSet.size()) {
		cout << "Множество пусто!\n";
		return;
	}
	for (auto i = multiSet.begin(); i != multiSet.end(); i++) {
		cout << *i << ' ';
	}
	cout << '\n';
}

template <typename T>
void List<T>::PushArithmeticMiddle() {
	if (!multiSet.size()) {
		cout << "Множество пусто!\n";
		return;
	}
	T Sum = 0;
	for (auto i = multiSet.begin(); i != multiSet.end(); i++) {
		Sum += *i;
	}
}

template <typename T>
void List<T>::EraseIfInRange(const double BeginValue, const double EndValue) {
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

template <typename T>
int List<T>::GetSize() {
	return Size;
}

template <typename T>
void List<T>::PlusMinAndMax() {
	if (multiSet.size() > 0) {
		multiset<T> tmp_multiset = multiSet;
		T MaxValue, MinValue;
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
			T NewValue = *i + MaxValue + MinValue;
			multiSet.insert(NewValue);
		}
		tmp_multiset = {};
	}
}
