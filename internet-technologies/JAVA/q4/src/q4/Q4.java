/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package q4;

import java.util.Scanner;

/**
 *
 * @author Jatin
 */
public class Q4 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        System.out.print("Enter the number            : ");
        Scanner ob = new Scanner(System.in);
        int value = ob.nextInt();
        System.out.println("Decimal Representation is   : " + Integer.toBinaryString(value));
        int num;
        do {
            System.out.print("\nEnter the bit to be flipped ( 0 to 31 ): ");
            num = ob.nextInt();
        } while (num >= 32 || num <= 0);
        System.out.println("");

        int mask = 1;
        int timeShift = num - 1;
        mask = mask << timeShift;

        value ^= mask;

        System.out.println("The result is               : " + value);
        System.out.println("Decimal Representation is   : " + Integer.toBinaryString(value));
    }
}
