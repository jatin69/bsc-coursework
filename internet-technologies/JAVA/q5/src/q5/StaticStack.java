/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package q5;

/**
 *
 * @author Jatin Rohilla
 */
public class StaticStack extends Stack {

    int[] arr;
    int stackSize;
    int top;

    public StaticStack(int size) {
        stackSize = size;
        arr = new int[stackSize];
        top = -1;
    }

    @Override
    public void push(int x) throws Exception {

        if (stackSize == top) {
            throw new Exception("Stack Overflow.");
        } else {
            top++;
            arr[top] = x;
        }
    }

    @Override
    public int pop() throws Exception {

        int ele;
        if (top == -1) {
            throw new Exception("Stack Underflow.");
        } else {
            ele = arr[top];
            top--;
        }
        return ele;
    }

    @Override
    public void display() throws Exception {
        if (top == -1) {
            throw new Exception("Stack Underflow.");
        } else {
            for (int i = top; i >= 0; i--) {
                System.out.print(arr[i] + "  ");
            }
            System.out.println("");
        }
    }

}
