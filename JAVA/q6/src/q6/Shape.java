/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package q6;

import java.util.Scanner;

/**
 *
 * @author Jatin Rohilla
 */

public class Shape {
     int x;
     int y;
    public void get(){
        Scanner ob = new Scanner(System.in);
        
        System.out.print("Enter X : ");
        x=ob.nextInt();
        
        System.out.print("Enter Y : ");
        y=ob.nextInt();
        
    }
    public void show(){
        System.out.println("X is : "+x);
        System.out.println("Y is : "+y); 
    }
}

