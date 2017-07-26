/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package arithmetic;

import java.util.Scanner;

/**
 *
 * @author Jatin Rohilla
 */
public class Rational {

    private int numerator;
    private int denominator;

    public Rational() {
        numerator = 0;
        denominator = 1;
    }

    public Rational(int num, int denom) {
        numerator = num;
        denominator = denom;
        if (denominator == 0) {
            throw new IllegalArgumentException("\nThe 'denominator' cannot be 0 , Retry !!\n");
        }
        simplify();
    }

    public void getValue() {
        Scanner ob = new Scanner(System.in);
        System.out.print("Enter numerator  : ");
        numerator = ob.nextInt();
        System.out.print("Enter denominator: ");
        denominator = ob.nextInt();
        if (denominator == 0) {
            throw new IllegalArgumentException("\nThe 'denominator' cannot be 0 , Retry !!\n");
        }
        simplify();
    }

    public Rational addition(Rational ob1) {
        Rational result = new Rational();
        result.numerator = (numerator * ob1.denominator) + (ob1.numerator * denominator);
        result.denominator = denominator * ob1.denominator;
        result.simplify();
        return result;
    }

    public Rational subtraction(Rational ob1) {
        Rational result = new Rational();
        result.numerator = (numerator * ob1.denominator) - (ob1.numerator * denominator);
        result.denominator = denominator * ob1.denominator;
        result.simplify();
        return result;
    }

    public Rational multiplication(Rational ob1) {
        Rational result = new Rational();
        result.numerator = numerator * ob1.numerator;
        result.denominator = denominator * ob1.denominator;
        result.simplify();
        return result;
    }

    public Rational division(Rational ob1) {
        Rational result = new Rational();
        result.numerator = numerator * ob1.denominator;
        result.denominator = denominator * ob1.numerator;
        result.simplify();
        return result;
    }

    @Override
    public String toString() {
        String result;
        result = "" + numerator;
        if (denominator != 1 && numerator != 0) {
            result = result + "/" + denominator;
        }
        return result;
    }

    private void simplify() {
        int gcd = MyMath.gcd(Math.abs(numerator), Math.abs(denominator));
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0) {
            denominator = denominator * -1;
            numerator = numerator * -1;
        }
    }

    public Rational changeSign() {
        Rational result = new Rational();
        result.numerator = (-1) * numerator;
        result.denominator = denominator;
        return result;
    }
}
