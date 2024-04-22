#include <iostream>
#include "List.h"
#include "Pair.h"
using namespace std;

int main() {
    List <int> list;
    int a = 23;
    cout << "int a:\n";
    cout << a << '\n';
    list << a;
    int b = 62;
    cout << "int b:\n";
    cout << b << '\n';
    list << b;
    int c = -31;
    cout << "int c:\n";
    cout << c << '\n';
    list << c;
    cout << "List<Pair>:\n";
    cout << list;
    List <Pair> pairList;
    Pair pair;
    pair.SetFirst(4);
    pair.SetSecond(1.8);
    cout << "Pair a:\n";
    cout << pair << '\n';
    pairList << pair;
    pair.SetFirst(6);
    pair.SetSecond(5.3);
    cout << "Pair a:\n";
    cout << pair << '\n';
    pairList << pair;
    cout << "List<Pair>:\n";
    cout << pairList << '\n';
    return 0;
}