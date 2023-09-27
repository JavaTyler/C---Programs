#pragma once

#include "RationalNumber.h"
#include <string>

class MixedNumber : public RationalNumber {
public:
	MixedNumber();
	MixedNumber(int whole, int numerator, int denominator);
	MixedNumber(const MixedNumber& src);
	~MixedNumber();

	bool equals(MixedNumber& rhs) const;

	int sign();

	std::string toString();

private:
	int whole;
};


