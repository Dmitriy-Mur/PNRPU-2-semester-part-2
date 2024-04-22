#include <iostream>
#include "Pair.h"

Pair& Pair::operator=(const Pair& other) {
    if (this != &other) {
        this->first = other.first;
        this->second = other.second;
    }
    return *this;
}

Pair Pair::operator+(const Pair& other) {
    Pair result;
    result.first = this->first + other.first;
    result.second = this->second + other.second;
    return result;
}

Pair Pair::operator-(const Pair& other) {
    Pair result;
    result.first = this->first - other.first;
    result.second = this->second - other.second;
    return result;
}

Pair Pair::operator++() {
    ++this->first;
    ++this->second;
    return *this;
}

Pair Pair::operator--() {
    --this->first;
    --this->second;
    return *this;
}

Pair Pair::operator++(int) {
    Pair temp = *this;
    this->first++;
    this->second++;
    return temp;
}

Pair Pair::operator--(int) {
    Pair temp = *this;
    this->first--;
    this->second--;
    return temp;
}

double Pair::operator[](const char x) {
    if (x == 'f') {
        return first;
    }
    if (x == 's') {
        return second;
    }
    else {
        return NULL;
    }
}

std::istream& operator>>(std::istream& in, Pair& pair) {
    in >> pair.first >> pair.second;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Pair& pair) {
    out << "(" << pair.first << ", " << pair.second << ")";
    return out;
}