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
public class Q1 {

    /**
     * @param args the command line arguments
     * @throws java.lang.ClassNotFoundException
     * @throws java.sql.SQLException
     */
    public static void main_Q1(String[] args) throws ClassNotFoundException, SQLException {

        Connection conn;
        PreparedStatement stmt;

        /* Done using Prepared Statements */
        conn = DBConnect.connectToDatabase();
        String sql = "INSERT INTO `college`.`student` (`FirstName`, `LastName`) VALUES (?,?);";
        stmt = conn.prepareStatement(sql);

        stmt.setString(1, "Aryan");
        stmt.setString(2, "Agarwal");
        stmt.executeUpdate();

        stmt.setString(1, "Jatin");
        stmt.setString(2, "Rohilla");
        stmt.executeUpdate();

        stmt.close();
        conn.close();

        /* The same thing can also be done using Normal statements
         Statement stmt = conn.createStatement();
        
         String createtable= "
         CREATE TABLE `student` (
         `ID` int(11) NOT NULL AUTO_INCREMENT,
         `FirstName` varchar(45) NOT NULL,
         `LastName` varchar(45) NOT NULL,
         PRIMARY KEY (`ID`)
         );
         ";
         
         String insertintotable="
         INSERT INTO `college`.`student`
         (`FirstName`,
         `LastName`)
         VALUES
         ( 'Jatin', 'Rohilla');
         ";
        
         stmt.executeUpdate(createtable);
         stmt.executeUpdate(insertintotable);
         */
    }
}
