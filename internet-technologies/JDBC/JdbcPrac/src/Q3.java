/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

/**
 *
 * @author Jatin Rohilla
 */
public class Q3 {

    public static void main_Q3(String[] args) throws ClassNotFoundException, SQLException {
       
        // updating All Teachers
        Connection conn;
        PreparedStatement stmt;

        /* Done using Prepared Statements */
        conn = DBConnect.connectToDatabase();
        String sql = "UPDATE `college`.`teacher` SET FirstName = CONCAT('Dr. ',FirstName) ;";
        stmt = conn.prepareStatement(sql);
        stmt.executeUpdate();
        stmt.close();
        conn.close();
        System.out.println("All Teacher Names Updated.");
    }

}
