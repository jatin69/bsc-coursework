/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package arithmetic;

/**
 *
 * @author Jatin Rohilla
 */
public class Complex {

    private Rational real;
    private Rational imaginary;

    public Complex() {
        real = new Rational();
        imaginary = new Rational();
    }

    public Complex(Rational a, Rational b) {
        real = a;
        imaginary = b;
    }

    public Complex(int a, int b, int c, int d) {

        real = new Rational(a, b);
        imaginary = new Rational(c, d);
    }

    public void getValue() {

        System.out.println("Enter the real part:");
        real.getValue();

        System.out.println("Enter the imaginary part:");
        imaginary.getValue();
    }

    @Override
    public String toString() {

        String complex = "(" + real.toString() + ") +  (" + imaginary.toString() + ") i";
        return complex;
    }

    public Complex addition(Complex ob1) {

        Complex result = new Complex();
        result.real = real.addition(ob1.real);
        result.imaginary = imaginary.addition(ob1.imaginary);
        return result;
    }

    public Complex subtraction(Complex ob1) {

        Complex result = new Complex();
        result.real = real.subtraction(ob1.real);
        result.imaginary = imaginary.subtraction(ob1.imaginary);
        return result;
    }

    /**
     * 
     * @param ob1
     * @return
     * Formula used: (a+bi)*(c+di)= (ac-bd) + i(ad+bc)
     */
    public Complex multiplication(Complex ob1) {

        Complex result = new Complex();
        Rational r1, r2;

        // calculating REAL part:
        r1 = real.multiplication(ob1.real);
        r2 = imaginary.multiplication(ob1.imaginary);
        result.real = r1.subtraction(r2);

        // calculating imaginary part
        r1 = real.multiplication(ob1.imaginary);
        r2 = imaginary.multiplication(ob1.real);
        result.imaginary = r1.addition(r2);

        return result;
    }

    /**
     * Calculates the Conjugate of a Complex Number
     * @return 
     */
    private Complex conjugate() {
        
        Complex result = new Complex();
        result.real = real;
        result.imaginary = imaginary.changeSign();
        return result;
    }

    /**
     * Calulates upper/lower when called as upper.division(lower).
     * @param lower
     * @return Complex Number
     */
    public Complex division(Complex lower){
        
        Complex result=new Complex();     
        Rational realDenom=lower.multiplication(lower.conjugate()).real;
        Complex complexNum=this.multiplication(lower.conjugate());
        result.real=complexNum.real.division(realDenom);
        result.imaginary=complexNum.imaginary.division(realDenom);
        return result;
        
    }
}
