<%-- 
    Document   : index
    Created on : 31 Oct, 2016, 6:02:57 PM
    Author     : Jatin
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%@ page errorPage="errorPage.jsp" %>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>q5 JSP</title>
    </head>
    <body>
    <center><h1>Game Room</h1></center>
    <form name="myform" action="judge.jsp" method="POST">
        <label>Enter your word:   </label>
        <input type="text" name="word" value="" />
        <br><br>
        <label>Choose the game type: </label> <br>
        <input type="radio" name="option" value="odd" checked/>odd <br>
        <input type="radio" name="option" value="even" />even<br>
        <br><input type="submit" value="RUN" name="submit" />
    </form>
</body>
</html>
