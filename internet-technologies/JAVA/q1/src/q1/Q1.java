/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package q1;

import java.util.Scanner;

/**
 *
 * @author Jatin
 */
public class Q1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        /*
           
         Matrix a= new Matrix(2,2);
         Matrix b= new Matrix(2,3);
         a.enter();   b.enter();
         a.display();  b.display();
        
         Matrix res;
         try {
         res = a.multiply(b);
         res.display();
         } catch (MyException ex) {
         ex.display();
         }              
         }
    
         */
        System.out.println("******* Welcome to the World of matricies *******");
        Scanner sc = new Scanner(System.in);
        int tmp_row, tmp_col;

        System.out.println("");
        System.out.println(">>>> Enter the First Matrix : \n");
        System.out.print("Enter Number of Rows    in the Matrix : ");
        tmp_row = sc.nextInt();
        System.out.print("Enter Number of Columns in the Matrix : ");
        tmp_col = sc.nextInt();
        Matrix m1 = new Matrix(tmp_row, tmp_col);
        System.out.println("Enter elements :");
        m1.enter();

        System.out.println("");
        System.out.println(">>>> Enter the Second Matrix : \n");
        System.out.print("Enter Number of Rows    in the Matrix : ");
        tmp_row = sc.nextInt();
        System.out.print("Enter Number of Columns in the Matrix : ");
        tmp_col = sc.nextInt();
        Matrix m2 = new Matrix(tmp_row, tmp_col);
        System.out.println("Enter elements :");
        m2.enter();

        while (true) {
            int choice;
            System.out.println("\nMatrix Operations :");
            System.out.println("1. Addition      \t2. Subtraction");
            System.out.println("3. Multiplication\t4. Transpose");
            System.out.println("5. Exit");
            System.out.print(" >>> Select an Operation : ");
            choice = sc.nextInt();
            System.out.println("");

            switch (choice) {
                case 1: {
                    try {
                        Matrix res=m1.add(m2);
                        System.out.println("Resultant Matrix is :");
                        System.out.println(res.toString());
                    } catch (Exception err) {
                        System.out.println(err.getMessage());
                    }
                }
                break;

                case 2: {
                    try {
                        Matrix res=m1.subtract(m2);
                        System.out.println("Resultant Matrix is :");
                        System.out.println(res.toString());
                    } catch (Exception err) {
                        System.out.println(err.getMessage());
                    }

                }
                break;
                case 3: {
                    try {
                        Matrix res=m1.multiply(m2);
                        System.out.println("Resultant Matrix is :");
                        System.out.println(res.toString());
                    } catch (Exception err) {
                        System.out.println(err.getMessage());
                    }
                }
                break;
                case 4: {
                    Matrix res;
                    System.out.println("Transpose of First Matrix is :");
                    res = m1.transpose();
                    System.out.println(res.toString());
                    System.out.println("Transpose of First Matrix is :");
                    res = m2.transpose();
                    System.out.println(res.toString());
                }
                break;
                case 5: {
                    System.out.println("Terminating Operations . . . ");
                    System.exit(0);
                }
                break;
                default:
                    System.out.println("Please Choose a Valid Option.");

            }

        }
    }
}
