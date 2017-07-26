<%-- 
    Document   : index
    Created on : 31 Oct, 2016, 8:22:17 PM
    Author     : Jatin
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Q6</title>
    </head>
    <body>
    <center>
        <h1>
            Chocolate adviser
        </h1>
    </center>
    <form action="output.jsp" method="get">
        Name: <input type="text" name="name"/>

        <br><br>
        Select chocolate texture preference: <br>
        <input type="radio" name="texture" value="chewy" checked> Chewy
        <input type="radio" name="texture" value="crunchy" > Crunchy

        <br><br>
        <input type="submit" value="View"/>
    </form>
</body>
</html>
