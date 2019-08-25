/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package q6;

/**
 *
 * @author Jatin
 */
public class Q6 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        /*
         * Dynamic Method Dispatch Concept: calling the functions of child class
         * using the object of super class.
         */
        System.out.println("****** Welcome to the Shape World ****** ");
        System.out.println("\nA Shape is being created ... ");
        Shape myShape = new Rect();
        myShape.get();
        System.out.println("\nDisplaying as Rectangle ...");
        myShape.show();

    }

}
