package RationalNumbers;

public class RationalNumber {

    private int numerator, denominator;

    public RationalNumber() {
        denominator = 1;
    }

    public RationalNumber(int numerator, int denominator) throws ArithmeticException {
        if (denominator == 0) {
            throw new ArithmeticException();
        }
        this.numerator = numerator;
        this.denominator = denominator;
        simplify();
    }

    public RationalNumber(RationalNumber rhs) {
        numerator = rhs.numerator;
        denominator = rhs.denominator;
    }

    public int getNumerator() {
        return numerator;
    }

    public void setNumerator(int numerator) {
        this.numerator = numerator;
    }

    public int getDenominator() {
        return denominator;
    }

    public void setDenominator(int denominator) throws ArithmeticException {
        if (denominator == 0) {
            throw new ArithmeticException();
        }
        this.denominator = denominator;
    }

    public boolean equals(RationalNumber rhs) {
        int gcd = this.gcd(this.numerator, this.denominator);
        int gcdrhs = rhs.gcd(this.numerator, this.denominator);

        int tempThisN = this.numerator;
        int tempThisD = this.denominator;
        int tempRhsN = rhs.numerator;
        int tempRhsD = rhs.denominator;

        if (this.denominator < 0) {
            tempThisD = this.denominator * -1;
            tempThisN = this.numerator * -1;
        }

        if (rhs.denominator < 0) {
            tempRhsD = rhs.denominator * -1;
            tempRhsN = rhs.numerator * -1;
        }

        if (tempRhsN/gcdrhs == tempThisN/gcd && tempRhsD/gcdrhs == tempThisD/gcd) {
            return true;
        }

        return false;
    }

    public int gcd(int a, int b) { return b==0 ? a : gcd(b, a%b); }
    //Found @: https://stackoverflow.com/questions/4009198/java-get-greatest-common-divisor

    private void simplify(){
        //Shrinks the number to its lowest rational version
        int divisor = gcd(this.numerator, this.denominator);
        this.setNumerator(this.numerator / divisor);
        this.setDenominator(this.denominator / divisor);

        //Checks to see if the negative number is set improperly and flips is
        if (this.denominator < 0) {
            this.setDenominator(this.denominator * -1);
            this.setNumerator(this.numerator * -1);
        }
    }

    public String toString() {

        //int gcd = this.gcd(this.numerator, this.denominator);
        simplify();
        int tempThisN = this.numerator;
        int tempThisD = this.denominator;
        int remainder, wholeNum;

        if (tempThisD < 0) {
            tempThisD = this.denominator * -1;
            tempThisN = this.numerator * -1;
        }

        //Zero check first or else it will be caught by the wrong check due to how their rules are logically defined.
        if (tempThisN == 0) {
            return "0";
        }
        //Denominator will not be negative, do not need to worry about negative denominator cases
        //Smaller numerator, numerator is positive, denominator is positive
        else if (tempThisN < tempThisD && tempThisN == Math.abs(tempThisN) && tempThisD == Math.abs(tempThisD)) {
            return tempThisN + "/" + tempThisD;
        }
        //Smaller numerator, negative numerator
        else if (tempThisN < tempThisD && tempThisN != Math.abs(tempThisN) && Math.abs(tempThisN) < tempThisD) {
            return tempThisN + "/" + tempThisD;
        }
        //Larger numerator; Negatives are handled for this scenario already...
        else if (Math.abs(tempThisN)> tempThisD) {
            remainder = tempThisN%tempThisD; //Remainder
            wholeNum = tempThisN / tempThisD; //Relying on truncation
            if (remainder == 0) {
                return wholeNum + "";
            }
            return wholeNum + " " + Math.abs(remainder) + "/" + tempThisD;
        }
        else {
            return "Logic error warning, you should never see this message.";
        }

    } //end of toString()

    //Positive/Negative adjustment for math functions
    private void thisRationalNumberNegAdjust() {
        if (this.denominator < 0) {
            this.denominator = this.denominator * -1;
            this.numerator = this.numerator * -1;
        }
    }

    public RationalNumber add(RationalNumber rhs) {
        thisRationalNumberNegAdjust();
        RationalNumber temp = new RationalNumber(this.numerator, this.denominator);
        RationalNumber temp2 = new RationalNumber(rhs.numerator, rhs.denominator);
        RationalNumber temp3 = new RationalNumber();

        if (rhs.denominator == this.denominator) {
            temp3.numerator = temp.numerator + temp2.numerator;
            return temp3;
        }
        else {
            temp.numerator = this.numerator * rhs.denominator;
            temp.denominator = this.denominator * rhs.denominator;
            temp2.numerator = rhs.numerator * this.denominator;
            temp2.denominator = rhs.denominator * this.denominator;

            temp3.numerator = temp.numerator + temp2.numerator;
            temp3.denominator = temp.denominator;
            return temp3;
        }
    }

    public RationalNumber sub(RationalNumber rhs) {
        thisRationalNumberNegAdjust();
        RationalNumber temp = new RationalNumber(this.numerator, this.denominator);
        RationalNumber temp2 = new RationalNumber(rhs.numerator, rhs.denominator);
        RationalNumber temp3 = new RationalNumber();

        if (rhs.denominator == this.denominator) {
            temp3.numerator = temp.numerator - temp2.numerator;
            return this;
        }
        else {
            temp.numerator = this.numerator * rhs.denominator;
            temp.denominator = this.denominator * rhs.denominator;
            temp2.numerator = rhs.numerator * this.denominator;
            temp2.denominator = rhs.denominator * this.denominator;

            temp3.numerator = temp.numerator - temp2.numerator;
            temp3.denominator = temp.denominator;
            return temp3;
        }
    }
    public RationalNumber mult(RationalNumber rhs) {
        thisRationalNumberNegAdjust();
        RationalNumber temp = new RationalNumber(this.numerator, this.denominator);
        RationalNumber temp2 = new RationalNumber(rhs.numerator, rhs.denominator);
        RationalNumber temp3 = new RationalNumber();

        temp3.numerator = temp.numerator * temp2.numerator;
        temp3.denominator = temp.denominator * temp2.denominator;
        return temp3;
    }

   public RationalNumber div(RationalNumber rhs) {
        thisRationalNumberNegAdjust();
        RationalNumber temp = new RationalNumber(this.numerator, this.denominator);
        RationalNumber temp2 = new RationalNumber(rhs.numerator, rhs.denominator);
        RationalNumber temp3 = new RationalNumber();
        RationalNumber temp4 = new RationalNumber();

        //Could've done reciprocal initially but decided to do separately for simplification
       //Technically do not need to do this, can simply do the math in a specific form but this shows more detail
        if (temp2.numerator != Math.abs(temp2.numerator)) {
            temp3.numerator = temp2.denominator * -1;
            temp3.denominator = temp2.numerator * -1;
        }
        else {
            temp3.numerator = temp2.denominator;
            temp3.denominator = temp2.numerator;
        }

        //Can also call the mult() function passing in rhs, but I decided to do it separately.
        temp4.numerator = temp.numerator * temp3.numerator;
        temp4.denominator = temp.denominator * temp3.denominator;
        return temp4;
    }


}