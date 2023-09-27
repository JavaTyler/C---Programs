package RationalNumbers;

public class MixedNumber extends RationalNumber {
    public int whole;

    public MixedNumber()
    {
        super();
    }

    public MixedNumber(int whole, int numerator, int denominator)
    {
        super(numerator, denominator);
        this.whole = whole;
        simplify();
    }

    public MixedNumber(MixedNumber number)
    {
        super(number);
        whole = number.whole;
        simplify();
    }

    public String toString()
    {
        simplify();
        return (this.whole + " " + super.toString());
    }

    public MixedNumber add(MixedNumber rhs)
    {
        RationalNumber rationalAdded = super.add(rhs);

        MixedNumber result = new MixedNumber();
        result.setNumerator(rationalAdded.getNumerator());
        result.setDenominator(rationalAdded.getDenominator());
        result.whole = this.whole + rhs.whole;
        result.simplify();

        return result;
    }

    public MixedNumber sub(MixedNumber rhs)
    {
        RationalNumber rationalAdded = super.sub(rhs);

        MixedNumber result = new MixedNumber();
        result.setNumerator(rationalAdded.getNumerator());
        result.setDenominator(rationalAdded.getDenominator());
        result.whole = this.whole - rhs.whole;
        result.simplify();

        return result;
    }

    public MixedNumber mult(MixedNumber num)
    {
        RationalNumber lhs = new RationalNumber(whole * getDenominator() + getNumerator() * getSign(), getDenominator());
        RationalNumber rhs = new RationalNumber(num.whole * num.getDenominator() + num.getNumerator() * num.getSign(), num.getDenominator());

        RationalNumber improperResult = lhs.mult(rhs);

        MixedNumber result = new MixedNumber(0, improperResult.getNumerator(), improperResult.getDenominator());
        result.simplify();

        return result;
    }

    int getSign()
    {
        return Math.abs(whole) > 0 ? (int) Math.signum(whole) : (int) Math.signum(getNumerator());
    }

    public MixedNumber div(MixedNumber num)
    {
        //DOES NOT WORK
        RationalNumber lhs = new RationalNumber(whole * getDenominator() + getNumerator(), getDenominator());
        RationalNumber rhs = new RationalNumber(num.getDenominator(), num.whole * num.getDenominator() + num.getNumerator());

        RationalNumber improperResult = lhs.mult(rhs);

        MixedNumber result = new MixedNumber(0, improperResult.getNumerator(), improperResult.getDenominator());
        result.simplify();

        return result;
    }

    public boolean equals(MixedNumber num)
    {
        //make improper and send to base class
        RationalNumber lhs = new RationalNumber(whole * getDenominator() + getNumerator(), getDenominator());
        RationalNumber rhs = new RationalNumber(num.whole * num.getDenominator() + num.getNumerator(), num.getDenominator());

        return lhs.equals(rhs);
    }

    private void simplify()
    {
        if(getNumerator() > 0) {
            whole += (getNumerator() / getDenominator()) * getSign();
            setNumerator(getNumerator() % getDenominator());
        }
        else if(getNumerator() < 0 && ((whole == 0 && Math.abs(getNumerator()) >= getDenominator()) || (whole > 0)))
        {
            whole -= Math.ceil(Math.abs((float) getNumerator() / getDenominator()));
            setNumerator((getDenominator() - Math.abs(getNumerator())) % getDenominator());
        }
    }
}



