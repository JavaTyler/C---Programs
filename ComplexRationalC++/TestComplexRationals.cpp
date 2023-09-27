#include <iostream>
#include "ComplexRational.h"
#include "RationalNumber.h"

using namespace std;
int main(int argc, char** argv)
{
	//cout << "command line arguments" << endl;
	//cout << argc << endl;
	//for (int i = 0; i < argc; ++i) {
	// cout << argv[i] << endl;
	//}
	ComplexRational ltest(10, 20); //Creates complex num w/ ref "l" (real = 10, imaginary = 20)
	ComplexRational rtest(5, 15); //Creates complex num w/ ref "r" (real = 5, imaginary = 15)
	ComplexRational result; //Creates result reference for assignment purposes
	//Math function testing for add,sub,div,mult between two complexnums ltest & rtest
	result = ltest.add(rtest);
	cout << result.toString() << endl;
	result = ltest.sub(rtest);
	cout << result.toString() << endl;
	result = ltest.mult(rtest);
	cout << result.toString() << endl;
	result = ltest.div(rtest);
	//Arithmetic exception handling/test
	try {
		rtest = ComplexRational();
		result = ltest.div(rtest);
	}
	catch (...)
	{
		cout << "Error! Arithmetic Exception!" << endl;
	}

	rtest = ComplexRational(5, 15);

	cout << result.toString() << endl;
	//Testing out the other math functions with a single complexnum; compare ltest rtest.
	cout << ltest.mag() << endl;
	cout << ltest.conj()
		.toString() << endl;
	cout << ltest.sqroot()
		.toString() << endl;
	cout << ltest.equals(rtest) << endl; //Should return false for the current test case
	//Sets real = 1, imaginary = 2 (for rtest)
	rtest.setR(10);
	rtest.setI(20);
	cout << ltest.equals(rtest) << endl;
	cout << to_string(ltest.getR()
	) + " " + to_string(ltest.getI()
	) << endl;

	//system("pause");
}
