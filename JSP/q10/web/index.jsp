<%-- 
    Document   : index
    Created on : 6 Nov, 2016, 1:25:03 AM
    Author     : Jatin
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Q10 JSP</title>
    </head>
    <body>
        <h1>Consumer Form</h1>
         <form action="a.jsp" method="get">
            <table>
                <tr>
                    <td>Name:</td>
                    <td><input type="text" name="name"/></td>
                </tr>
                <tr>
                    <td>Age:</td>
                    <td><input type="number" name="age"/></td>
                </tr>          
            </table>   
            <br>
            <input type="submit" value="Next Page"/>
        </form>
    </body>
</html>
