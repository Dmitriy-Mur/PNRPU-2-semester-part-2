#pragma once

class Pair {
private:
    int first;
    double second;
public:
    Pair() : first(0), second(0.0) {}
    Pair(int f, double s) : first(f), second(s) {}
    Pair& operator=(const Pair& other);
    Pair operator+(const Pair& other);
    Pair operator-(const Pair& other);
    Pair operator++();
    Pair operator--();
    Pair operator++(int);
    Pair operator--(int);
    double operator[](const char x);
    friend std::istream& operator>>(std::istream& in, Pair& pair);
    friend std::ostream& operator<<(std::ostream& out, const Pair& pair);
};
