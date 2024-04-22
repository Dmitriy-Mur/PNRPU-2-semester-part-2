#include <iostream>
#include "List.h"
#include "Error.h"
using namespace std;


int main() {
    system("chcp 1251 > NULL");
    try {
        List a(2);
        a[0] = 3;
        a[1] = 8;
        List b;
        cout << a << '\n';
        cout << b << '\n';
        cout << b[0];           //Ошибка
        Iterator i = b.first(); //Ошибка
        Iterator j = b.last();  //Ошибка
        Iterator k = a.last();
        ++k;
    }
    catch (Error& m_Error) {
        m_Error.What();
    }
    return 0;
}