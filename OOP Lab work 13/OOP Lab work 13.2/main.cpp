#include "Pair.h"
#include <iostream>
#include <list>
#include <queue>
#include <numeric>
#include <algorithm>
using namespace std;

list<Pair> PriorityQueueToList(priority_queue<Pair>& myQueue);
void PushArithmeticMiddle(priority_queue<Pair>& myQueue);
void EraseIfInRange(priority_queue<Pair>& myQueue, const double BeginValue, const double EndValue);
void PlusMinAndMax(priority_queue<Pair>& myQueue);
void ShowPriorityQueue(priority_queue<Pair>& myQueue);

int main() {
	system("chcp 1251 > NULL");
	priority_queue <Pair> myQueue;
	Pair arr[] = { Pair(7, 8.2), Pair(2, 0.3), Pair(-6, 1.5), Pair(8, 6.1) };
	for (Pair pair : arr) {
		myQueue.push(pair);
	}
	cout << "Содержимое очереди:\n";
	ShowPriorityQueue(myQueue);
	cout << "Добавляем среднее арифмитическое очереди в контейнер\n";
	PushArithmeticMiddle(myQueue);
	cout << "Содержимое очереди:\n";
	ShowPriorityQueue(myQueue);
	cout << "Удаляем из очереди а элементы, значения которых входят в диапазон от 2 до 3\n";
	EraseIfInRange(myQueue, 2, 3);
	cout << "Содержимое очереди:\n";
	ShowPriorityQueue(myQueue);
	cout << "К каждому элементу добавляем сумму минимального и максимального элементов\n";
	PlusMinAndMax(myQueue);
	cout << "Содержимое очереди:\n";
	ShowPriorityQueue(myQueue);
	return 0;
}

list<Pair> PriorityQueueToList(priority_queue<Pair>& myQueue) {
	priority_queue <Pair> tmp_priority_queue = myQueue;
	list <Pair> m_list;
	while (tmp_priority_queue.size() > 0) {
		m_list.push_back(tmp_priority_queue.top());
		tmp_priority_queue.pop();
	}
	return m_list;
}

void PushArithmeticMiddle(priority_queue<Pair>& myQueue) {
	if (!myQueue.size()) {
		cout << "Очередь пуста!\n";
		return;
	}
	list <Pair> m_list = PriorityQueueToList(myQueue);
	Pair Middle = accumulate(m_list.begin(), m_list.end(), Pair(0, 0));
	Middle.SetFirst(Middle.GetFirst() / m_list.size());
	Middle.SetSecond(Middle.GetSecond() / m_list.size());
	myQueue.push(Middle);
}

void EraseIfInRange(priority_queue<Pair>& myQueue, const double BeginValue, const double EndValue) {
	if (myQueue.size() > 0) {
		list <Pair> m_list = PriorityQueueToList(myQueue);
		auto i = remove_if(m_list.begin(), m_list.end(), [BeginValue, EndValue](Pair p) {
			return (BeginValue <= p.GetFirst() && p.GetFirst() <= EndValue) || (BeginValue <= p.GetSecond() && p.GetSecond() <= EndValue);
			});
		myQueue = {};
		if (i != m_list.begin()) {
			for_each(m_list.begin(), i--, [&myQueue](Pair p) {
				myQueue.push(p);
				});
		}
	}
}

void PlusMinAndMax(priority_queue<Pair>& myQueue) {
	if (myQueue.size() > 0) {
		list <Pair> m_list = PriorityQueueToList(myQueue);
		myQueue = {};
		Pair max = *max_element(m_list.begin(), m_list.end());
		Pair min = *min_element(m_list.begin(), m_list.end());
		for (Pair& c : m_list) {
			myQueue.push(c + max + min);
		}
	}
}

void ShowPriorityQueue(priority_queue<Pair>& myQueue) {
	if (!myQueue.size()) {
		cout << "Очередь пуста!\n";
		return;
	}
	list <Pair> m_list = PriorityQueueToList(myQueue);
	for_each(m_list.begin(), m_list.end(), [](Pair p) {
		cout << p << '\n';
	});
}