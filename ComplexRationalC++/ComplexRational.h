#pragma once

#include <string>
#include "RationalNumber.h"


using namespace std;

class ComplexRational {
private:
	RationalNumber r, i;
	int ScaleFactor = 10000;

	RationalNumber setReal(const double d) const 
	{
		return RationalNumber((int)(d * (double)ScaleFactor), ScaleFactor);
	}

	double convertDouble(const RationalNumber& rhs) const
	{
		double convertResult = ((double)rhs.getNumerator() / (double)rhs.getDenominator());
		return convertResult;
	}

public:
	ComplexRational();
	ComplexRational(double _r, double _i);
	ComplexRational(const ComplexRational& rhs);
	~ComplexRational();

	ComplexRational add(const ComplexRational& rhs) const; //first const says ex2 no change, second ex1 no change. ex1.add(ex2);
	ComplexRational sub(const ComplexRational& rhs) const; // & is google it, probably reference
	ComplexRational mult(const ComplexRational& rhs) const;
	ComplexRational div(const ComplexRational& rhs) const;
	 
	ComplexRational conj() const;
	ComplexRational sqroot() const;

	double mag() const;

	bool equals(const ComplexRational& rhs) const;
	void setR(double r);
	void setI(double i);
	double getR() const;
	double getI() const;

	string toString() const;
};