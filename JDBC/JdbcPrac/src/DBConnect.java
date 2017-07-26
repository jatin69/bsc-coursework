/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

/**
 *
 * @author Jatin Rohilla
 */

public class DBConnect {
    
    private static final String DB_DRIVER="com.mysql.jdbc.Driver";
    private static final String URL = "jdbc:mysql://localhost/college";
    private static final String USER = "root";
    private static final String PASS = "123456789";
    
    public static Connection conn;

    public static Connection connectToDatabase() throws ClassNotFoundException {
        try {
            Class.forName(DB_DRIVER);
            conn = DriverManager.getConnection(URL, USER, PASS);
        } catch (SQLException ex) {
            System.out.println("SQLException: " + ex.getMessage());
            System.out.println("SQLState: " + ex.getSQLState());
            System.out.println("VendorError: " + ex.getErrorCode());
        }
        return conn;
    }
}
