package RationalNumbers;

import java.sql.SQLOutput;

public class MixedMain {

    public static void main(String[] args) {
        MixedNumber temp1 = new MixedNumber(1, 3, 4);
        MixedNumber temp2 = new MixedNumber(0, 2, 8);
        MixedNumber temp3 = new MixedNumber(-3, -4, -1);
        MixedNumber temp4 = new MixedNumber(1, 6, 8);

        System.out.println(temp1.toString());
        System.out.println(temp2.toString());
        System.out.println(temp3.toString());
        System.out.println(temp4.toString());

        System.out.println(temp1.equals(temp2));
        System.out.println(temp1.equals(temp4));

        /*System.out.println("Add: " + temp1.add(temp2));
        System.out.println("Sub: " + temp1.sub(temp2));
        System.out.println("Mult: " + temp1.mult(temp2));
        System.out.println("Div: " + temp1.div(temp2));

        System.out.println("Equals: " + temp1.equals(temp2));*/

    }
}
