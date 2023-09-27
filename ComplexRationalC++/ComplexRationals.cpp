#include "RationalNumber.h"
#include "ComplexRational.h"
#include <string>
#include <math.h>

ComplexRational::ComplexRational()
    :r(RationalNumber())
    ,i(RationalNumber())

    {

    }

ComplexRational::ComplexRational(double re, double im)
{
    r = setReal(re);
    i = setReal(im);
}
ComplexRational::ComplexRational(const ComplexRational& rhs)
{
    r = rhs.r;
    i = rhs.i;
}

ComplexRational::~ComplexRational()
{

}

/*private RationalNumber setReal(double d) {

    //RationalNumber testCase = new RationalNumber((int)(d * (double)ScaleFactor),ScaleFactor);
    //System.out.println(testCase + " < - - - testCase");
    return new RationalNumber((int)(d * (double)ScaleFactor), ScaleFactor);

}

private double convertDouble(RationalNumber rhs) {
    double convertResult = ((double)rhs.getNumerator() / (double)rhs.getDenominator());
    return convertResult;
}*/

ComplexRational ComplexRational::add(const ComplexRational& rhs) const {
    ComplexRational temp_rhs = ComplexRational(rhs);
    temp_rhs.setR(convertDouble(r) + convertDouble(rhs.r));
    temp_rhs.setI(convertDouble(i) + convertDouble(rhs.i));
    return temp_rhs;
}
ComplexRational ComplexRational::sub(const ComplexRational& rhs) const {
    ComplexRational temp_rhs = ComplexRational(rhs);
    temp_rhs.setR(convertDouble(r) - convertDouble(rhs.r));
    temp_rhs.setI(convertDouble(i) - convertDouble(rhs.i));
    return temp_rhs;
}
ComplexRational ComplexRational::mult(const ComplexRational& rhs) const {
    ComplexRational temp_rhs = ComplexRational();
    temp_rhs.setR((convertDouble(rhs.r) * convertDouble(r)) - (convertDouble(rhs.i) * convertDouble(i)));
    temp_rhs.setI((convertDouble(rhs.r) * convertDouble(i)) + (convertDouble(r) * convertDouble(rhs.i)));
    return temp_rhs;
}
ComplexRational ComplexRational::div(const ComplexRational& rhs) const {
    ComplexRational temp_rhs = ComplexRational();
    double zeroMinCheck = 0.00001;
    if (
        (convertDouble(rhs.r) * (convertDouble(rhs.r)) + (convertDouble(rhs.i) * convertDouble(rhs.i))) <= zeroMinCheck) { //zeroMinCheck to prevent false equals(0) with doubles (Java logic issue)
        throw "Arithmetic Exception! : Divides by Zero";
    }
    /*
    temp_rhs.r = (r * rhs.r + i * rhs.i) / (rhs.r * rhs.r + rhs.i * rhs.i);
    temp_rhs.i = (i * rhs.r - r * rhs.i) / (rhs.r * rhs.r + rhs.i + rhs.i);
     */
    temp_rhs.setR((convertDouble(r) * (convertDouble(rhs.r)) + convertDouble(i) * convertDouble(rhs.i)) / (convertDouble(rhs.r) * convertDouble(rhs.r) + convertDouble(rhs.i) * convertDouble(rhs.i)));
    temp_rhs.setI(((convertDouble(i) * convertDouble(rhs.r)) - (convertDouble(r) * convertDouble(rhs.i))) / ((convertDouble(rhs.r) * convertDouble(rhs.r) + (convertDouble(rhs.i) + convertDouble(rhs.i)))));
    return temp_rhs;
}
ComplexRational ComplexRational::conj() const {

    return ComplexRational(convertDouble(r) * -1, convertDouble(i));

}
ComplexRational ComplexRational::sqroot() const {
    double tempR, tempI;
    tempR = convertDouble(r);
    tempI = convertDouble(i);
    /*
     temp_rhs.r = Math.sqrt((r + Math.sqrt(r * r + i * i))/2);
     temp_rhs.i = Math.sqrt((-r + Math.sqrt(r * r + i * i))/2);
     */
    if (convertDouble(i) != 0.00) {
        tempR = sqrt((((tempR + sqrt((tempR * tempR + tempI * tempI))) / (2))));
        tempI = sqrt(((-tempR + sqrt(((tempR * tempR) + (tempI * tempI))) / 2)));
    }
    else {
        if (tempR >= 0) {
            tempR = sqrt(tempR);
            tempI = 0;
        }
        else {
            tempR = 0;
            tempR = sqrt(-tempR);
        }
    }
    return ComplexRational(tempR, tempI);
}
double ComplexRational::mag() const {
    double tempR, tempI;
    tempR = convertDouble(r);
    tempI = convertDouble(i);
    return sqrt(tempR * tempR + tempI * tempI);
}

/*
 public boolean equals(Object rhs) {
    if (rhs == null) {
        return false;
    }
    if (rhs instanceof ComplexNumber) {
        ComplexNumber cnrhs = (ComplexNumber)rhs;
        if (((Math.abs(cnrhs.i) - this.i) < 0.0001) && ((Math.abs(cnrhs.r) - this.r) < 0.0001)) {
            return true;
        }
        else {
            return false;
        }
    }
    return false;
}
 */
bool ComplexRational::equals(const ComplexRational& rhs) const {
    //cout << (this->getI() + " <-- i r --> " + this.getR());
    //System.out.println(rhs.getI() + " <-- i r --> " + rhs.getR());
    if (rhs.getI() == this->getI() && rhs.getR() == this->getR()) {
        return true;
    }
    else {
        return false;
    }
}
void ComplexRational::setR(double re) {
    this->r = setReal(re);
}
void ComplexRational::setI(double im) {
    this->i = setReal(im);
}
double ComplexRational::getR() const {
    return convertDouble(this->r);
}
double ComplexRational::getI() const {
    return convertDouble(this->i);
}

string ComplexRational::toString() const {
    if (convertDouble(i) >= 0) {
        return to_string(convertDouble(r)) + " + " + to_string(convertDouble(i)) + "i";
    }
    else {
        return to_string(convertDouble(r)) + " - " + to_string(abs(convertDouble(i))) + "i";
    }
}