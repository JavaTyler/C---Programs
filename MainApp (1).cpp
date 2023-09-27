#include <iostream>

#include "RationalNumber.h"
#include "RationalNumber.cpp"

using namespace std;

int main(int argc, char** argv)
{
	RationalNumber case1;
	cout << "Default Constructor: numerator: " << case1.getNumerator() << " denominator: " << case1.getDenominator() << endl; //<<endl adding more simply moves on to the next line, creating gaps
	RationalNumber case2(3, 5);
	cout <<"Overload constructor: " << case2.toString() << endl;
	RationalNumber case3(2, -7);
	cout <<"Negative sign flip to numerator: " << case3.toString() << endl;
	RationalNumber case4(0, -1);
	cout << "Numerator 0 causes a return of 0 alone: " << case4.toString() << endl;
	/*RationalNumber case5 = new RationalNumber(105, 0);
	Denominator of 0 causes a return of ArithmeticException*/
	RationalNumber case6(-5016, -18);
	cout <<"Goes from improprer fraction to mixed, rational number reduces, double negative logic handled: " << case6.toString() << endl;
	RationalNumber case7(-7, 3);
	cout <<"Negative mixed number: " << case7.toString() << endl;
	RationalNumber wholeOnly(30, 15);
	cout <<"Rational number (30/15) gets reduced to whole number: " << wholeOnly.toString() << endl;
	//Getters + Setters
	RationalNumber case8(7, 10);
	cout << "Getters and Setters, starting case: " << case8.toString() << endl;
	case8.setNumerator(12);
	case8.setDenominator(13);
	cout << "New numerator + denominator: " << case8.toString() << endl;
	//Arithmetic
	RationalNumber arithmeticCase1(4, 5);
	RationalNumber arithmeticCase2(-3, 12);
	cout << "Addition: " << arithmeticCase1.add(arithmeticCase2).toString() << endl;
	cout << "Subtraction: " << arithmeticCase1.sub(arithmeticCase2).toString() << endl;
	cout << "Multiplication: " << arithmeticCase1.mult(arithmeticCase2).toString() << endl;
	cout << "Division: " << arithmeticCase1.div(arithmeticCase2).toString() << endl;
	//Equivalence
	RationalNumber case9 (1, 2);
	RationalNumber case10(5, 10);
	cout << "Equivalence testing, should return true: " << case9.equals(case10) << endl;
	case10.setDenominator(40);
	cout << "Equivalence testing, should return false: " << case9.equals(case10) << endl;
}