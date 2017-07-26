<%-- 
    Document   : typeA
    Created on : 31 Oct, 2016, 1:14:47 PM
    Author     : Jatin
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%@ page import="java.io.*,java.util.*, javax.servlet.*,java.lang.*" %>
<%@ page errorPage="errorPage.jsp" %>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Q1 - Scriptlets</title>
    </head>
    <body>
    <center><h1>The Number Triangle - using Scriptlets </h1></center>
    <h2>
        <%! int n; // global declaration of n %>
        <%
            n = Integer.parseInt(request.getParameter("num"));
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= i; j++) {
                    out.print(j + " ");
                }
                out.print("<br>");
            }
        %>
    </h2>
    <br>
    <form name="returnToHome" action="index.jsp" method="POST" >
        <button type="submit" name="returnToHome" >Print New Triangle</button>
    </form>

</body>
</html>
