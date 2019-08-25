<%-- 
    Document   : typeB
    Created on : 31 Oct, 2016, 1:15:06 PM
    Author     : Jatin
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ page import="java.io.*,java.util.*, javax.servlet.*,java.lang.*" %>
<%@ page errorPage="errorPage.jsp" %>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Q1 - using JSTL</title>
    </head>
    <body>
    <center><h1>The Number Triangle - using JSTL </h1></center>
    <h2>
        
        <c:set var="k" value="${param.num}" />
        <c:forEach var="i" begin="1" end= "${k}" >
            <c:forEach var="j" begin="1" end="${i}">
                <c:out value="${j}" />
            </c:forEach>
            <br>
        </c:forEach>
    </h2>
    <br>
    <form name="returnToHome" action="index.jsp" method="POST" >
        <button type="submit" name="returnToHome" >Print New Triangle</button>
    </form>
</body>
</html>
