#pragma once

#include <string>

using namespace std;

class RationalNumber {
private:
	int numerator, denominator;

	int gcd(int a, int b) const;
	void simplify();

public:

	RationalNumber();
	RationalNumber(int numerator, int denominator);
	RationalNumber(const RationalNumber& src);
	~RationalNumber();

	double getNumerator() const;
	double getDenominator() const;
	void setNumerator(double numerator);
	void setDenominator(double denominator);

	bool equals(RationalNumber& rhs) const; //Had to remove const from method signature

	string toString(); //Had to remove const from method

	RationalNumber add(const RationalNumber& rhs) const;
	RationalNumber sub(const RationalNumber& rhs) const;
	RationalNumber mult(const RationalNumber& rhs) const;
	RationalNumber div(const RationalNumber& rhs) const;

};
