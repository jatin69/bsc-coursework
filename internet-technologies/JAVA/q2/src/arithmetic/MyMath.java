/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package arithmetic;

import java.math.BigInteger;

/**
 *
 * @author Jatin Rohilla
 */
public class MyMath {

    public static int gcd(int x, int y) {
        BigInteger b1 = BigInteger.valueOf(x);
        BigInteger b2 = BigInteger.valueOf(y);
        BigInteger gcd = b1.gcd(b2);
        return gcd.intValue();
    }
}
