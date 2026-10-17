#pragma once
#include <iostream>
#include <string> 

using namespace std;
#pragma pack(push, 1)
class Product
{
private:
	int first = 0;
	double second = 0.0;
public:
	Product();                            
	Product(int f, double s);             
	Product(const Product& other);

	int GetFirst() const;
	double GetSecond() const;
	bool SetFirst(int value);
	bool SetSecond(double value);

	double power() const;

	Product& operator=(const Product& other);

	operator string() const;

	Product& operator++();
	Product& operator--();

	Product operator++(int);
	Product operator--(int);

	friend ostream& operator<<(ostream& out, const Product& p);
	friend istream& operator>>(istream& in, Product& p);
};
#pragma pack(pop)

