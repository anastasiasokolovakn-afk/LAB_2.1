#include "Product.h"
#include <iostream>
#include <string> 
#include <sstream>

using namespace std;

Product::Product() {
	first = 0;
	second = 0.0;
}
Product::Product(int f, double s) {
    if (f > 0) {
        first = f;
    }
    else {
        first = 1;
    }

    if (s > 0.0) {
        second = s;
    }
    else {
        second = 1.0;
    }
}
Product::Product(const Product& other) {
    first = other.first;
    second = other.second;
}

int Product::GetFirst() const {
    return first;
}
double Product::GetSecond() const {
    return second;
}
bool Product::SetFirst(int value) {
    if (value > 0) {
        first = value;
        return true;
    }
    else {
        return false;
    }
}
bool Product::SetSecond(double value) {
    if (value > 0) {
        second = value;
        return true;
    }
    else {
        return false;
    }
}
double Product::power() const {
    double result = first * second * 10;
    return result;
}
Product& Product::operator=(const Product& other) {
    if (this != &other) {
        first = other.first;
        second = other.second;
    }
    return *this;
}

Product::operator string() const {
    stringstream ss;
    ss << "Калорійність(на 100 г) : " << first << " ккал" << endl
        << "Маса продукту : " << second << " кг" << endl
        << "Загальна калорійність : " << power() << " ккал" << endl;
    return ss.str();
}

Product& Product::operator++() {
    first++;
    return *this;
}
Product& Product::operator--() {
    if (first > 1) {
        first--;
    }
    return *this;
}

Product Product::operator++(int) {
    Product temp(*this);
    second += 0.1;
    return temp;
}
Product Product::operator--(int) {
    Product temp(*this);
    if (second > 0.1) {
        second -= 0.1;
    }
    return temp;
}

ostream& operator<<(ostream& out, const Product& p) {
    out << string(p);
    return out;
}
istream& operator>>(istream& in, Product& p) {
    int f;
    double s;
    do {
        cout << "Введіть калорійність (first > 0): ";
        in >> f;
        cout << "Введіть вагу в кг (second > 0): ";
        in >> s;
    } while (!p.SetFirst(f) || !p.SetSecond(s));
    return in;
}