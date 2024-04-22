#include <iostream>
#include "Magazin.h"
#include "Vector.h"
#include "Dialog.h"
using namespace std;

int main() {
	system("chcp 1251 > NULL");
	cout << "m: Создать группу\n" <<
			"+: Добавить элемент в группу\n" <<
			"-: Удалить элемент из группы\n" <<
			"s: Информация об элементах группы\n" <<
			"z: Вывести информацию о элементах группы\n" <<
			"q: Конец работы\n";
	Dialog D;
	D.Execute();
	return 0;
}