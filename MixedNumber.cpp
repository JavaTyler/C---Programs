#include <iostream>
#include "RationalNumber.h"
#include "MixedNumber.h"



MixedNumber::MixedNumber() : RationalNumber()
{
	this->whole = 0;
}

MixedNumber::MixedNumber(int whole, int numerator, int denominator) : RationalNumber(numerator, denominator)
{
	this->whole = whole;
}

MixedNumber::MixedNumber(const MixedNumber& mixed_number) : RationalNumber((RationalNumber)mixed_number)
{
	whole = mixed_number.whole;
}

MixedNumber::~MixedNumber()
{

}

std::string MixedNumber::toString()
{
    RationalNumber pass(whole, 1);
    RationalNumber otherPass(this->numerator, this->denominator);
	return pass.add(otherPass).toString();
}

int MixedNumber::sign()
{
	return abs(whole) > 0 ? (whole >= 0 ? 1 : -1) : (this->getNumerator() >= 0 ? 1 : -1);
}

bool MixedNumber::equals(MixedNumber& rhs) const
{
	RationalNumber temp1(this->getNumerator() + this->getDenominator() * this->whole, this->getDenominator());
	RationalNumber temp2(rhs.getNumerator() + rhs.getDenominator() * rhs.whole, rhs.getDenominator());

	return temp1.equals(temp2);
}



//using namespace std;

int main() {

    //START OF USE OF BRYCE HUSSERL'S TEST METHOD:
    MixedNumber Def1;

    MixedNumber B1(1, 1, 1);
    MixedNumber B2(1, 1, -1);
    MixedNumber B3(1, -1, 1);
    MixedNumber B4(1, -1, -1);
    MixedNumber B5(-1, 1, 1);
    MixedNumber B6(-1, 1, -1);
    MixedNumber B7(-1, -1, 1);
    MixedNumber B8(-1, -1, -1);

    MixedNumber D1(1, 10, 1);
    MixedNumber D2(1, 10, -1);
    MixedNumber D3(1, -10, 1);
    MixedNumber D4(1, -10, -1);
    MixedNumber D5(-1, 10, 1);
    MixedNumber D6(-1, 10, -1);
    MixedNumber D7(-1, -10, 1);
    MixedNumber D8(-1, -10, -1);

    MixedNumber N1(1, 1, 10);
    MixedNumber N2(1, 1, -10);
    MixedNumber N3(1, -1, 10);
    MixedNumber N4(1, -1, -10);
    MixedNumber N5(-1, 1, 10);
    MixedNumber N6(-1, 1, -10);
    MixedNumber N7(-1, -1, 10);
    MixedNumber N8(-1, -1, -10);

    MixedNumber Z1(0, 1, 10);
    MixedNumber Z2(0, 1, -10);
    MixedNumber Z3(0, -1, 10);
    MixedNumber Z4(0, -1, -10);
    MixedNumber Z5(0, 1, 10);
    MixedNumber Z6(0, 1, -10);
    MixedNumber Z7(0, -1, 10);
    MixedNumber Z8(0, -1, -10);

    std::cout << "Default constructor = " << Def1.toString() << endl;

    std::cout << "\nB = (+-1) (+-1/+-1)\nD = (+-1) (+-10/+-1)\nN = (+-1) (+-1/+-10)\nZ = (+-0) (+-1/+-10)\n" << endl;
    std::cout << "B1 = " << B1.toString() << "\t\tD1 = " << D1.toString() << "\t\tN1 = " << N1.toString() << "\t\tZ1 = " << Z1.toString() << endl;
    std::cout << "B2 = " << B2.toString() << "\t\tD2 = " << D2.toString() << "\t\tN2 = " << N2.toString() << "\t\tZ2 = " << Z2.toString() << endl;
    std::cout << "B3 = " << B3.toString() << "\t\tD3 = " << D3.toString() << "\t\tN3 = " << N3.toString() << "\t\tZ3 = " << Z3.toString() << endl;
    std::cout << "B4 = " << B4.toString() << "\t\tD4 = " << D4.toString() << "\t\tN4 = " << N4.toString() << "\t\tZ4 = " << Z4.toString() << endl;
    std::cout << "B5 = " << B5.toString() << "\t\tD5 = " << D5.toString() << "\t\tN5 = " << N5.toString() << "\t\tZ5 = " << Z5.toString() << endl;
    std::cout << "B6 = " << B6.toString() << "\t\tD6 = " << D6.toString() << "\tN6 = " << N6.toString() << "\t\tZ6 = " << Z6.toString() << endl;
    std::cout << "B7 = " << B7.toString() << "\t\tD7 = " << D7.toString() << "\tN7 = " << N7.toString() << "\t\tZ7 = " << Z7.toString() << endl;
    std::cout << "B8 = " << B8.toString() << "\t\tD8 = " << D8.toString() << "\t\tN8 = " << N8.toString() << "\t\tZ8 = " << Z8.toString() << endl;



    //END OF USE OF BRYCE HUSSERL'S TEST METHOD:
    
    //My specific test cases:

    MixedNumber equalTest1(1, 1, 2);
    MixedNumber equalTest2(1, 4, 8);
    std::cout << "equals " << equalTest1.equals(equalTest2) << endl;

    equalTest1 = MixedNumber(0, 12, 12);
    equalTest2 = MixedNumber(0, 18, 18);
    std::cout << "equals " << equalTest1.equals(equalTest2) << endl;

    equalTest1 = MixedNumber(1, 1, 2);
    equalTest2 = MixedNumber(0, 3, 2);
    std::cout << "equals " << equalTest1.equals(equalTest2) << endl;

    equalTest1 = MixedNumber(1, 1, 2);
    equalTest2 = MixedNumber(0, 4, 2);
    std::cout << "equals " << equalTest1.equals(equalTest2) << endl;

    std::cout << equalTest2.toString() << endl;
}
