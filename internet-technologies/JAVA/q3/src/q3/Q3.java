/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package q3;

import java.text.DecimalFormat;
import java.util.Scanner;

/**
 * Driver class for Class BankAccount 
 * @author Jatin
 */
public class Q3 {

    /**
     * Displays subMenu
     */
    private static void subMenu() {
        System.out.println("\n *** Bank Operations ***");
        System.out.println("1. Deposit Money\t    2. WithDraw Money\t\t3. Balance Enquiry\t\t");
        System.out.println("4. View Account Number\t    5. View Owner Details \t6. Switch to a New Bank Account");
        System.out.println("7. Exit");
        System.out.print("Enter your Choice : ");
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        DecimalFormat obf = new DecimalFormat("00.0000");

        System.out.println(" ******** Welcome to the Bank ******** \n");
        System.out.print("Creating a Bank Account for you ...   ");
        BankAccount myAccount = new BankAccount();
        System.out.println("Account Created.");
        System.out.println("Your Bank Account number is : " + myAccount.accountNumber);
        outer:
        while (true) {
            subMenu();
            switch (sc.nextInt()) {
                case 1: {
                    System.out.print("\nEnter the Amount to be deposited : ");
                    double rupees = sc.nextDouble();
                    if (myAccount.deposit(rupees)) {
                        System.out.println("Transaction Successul.");

                    }
                    System.out.println("Deducting taxes " + BankAccount.taxRate + "% on deposited amount.");
                    System.out.println(obf.format(myAccount.taxDeduction(rupees)) + " deducted.");
                    System.out.print("Your New Balance is : ");
                    System.out.println(obf.format(myAccount.getBalance()));
                }
                break;
                case 2: {
                    System.out.print("\nEnter the Amount to be Withdrawn : ");
                    try {
                        double rupees = sc.nextDouble();
                        if (myAccount.withdraw(rupees)) {
                            System.out.println("Transaction Successul.");
                            System.out.print("Your New Balance is :");
                            System.out.println(obf.format(myAccount.getBalance()));
                        }
                    } catch (Exception ex) {
                        ex.getMessage();
                    }
                }
                break;
                case 3: {
                    System.out.print("\nYour Current Balance is :");
                    System.out.println(obf.format(myAccount.getBalance()));
                }
                break;
                case 4: {
                    System.out.println("\nYour Account Number is : " + myAccount.accountNumber);
                }
                break;
                case 5:{
                    System.out.println("\nOwner Details are : ");
                    myAccount.putOwnerDetails();
                }break;
                case 6: {
                    myAccount = new BankAccount();
                }
                break;
                case 7: {
                    System.out.println("\nTerminating Operations ...");
                    break outer;
                }
                default: {
                    System.out.println("\nInvalid Choice. Retry");
                }
            }
        }
    }
}
