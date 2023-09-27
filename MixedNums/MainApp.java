package RationalNumbers;

public class MainApp {

    public static void main(String[] args) {
        //Simple tests (constructors + toString())
        RationalNumber case1 = new RationalNumber();
        System.out.println("Default Constructor: numerator: " + case1.getNumerator() + " denominator: " + case1.getDenominator());

        RationalNumber case2 = new RationalNumber(3,5);
        System.out.println("Overload constructor: " + case2);

        RationalNumber case3 = new RationalNumber(2, -7);
        System.out.println("Negative sign flip to numerator: " + case3);

        RationalNumber case4 = new RationalNumber(0, -1);
        System.out.println("Numerator 0 causes a return of 0 alone: " + case4);

        /*RationalNumber case5 = new RationalNumber(105, 0);
        Denominator of 0 causes a return of ArithmeticException*/

        RationalNumber case6 = new RationalNumber(-5016, -18);
        System.out.println("Goes from improprer fraction to mixed, rational number reduces, double negative logic handled: " + case6);

        RationalNumber case7 = new RationalNumber(-7, 3);
        System.out.println("Negative mixed number: " + case7);

        RationalNumber wholeOnly = new RationalNumber(30,15);
        System.out.println("Rational number (30/15) gets reduced to whole number: " + wholeOnly);

        //Getters + Setters
        RationalNumber case8 = new RationalNumber(7, 10);
        System.out.println("Getters and Setters, starting case: " + case8);
        case8.setNumerator(12);
        case8.setDenominator(13);
        System.out.print("New numerator + denominator: ");
        System.out.println(case8);

        //Arithmetic
        RationalNumber arithmeticCase1 = new RationalNumber(4, 5);
        RationalNumber arithmeticCase2 = new RationalNumber(-3, 12);

        System.out.println("Addition: ");
        System.out.println(arithmeticCase1.add(arithmeticCase2));
        System.out.print("Subtraction: ");
        System.out.println(arithmeticCase1.sub(arithmeticCase2));
        System.out.print("Multiplication: ");
        System.out.println(arithmeticCase1.mult(arithmeticCase2));
        System.out.print("Division: ");
        System.out.println(arithmeticCase1.div(arithmeticCase2));

        //Equivalence
        RationalNumber case9 = new RationalNumber(1,2);
        RationalNumber case10  = new RationalNumber(5, 10);
        System.out.println("Equivalence testing, should return true: " + case9.equals(case10));
        case10.setDenominator(40);
        System.out.println("Equivalence testing, should return false: " + case9.equals(case10));
    }

}
