<%-- 
    Document   : index
    Created on : 6 Nov, 2016, 12:17:36 AM
    Author     : Jatin
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
    <center>
        <h1>
            Substring function  
        </h1>
    </center>
    <form action="result.jsp" method="get" >
        <table>
            <tr>
                <td>String:</td> 
                <td><input type="text" name="string"/></td>        
            </tr> 
            <tr>
                <td>Start index: </td>
                <td><input type="text" name="start"/></td>
            </tr>
            <tr>
                <td>End index: </td>
                <td><input type="text" name="end"/></td>
            </tr>
        </table> 
        <br>
        <input type="submit" value="View substring"/>
    </form>        
</body>
</html>
