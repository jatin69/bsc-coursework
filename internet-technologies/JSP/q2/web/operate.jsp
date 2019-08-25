<%-- 
    Document   : operate
    Created on : 31 Oct, 2016, 4:12:24 PM
    Author     : Jatin
--%>

<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%@ page import="java.io.*,java.util.*, javax.servlet.*,java.lang.*" %>
<%@ page errorPage="errorPage.jsp" %>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Q2- Result</title>
    </head>
    <body>
    <center>
        <h1>Calculation Result</h1>
    </center>
    <%! int a, b, res, op;%>   

    <%
        a = Integer.parseInt(request.getParameter("opr1"));
        b = Integer.parseInt(request.getParameter("opr2"));
        op = Integer.parseInt(request.getParameter("operation"));

        if (op == 1) {
            res = a + b;
        } else if (op == 2) {
            res = a - b;
        } else if (op == 3) {
            res = a * b;
        }
    %>	
    <h3>
        Result using getParameter function :  <%=res%>
    </h3>

    <h3>    
        Result using Expression Language :
        <c:if test="${param.operation == 1}">
            ${param.opr1 + param.opr2}
        </c:if>
        <c:if test="${param.operation == 2}">
            ${param.opr1 - param.opr2}
        </c:if>
        <c:if test="${param.operation == 3}">
            ${param.opr1 * param.opr2}
        </c:if>
    </h3>
</body>
</html>
