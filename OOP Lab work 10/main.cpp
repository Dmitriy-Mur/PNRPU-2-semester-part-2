#include <iostream>
#include "file_work.h"
#include <string>
#include <functional>
using namespace std;

int main() {
	system("chcp 1251 > NULL");
	int choose = 6;
	function<int()> f[5] = { make_file, print_file, del_file, change_file, add_file };
	do {
		if (choose != 6) {
			check_k(f[choose - 1]());
		}
		cout << "Введите номер команды :\n" <<
			"1. Создать файл\n" <<
			"2. Печать файла\n" <<
			"3. Удалить все записи меньше заданного значения\n" <<
			"4. Увеличить все записи с заданным значением на число L\n" <<
			"5. Добавить K записей перед элиментом с заданным номером\n" <<
			"6. Выход\n"; 
		cin >> choose;
		system("cls");
	} while (choose != 6);
	return 0;
}

