#include <iostream>
#include "Pair.h"

int main() {
    Pair p1(3, 4.2);
    Pair p2(1, 2.5);
    std::cout << "p1: " << p1 << std::endl;
    std::cout << "p2: " << p2 << std::endl;
    std::cout << "p1 + p2: " << p1 + p2 << std::endl;
    std::cout << "p1 - p2: " << p1 - p2 << std::endl;
    std::cout << std::endl;
    Pair p3(5, 6.1);
    std::cout << "p3: " << p3 << std::endl;
    std::cout << "++p3: " << ++p3 << std::endl;
    std::cout << "p3++: " << p3++ << std::endl;
    std::cout << "p3: " << p3 << std::endl;
    std::cout << "--p3: " << --p3 << std::endl;
    std::cout << "p3--: " << p3-- << std::endl;
    std::cout << "p3: " << p3 << std::endl;
    std::cout << std::endl;
    Pair p4(2, 1.3);
    std::cout << "p4: " << p4 << std::endl;
    std::cout << "p4['f']: " << p4['f'] << std::endl;
    std::cout << "p4['s']: " << p4['s'] << std::endl;
    std::cout << std::endl;
    Pair input;
    std::cout << "Enter pair (int, double): ";
    std::cin >> input;
    std::cout << "You entered: " << input << std::endl;
    return 0;
}