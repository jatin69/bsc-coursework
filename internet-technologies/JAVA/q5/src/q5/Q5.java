/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package q5;

import java.util.Scanner;

/**
 *
 * @author Jatin
 */
public class Q5 {

    private static Stack mainMenu() {
        System.out.println("******* Welcome to the World of Stacks *******");
        System.out.println("1. Static stack");
        System.out.println("2. Dynamic stack");
        System.out.println("3. Exit");
        Stack ob = null;
        Scanner in = new Scanner(System.in);
        System.out.print("Choose the type of stack : ");
        int choice = in.nextInt();

        switch (choice) {
            case 1: {
                System.out.println("");
                System.out.print("Enter the Size of Static Stack : ");
                int size = in.nextInt();
                try {
                    if (size == 0) {
                        throw new Exception("Error: Size of a Stack Cannot be zero. ");
                    }
                } catch (Exception err) {
                    System.out.print(err.getMessage());
                    System.out.println("Retry !!");
                    mainMenu();
                }
                ob = new StaticStack(size);
            }
            break;
            case 2: {
                ob = new DynamicStack();
            }
            break;
            case 3: {
                System.out.println("Terminating Operations . . . ");
                System.exit(0);

            }
            default:
                System.out.println("Error: Please Choose a Valid Option.\n");
                mainMenu();
        }

        return ob;
    }

    /**
     * @param args the command line arguments
     * @throws java.lang.Exception
     */
    public static void main(String[] args) throws Exception {

        Stack ob = mainMenu();
        while (true) {
            Scanner in = new Scanner(System.in);
            int choice;
            System.out.println("\n\nOperations :");
            System.out.print("1. Push    2. Pop   3. Display   4. exit   ");
            System.out.print(" >>> Select an Operation : ");
            choice = in.nextInt();
            System.out.println("");

            switch (choice) {
                case 1: {
                    System.out.print("Enter an element to insert : ");
                    int ele = in.nextInt();
                    try {
                        ob.push(ele);
                        System.out.print(ele + " pushed to stack.");

                    } catch (Exception err) {
                        System.out.println(err.getMessage());
                    }
                }
                break;

                case 2: {
                    try {
                        int ele = ob.pop();
                        System.out.print("Popped element is : " + ele);
                    } catch (Exception err) {
                        System.out.println(err.getMessage());
                    }

                }
                break;
                case 3: {
                    try {
                        System.out.println("Current Stack Status : ");
                        ob.display();
                    } catch (Exception err) {
                        System.out.println(err.getMessage());
                    }
                }
                break;
                case 4: {
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
