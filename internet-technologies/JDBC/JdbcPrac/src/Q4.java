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
public class Q4 {

    public static void main_Q4(String[] args) throws ClassNotFoundException, SQLException {

        // Develop Driver functions if required.
        int id = 3;
        Connection conn;
        PreparedStatement stmt;

        /* Done using Prepared Statements */
        conn = DBConnect.connectToDatabase();
        String sql = "DELETE FROM `college`.`student` WHERE ID = ?";
        stmt = conn.prepareStatement(sql);
        stmt.setInt(1, id);

        int affectedRows = stmt.executeUpdate();
        if (affectedRows == 0) {
            System.out.println("Student with ID - " + id + " not found !!");
        } else {
            System.out.println("Student with ID - " + id + " Deleted successfully !!");
        }
        stmt.close();
        conn.close();

    }
}
