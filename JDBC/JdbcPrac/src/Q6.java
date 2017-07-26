
/*
 Stored Procedure created in mysql Workbench is :

 USE `college`;
 DROP procedure IF EXISTS `noOfRows`;

 DELIMITER $$
 USE `college`$$
 CREATE PROCEDURE `noOfRows` ()
 BEGIN
 SELECT COUNT(*) FROM student;
 END$$

 DELIMITER ;

 
 In phpmyadmin :
 CREATE DEFINER=`root`@`localhost` PROCEDURE `noOfRows`()
BEGIN
SELECT COUNT(*) 
FROM 
student;
END
 
 */
import java.sql.*;

/**
 *
 * @author Jatin Rohilla Reference :
 * http://www.xyzws.com/javafaq/how-to-call-a-stored-procedure-by-jdbc-java-class/169
 */
public class Q6 {

    public static void main_Q6(String[] args) throws ClassNotFoundException, SQLException {

        Connection conn;
        CallableStatement stmt;
        ResultSet rs;

        /* Done using Normal Statements */
        conn = DBConnect.connectToDatabase();

        String procName = " {call noOfRows() } ";
        stmt = conn.prepareCall(procName);
        stmt.executeQuery();

        /* When one result set is returned, we can directly fetch it.
         In case of multiples, stmt.getMoreResults(); can be used. */
        rs = stmt.getResultSet();
        int rowCount = 0;
        while (rs.next()) {
            rowCount = rs.getInt(1);
        }
        System.out.println("No. of rows in Student table: " + rowCount);

        rs.close();
        stmt.close();
        conn.close();
    }
}
