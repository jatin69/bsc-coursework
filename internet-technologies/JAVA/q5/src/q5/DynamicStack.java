/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package q5;

import java.util.ArrayList;

/**
 *
 * @author Jatin Rohilla
 */
public class DynamicStack extends Stack {

    // using Integer arrayList
    ArrayList<Integer> arr;

    public DynamicStack() {
        this.arr = new ArrayList<>();
    }

    @Override
    public void push(int x) throws Exception {
        if (!arr.add(x)) {
            throw new Exception("Error Adding element");
        }
    }

    @Override
    public int pop() throws Exception {

        if (arr.isEmpty()) {
            throw new Exception("Stack Underflow");
        }

        Integer a = arr.remove(arr.size() - 1);
        return a;

    }

    @Override
    public void display() throws Exception {
        if (arr.isEmpty()) {
            throw new Exception("Stack Underflow");
        }
        int i = arr.size() - 1;
        for (; i >= 0; --i) {
            System.out.print(arr.get(i) + "  ");
        }

    }

}
