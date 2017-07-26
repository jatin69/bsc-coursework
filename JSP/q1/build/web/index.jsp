<%-- 
    Document   : index
    Created on : 31 Oct, 2016, 1:08:40 PM
    Author     : Jatin
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%@ page import="java.io.*,java.util.*, javax.servlet.*,java.lang.*" %>
<%@ page errorPage="errorPage.jsp" %>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Q1</title>
    </head>
    <body>
        <h1>Printing Number Triangle</h1>
        <h3>
            Triangle using Scriptlets
        </h3>
        <form name="fortypeA" action="typeA.jsp" method="GET">
            <label>Enter the length of Triangle  </label>
            <input type="text" name="num" />       
            <button type="submit" >RUN </button>
        </form>
        <br>
        <h3>
            Triangle using JSTL Loop
        </h3>
        <form name="fortypeB" action="typeB.jsp" method="GET">
            <label>Enter the length of Triangle  </label>
            <input type="text" name="num" />       
            <button type="submit"  >RUN </button>
        </form>
    </body>
</html>
