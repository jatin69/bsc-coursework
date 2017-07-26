/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package q2;

import arithmetic.*;
import java.util.Scanner;

/* Remember that Java is a statically typed language.
 For more details- Refer: http://stackoverflow.com/a/10781763/5371996
 */
/**
 *
 * @author Jatin
 */
public class Q2 {

    static Scanner sc = new Scanner(System.in);

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        outer:
        while (true) {

            mainMenu();
            switch (sc.nextInt()) {
                case 1: {
                    try {
                        System.out.println("\nEnter First Rational number :");
                        Rational r1 = new Rational();
                        r1.getValue();
                        System.out.println("\nEnter Second Rational number :");
                        Rational r2 = new Rational();
                        r2.getValue();
                        operations(r1, r2);
                    } catch (IllegalArgumentException e) {
                        System.out.println(e.getMessage());
                    } catch (Exception e) {
                        System.out.println(e.getMessage());
                    }

                }
                break;
                case 2: {
                    try {
                        System.out.println("\nEnter First Complex number :");
                        Complex r1 = new Complex();
                        r1.getValue();
                        System.out.println("\nEnter Second Complex number :");
                        Complex r2 = new Complex();
                        r2.getValue();
                        operations(r1, r2);
                    } catch (IllegalArgumentException e) {
                        System.out.println(e.getMessage());
                    } catch (Exception e) {
                        System.out.println(e.getMessage());
                    }
                }
                break;
                case 3: {
                    System.out.println("\nTerminating Operations . . . \n");
                    break outer;
                }
                default: {
                    System.out.println("\nInvalid choice. Retry !!\n");
                }
            }
        }
    }

    /**
     * Display Main Menu on the screen
     */
    private static void mainMenu() {
        System.out.println(" ******* Welcome to the World of Number Operations ******* \n");
        System.out.println("1. Rational Number Operations");
        System.out.println("2. Complex Number Operations");
        System.out.println("3. Exit");
        System.out.print("Enter your Choice : ");

    }

    /**
     * Display Sub Menu on the screen
     */
    private static void subMenu() {
        System.out.println("\nAvailable Operations -");
        System.out.print("1. Addition\t2. Subtraction\t3. Multiplication\t4. Division\t");
        System.out.println("5. Return to Main Menu");
        System.out.print("Enter your Choice : ");
    }

    /**
     * Performs Rational Operations, overloaded with Complex operations
     *
     * @param r1
     * @param r2
     */
    @SuppressWarnings("InfiniteRecursion")
    private static void operations(Rational r1, Rational r2) {
        subMenu();
        switch (sc.nextInt()) {

            case 1: {
                System.out.println("\nSum is :");
                Rational r3 = r1.addition(r2);
                System.out.println(r3.toString() + "\n");
            }
            break;
            case 2: {
                System.out.println("\nDifference is :");
                Rational r3 = r1.subtraction(r2);
                System.out.println(r3.toString() + "\n");

            }
            break;
            case 3: {
                System.out.println("\nProduct is :");
                Rational r3 = r1.multiplication(r2);
                System.out.println(r3.toString() + "\n");
            }
            break;
            case 4: {
                System.out.println("\nQuotient is :");
                Rational r3 = r1.division(r2);
                System.out.println(r3.toString() + "\n");
            }
            break;
            case 5: {
                System.out.println("Returning to Main Menu ... \n");
                return;
            }
            default: {
                System.out.println("Invalid choice. Retry. \n");
            }
        }
        operations(r1, r2);
    }

    /**
     * Performs Complex Operations,. Overloaded with - Rational operations
     *
     * @param r1
     * @param r2
     */
    @SuppressWarnings("InfiniteRecursion")
    private static void operations(Complex r1, Complex r2) {
        subMenu();
        switch (sc.nextInt()) {

            case 1: {
                System.out.println("\nSum is :");
                Complex r3 = r1.addition(r2);
                System.out.println(r3.toString() + "\n");
            }
            break;
            case 2: {
                System.out.println("\nDifference is :");
                Complex r3 = r1.subtraction(r2);
                System.out.println(r3.toString() + "\n");

            }
            break;
            case 3: {
                System.out.println("\nProduct is :");
                Complex r3 = r1.multiplication(r2);
                System.out.println(r3.toString() + "\n");
            }
            break;
            case 4: {
                System.out.println("\nQuotient is :");
                Complex r3 = r1.division(r2);
                System.out.println(r3.toString() + "\n");
            }
            break;
            case 5: {
                System.out.println("Returning to Main Menu ... \n");
                return;
            }
            default: {
                System.out.println("Invalid choice. Retry. \n");
            }
        }
        operations(r1, r2);
    }
}
