/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package q3;

import java.util.Scanner;

/**
 * <h2>Simulating a Bank Account</h2>
 *
 * @version 1.1
 * @author Jatin Rohilla
 */
public class BankAccount {

    /**
     * enum Gender of the person. Can take values- Male, Female.
     */
    private enum Gender {

        MALE, FEMALE
    }

    /**
     * Variable to store gender of the Owner
     */
    private Gender gender;
    /**
     * Variable to store name of the person
     */
    private String name;

    /**
     * Account number for a Bank Account.
     * <h2>Auto generated</h2>
     */
    public static long accountNumber = 100;
    /**
     * Current Balance in the account
     */
    private double balance;
    /**
     * The taxRate of Bank. The Bank charges 0.25% on all deposits
     */
    public static final float taxRate = 0.25f;

    /**
     * Constructor - Auto assigns the Account Number and sets balance to zero.
     */
    public BankAccount() {
        accountNumber++;
        this.accountNumber = accountNumber;
        this.balance = 0;
        getOwnerDetails();
    }

    /**
     * Method to get Owner details for a Bank account
     */
    private void getOwnerDetails() {
        Scanner sc = new Scanner(System.in);
        System.out.println("\nEnter the Following owner details - ");
        System.out.print("Name   : ");
        this.name = sc.nextLine();
        System.out.print("Gender :   1. Male   2. Female  , Your choice : ");
        int choice = sc.nextInt();
        if (choice == 1) {
            this.gender = Gender.MALE;
        } else if (choice == 2) {
            this.gender = Gender.FEMALE;
        } else {
            try {
                throw new Exception("Please enter gender from specified values.");
            } catch (Exception ex) {
                System.out.println(ex.getMessage());
                this.getOwnerDetails();
            }
        }
    }

    /**
     * Method to display owner details
     */
    public void putOwnerDetails() {
        System.out.println("Name   : " + this.name);
        System.out.println("Gender : " + this.gender);
    }

    /**
     * Method to deposit money in the bank
     *
     * @param rupees is the amount to be deposited
     * @return transaction status
     */
    public boolean deposit(double rupees) {
        balance += rupees;
        return true;
    }

    /**
     * Method to withdraw money in the bank.
     *
     * @param rupees the amount to be withdrawn
     * @return transaction status
     * @throws Exception when user try to withdraw more money than the balance.
     */
    public boolean withdraw(double rupees) throws Exception {
        if (!(balance - rupees >= 0)) {
            throw new Exception("More Money Cannot be Withdrawn than the balance. Retry !!");
        }
        balance -= rupees;
        return true;
    }

    /**
     * Method to check the current balance in account.
     *
     * @return current balance
     */
    public double getBalance() {
        return balance;
    }

    /**
     * Method to deduct taxes while depositing the money.
     *
     * @param rupees is the amount to be deposited
     * @return current balance
     */
    double taxDeduction(double rupees) {
        double tax = (rupees * (taxRate / 100));
        balance -= tax;
        return tax;
    }
}
