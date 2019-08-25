/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package q1;

import java.util.Scanner;

/**
 *
 * @author Jatin Rohilla
 */
public class Matrix {

    int[][] mat;
    int rows;
    int cols;

    public Matrix(int row, int column) {
        rows = row;
        cols = column;

        mat = new int[rows][cols];
    }

    public void enter() {

        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print("Element["+i+"]["+j+"] : ");
                mat[i][j] = sc.nextInt();
            }
        }
    }

    private boolean isCompatible(Matrix m, char operation) {

        if (operation == '+' || operation == '-') {
            if (rows == m.rows && cols == m.cols) {
                return true;
            }
        } else if (operation == '*') {
            if (cols == m.rows) {
                return true;
            }
        }
        return false;
    }

    @Override
    public String toString() {

        String matrix = new String();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix = matrix + mat[i][j] + " ";
            }
            matrix = matrix + "\n";
        }
        return matrix;
    }

    public Matrix add(Matrix m) throws Exception {

        if (!isCompatible(m, '+')) {
            throw new Exception("The matricies are not compatible for addition.");
        }
        Matrix res = new Matrix(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res.mat[i][j] = mat[i][j] + m.mat[i][j];
            }
        }
        return res;
    }

    public Matrix subtract(Matrix m) throws Exception {

        if (!isCompatible(m, '-')) {
            throw new Exception("The matricies are not compatible for subtraction.");
        }
        Matrix res = new Matrix(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res.mat[i][j] = mat[i][j] - m.mat[i][j];
            }
        }
        return res;
    }

    public Matrix multiply(Matrix m) throws Exception {

        if (!isCompatible(m, '*')) {
            throw new Exception("The matricies are not compatible for multiplication.");
        }
        Matrix res = new Matrix(rows, m.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                res.mat[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    res.mat[i][j] += mat[i][k] * m.mat[k][j];
                }
            }
        }
        return res;
    }

    public Matrix transpose() {
        Matrix res = new Matrix(cols, rows);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res.mat[i][j] = mat[j][i];
            }
        }
        return res;
    }
}
