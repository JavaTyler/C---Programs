#include "RationalNumber.h"
#include <cmath>

RationalNumber::RationalNumber()
	:numerator(0)
	, denominator(1)
{

}

RationalNumber::RationalNumber(int numerator, int denominator)
	:numerator(numerator)
{
	if (denominator == 0) {
		throw "Invalid input, denominator cannot be 0";
	}
	else {
		this->denominator = denominator;
	}
	simplify();
}

RationalNumber::RationalNumber(const RationalNumber& src)
	:numerator(src.numerator)
	, denominator(src.denominator)
{

}

RationalNumber::~RationalNumber()
{

}

double RationalNumber::getNumerator() const
{
	return numerator;
}
double RationalNumber::getDenominator() const
{
	return denominator;
}
void RationalNumber::setNumerator(double numerator)
{
	this->numerator = numerator;
}
void RationalNumber::setDenominator(double denominator)
{
	if (denominator == 0) {
		throw "Arithmetic Exception: Denominator != 0";
	}
	this->denominator = denominator;
}

//Private methods (GCD + thisRationalNumberNegAdjust)
int RationalNumber::gcd(int a, int b) const
{
	if (b == 0) return a;
	return gcd(b, a % b);
}
// Found @: https://stackoverflow.com/questions/4009198/java-get-greatest-common-divisor

void RationalNumber::simplify()
{
	int divisor = gcd(this->numerator, this->denominator);
	this->numerator = this->numerator / divisor;
	this->denominator = this->denominator / divisor;

	if (this->denominator < 0) {
		this->denominator = this->denominator * -1;
		this->numerator = this->numerator * -1;
	}
}

/*void RationalNumber::thisRationalNumberNegAdjust()
{
	if (this->denominator != abs(this->denominator)) {
		this->denominator = this->denominator * -1;
		this->numerator = this->numerator * -1;
	}
}*/

bool RationalNumber::equals(RationalNumber& rhs) const { //Why does it not let me have const RationalNumber& rhs
	int gcd = this->gcd(this->numerator, this->denominator);
	int gcdrhs = rhs.gcd(this->numerator, this->denominator);

	int tempThisN = this->numerator;
	int tempThisD = this->denominator;
	int tempRhsN = rhs.numerator;
	int tempRhsD = rhs.denominator;
	if (this->denominator < 0) {
		tempThisD = this->denominator * -1;
		tempThisN = this->numerator * -1;
	}
	if (rhs.denominator < 0) {
		tempRhsD = rhs.denominator * -1;
		tempRhsN = rhs.numerator * -1;
	}
	if (tempRhsN / gcdrhs == tempThisN / gcd && tempRhsD / gcdrhs == tempThisD / gcd) {
		return true;
	}
	else {
		return false;
	}

}

string RationalNumber::toString() { //Also had to remove const here

	simplify();

	int tempThisN = this->numerator;
	int tempThisD = this->denominator;
	int remainder, wholeNum;

	if (tempThisD < 0) {
		tempThisD = this->denominator * -1;
		tempThisN = this->numerator * -1;
	}
	//Zero check first or else it will be caught by the wrong check due to how their rules are logically defined.
	if (tempThisN == 0) {
		return "0";
	}
	//Denominator will not be negative, do not need to worry about negative denominator cases
	//Smaller numerator, numerator is positive, denominator is positive
	else if (tempThisN < tempThisD && tempThisN == abs(tempThisN) && tempThisD == abs(tempThisD)) {
		return to_string(tempThisN) + "/" + to_string(tempThisD);
	}
	//Smaller numerator, negative numerator
	else if (tempThisN < tempThisD && tempThisN != abs(tempThisN) && abs(tempThisN) < tempThisD) {
		return to_string(tempThisN) + "/" + to_string(tempThisD);
	}
	//Larger numerator; Negatives are handled for this scenario already...
	else if (abs(tempThisN) > tempThisD) {
		remainder = tempThisN % tempThisD; //Remainder
		wholeNum = (int)(tempThisN / tempThisD); //Relying on truncation
		if (remainder == 0) {
			return to_string(wholeNum);
		}
		return to_string(wholeNum) + " " + to_string(abs(remainder)) + "/" + to_string(tempThisD);
	}
	else {
		return "Logic error warning, you should never see this message.";
	}
} //end of toString()

RationalNumber RationalNumber::add(const RationalNumber& rhs) const
{
	RationalNumber temp = RationalNumber(this->numerator, this->denominator);
	RationalNumber temp2 = RationalNumber(rhs.numerator, rhs.denominator);
	RationalNumber temp3 = RationalNumber();
	if (rhs.denominator == this->denominator) {
		temp3.numerator = temp.numerator + temp2.numerator;
		return temp3;
	}
	else {
		temp.numerator = this->numerator * rhs.denominator;
		temp.denominator = this->denominator * rhs.denominator;
		temp2.numerator = rhs.numerator * this->denominator;
		temp2.denominator = rhs.denominator * this->denominator;
		temp3.numerator = temp.numerator + temp2.numerator;
		temp3.denominator = temp.denominator;
		return temp3;
	}

}
RationalNumber RationalNumber::sub(const RationalNumber& rhs) const
{
	RationalNumber temp = RationalNumber(this->numerator, this->denominator);
	RationalNumber temp2 = RationalNumber(rhs.numerator, rhs.denominator);
	RationalNumber temp3 = RationalNumber();
	if (rhs.denominator == this->denominator) {
		temp3.numerator = temp.numerator - temp2.numerator;
		temp3.denominator = this->denominator;
		return temp3;
	}
	else {
		temp.numerator = this->numerator * rhs.denominator;
		temp.denominator = this->denominator * rhs.denominator;
		temp2.numerator = rhs.numerator * this->denominator;
		temp2.denominator = rhs.denominator * this->denominator;
		temp3.numerator = temp.numerator - temp2.numerator;
		temp3.denominator = temp.denominator;
		return temp3;
	}
}
RationalNumber RationalNumber::mult(const RationalNumber& rhs) const
{
	RationalNumber temp = RationalNumber(this->numerator, this->denominator);
	RationalNumber temp2 = RationalNumber(rhs.numerator, rhs.denominator);
	RationalNumber temp3 = RationalNumber();
	temp3.numerator = temp.numerator * temp2.numerator;
	temp3.denominator = temp.denominator * temp2.denominator;
	return temp3;
}
RationalNumber RationalNumber::div(const RationalNumber& rhs) const
{
	RationalNumber temp = RationalNumber(this->numerator, this->denominator);
	RationalNumber temp2 = RationalNumber(rhs.numerator, rhs.denominator);
	RationalNumber temp3 = RationalNumber();
	RationalNumber temp4 = RationalNumber();
	//Could've done reciprocal initially but decided to do separately for simplification
	//Technically do not need to do this, can simply do the math in a specific form but this shows more detail
	if (temp2.numerator != abs(temp2.numerator)) {
		temp3.numerator = temp2.denominator * -1;
		temp3.denominator = temp2.numerator * -1;
	}
	else {
		temp3.numerator = temp2.denominator;
		temp3.denominator = temp2.numerator;

		RationalNumber temp = RationalNumber(this->numerator, this->denominator);
		RationalNumber temp2 = RationalNumber(rhs.numerator, rhs.denominator);
		RationalNumber temp3 = RationalNumber();
		RationalNumber temp4 = RationalNumber();
	}
	temp4.numerator = temp.numerator * temp3.numerator;
	temp4.denominator = temp.denominator * temp3.denominator;
	return temp4;
}

