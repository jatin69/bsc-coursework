<%-- 
    Document   : index
    Created on : 31 Oct, 2016, 5:47:33 PM
    Author     : Jatin
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%@ page import="java.io.*,java.util.*, javax.servlet.*,java.lang.*" %>
<%@ page errorPage="errorPage.jsp" %>

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Greetings ${param.uname}</title>
    </head>
    <body>
    <center>
        <h2>
            <%! String uname;%>
            <%
                uname = request.getParameter("uname");
                int currHour = Calendar.getInstance().get(Calendar.HOUR_OF_DAY);
                if (currHour >= 1 && currHour < 12) {
                    out.println("Good Morning  " + uname);
                } else if (currHour >= 12 && currHour < 17) {
                    out.println("Good Afternoon " + uname);
                } else if (currHour >= 17 && currHour < 25) {
                    out.println("Good Evening " + uname);
                }
            %> 
        </h2>
    </center>
</body>
</html>
