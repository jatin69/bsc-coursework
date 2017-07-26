/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import java.sql.*;

/**
 *
 * @author Jatin Rohilla
 */
public class Q5 {

    public static void main_Q5(String[] args) throws ClassNotFoundException, SQLException {

        Connection conn;
        Statement stmt;
        ResultSet rs;

        /* Done using Normal Statements */
        conn = DBConnect.connectToDatabase();
        stmt = conn.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_UPDATABLE);
        String sql = "SELECT * FROM `college`.`student` WHERE FirstName = 'Ayush';";
        rs = stmt.executeQuery(sql);

        System.out.println("\n Initial ResultSet :");
        while (rs.next()) {
            int id = rs.getInt("ID");
            String FName = rs.getString("FirstName");
            String LName = rs.getString("LastName");
            System.out.println("ID : " + id + "  " + "Name: " + FName + " " + LName);
        }

        rs.moveToInsertRow();
        rs.updateString("FirstName", "Ayush");
        rs.updateString("LastName", "Singhania");
        rs.insertRow();

        rs.moveToInsertRow();
        rs.updateString("FirstName", "Ayush");
        rs.updateString("LastName", "Malhotra");
        rs.insertRow();

        System.out.println("\nAfter Insertion, Modified Resultset :");
        rs.beforeFirst();
        while (rs.next()) {
            int id = rs.getInt("ID");
            String FName = rs.getString("FirstName");
            String LName = rs.getString("LastName");
            System.out.println("ID : " + id + "  " + "Name: " + FName + " " + LName);
        }
        rs.close();
        stmt.close();
        conn.close();
    }
}
