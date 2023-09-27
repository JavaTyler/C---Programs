package RationalNumbers;

public class TestComplexRationalNumber {

    public static void main(String[] args) {

        ComplexRational ltest = new ComplexRational(10, 20); //Creates complex num w/ ref "l" (real = 10, imaginary = 20)
        ComplexRational rtest = new ComplexRational(5, 15); //Creates complex num w/ ref "r" (real = 5, imaginary = 15)

        ComplexRational result; //Creates result reference for assignment purposes

        //Math function testing for add,sub,div,mult between two complexnums ltest & rtest
        result = ltest.add(rtest);
        System.out.println(result);
        result = ltest.sub(rtest);
        System.out.println(result);
        result = ltest.mult(rtest);
        System.out.println(result);
        result = ltest.div(rtest);
        System.out.println(result);

        //Arithmetic exception handling/test
        try {
            rtest = new ComplexRational();
            result = ltest.div(rtest);
        }
        catch (ArithmeticException e) {
            System.out.println(e);
        }

        rtest = new ComplexRational(5, 15);

        //Testing out the other math functions with a single complexnum; compare ltest rtest.
        System.out.println(ltest.mag());
        System.out.println(ltest.conj());
        System.out.println(ltest.sqrt());
        System.out.println(ltest.equals(rtest)); //Should return false for the current test case

        //Sets real = 10, imaginary = 20 (for rtest)
        rtest.setR(10);
        rtest.setI(20);

        System.out.println(ltest.equals(rtest));

        System.out.println(ltest.getR() + " " + ltest.getI());

    }

}