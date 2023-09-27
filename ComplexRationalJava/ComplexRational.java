package RationalNumbers;

class ComplexRational {
    private RationalNumber r, i;
    private int ScaleFactor = 10000;
    public ComplexRational() {
        r = new RationalNumber();
        i = new RationalNumber();
    }
    public ComplexRational(double _r, double _i) {
       r = setReal(_r);
       i = setReal(_i);
    }
    public ComplexRational(ComplexRational rhs) {
        r = rhs.r;
        i = rhs.i;
    }
    private RationalNumber setReal(double d) {

        //RationalNumber testCase = new RationalNumber((int)(d * (double)ScaleFactor),ScaleFactor);
        //System.out.println(testCase + " < - - - testCase");
        return new RationalNumber((int)(d * (double)ScaleFactor),ScaleFactor);

    }

    private double convertDouble(RationalNumber rhs) {
        double convertResult = ((double) rhs.getNumerator() / (double)rhs.getDenominator());
        return convertResult;
    }

    public ComplexRational add(ComplexRational rhs) {
        ComplexRational temp_rhs = new ComplexRational(rhs);
        temp_rhs.setR(convertDouble(r) + convertDouble(rhs.r));
        temp_rhs.setI(convertDouble(i) + convertDouble(rhs.i));
        return temp_rhs;
    }
    public ComplexRational sub(ComplexRational rhs) {
        ComplexRational temp_rhs = new ComplexRational(rhs);
        temp_rhs.setR(convertDouble(r) - convertDouble(rhs.r));
        temp_rhs.setI(convertDouble(i) - convertDouble(rhs.i));
        return temp_rhs;
    }
    public ComplexRational mult(ComplexRational rhs) {
        ComplexRational temp_rhs = new ComplexRational();
        temp_rhs.setR((convertDouble(rhs.r) * convertDouble(r)) - (convertDouble(rhs.i) * convertDouble(i)));
        temp_rhs.setI((convertDouble(rhs.r) * convertDouble(i)) + (convertDouble(r) * convertDouble(rhs.i)));
        return temp_rhs;
    }
    public ComplexRational div(ComplexRational rhs) {
        ComplexRational temp_rhs = new ComplexRational();
        double zeroMinCheck = 0.00001;
        if (
                (convertDouble(rhs.r) * (convertDouble(rhs.r)) + (convertDouble(rhs.i) * convertDouble(rhs.i))) <= zeroMinCheck) { //zeroMinCheck to prevent false equals(0) with doubles (Java logic issue)
            throw new ArithmeticException();
        }
        /*
        temp_rhs.r = (r * rhs.r + i * rhs.i) / (rhs.r * rhs.r + rhs.i * rhs.i);
        temp_rhs.i = (i * rhs.r - r * rhs.i) / (rhs.r * rhs.r + rhs.i + rhs.i);
         */
        temp_rhs.setR((convertDouble(r) * (convertDouble(rhs.r)) + convertDouble(i) * convertDouble(rhs.i)) / (convertDouble(rhs.r) * convertDouble(rhs.r) + convertDouble(rhs.i) * convertDouble(rhs.i)));
        temp_rhs.setI(((convertDouble(i) * convertDouble(rhs.r)) - (convertDouble(r) * convertDouble(rhs.i))) / ((convertDouble(rhs.r) * convertDouble(rhs.r)  + (convertDouble(rhs.i) + convertDouble(rhs.i)))));
        return temp_rhs;
    }
    public ComplexRational conj() {

        return new ComplexRational(convertDouble(r) * -1, convertDouble(i));

    }
    public ComplexRational sqrt() {
        double tempR, tempI;
        tempR = convertDouble(r);
        tempI = convertDouble(i);
        /*
         temp_rhs.r = Math.sqrt((r + Math.sqrt(r * r + i * i))/2);
         temp_rhs.i = Math.sqrt((-r + Math.sqrt(r * r + i * i))/2);
         */
        if (!i.equals(0)) {
            tempR = Math.sqrt((((tempR + Math.sqrt((tempR * tempR + tempI * tempI)))/(2))));
            tempI = Math.sqrt(((-tempR + Math.sqrt(((tempR * tempR) + (tempI * tempI)))/2)));
        }
        else {
            if (tempR >= 0) {
                tempR = Math.sqrt(tempR);
                tempI = 0;
            }
            else {
                tempR = 0;
                tempR = Math.sqrt(-tempR);
            }
        }
        return new ComplexRational(tempR, tempI);
    }
    public double mag() {
        double tempR, tempI;
        tempR = convertDouble(r);
        tempI = convertDouble(i);
        return Math.sqrt(tempR*tempR + tempI*tempI);
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
    public boolean equals(ComplexRational rhs) {
        System.out.println(this.getI() + " <-- i r --> " + this.getR());
        System.out.println(rhs.getI() + " <-- i r --> " + rhs.getR());
        if (rhs.getI() == this.getI() && rhs.getR() == this.getR()) {
            return true;
        } else {
            return false;
        }
    }
    public void setR(double re) {
        this.r = setReal(re);
    }
    public void setI(double im) {
        this.i = setReal(im);
    }
    public double getR() {
        return convertDouble(this.r);
    }
    public double getI() {
        return convertDouble(this.i);
    }

    public String toString() {
        if (convertDouble(i) >= 0) {
            return convertDouble(r) + " + " + convertDouble(i) + "i";
        } else {
            return convertDouble(r) + " - " + Math.abs(convertDouble(i)) + "i";
        }
    }

}

