/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;

/**
 *
 * @author Jatin Rohilla
 */
public class Q2 {

    public static void main_Q2(String[] args) throws ClassNotFoundException, SQLException {

        // updating Rita
        Connection conn;
        Statement stmt;

        /* Done using Normal Statements */
        conn = DBConnect.connectToDatabase();
        String sql = "UPDATE `college`.`teacher` SET FirstName = CONCAT('Dr. ',FirstName) where FirstName = 'Rita';";
        stmt = conn.createStatement();
        stmt.executeUpdate(sql);
        stmt.close();
        conn.close();
        System.out.println("Teacher Rita's Name Updated.");
    }

}
