<%-- 
    Document   : b
    Created on : 6 Nov, 2016, 1:27:31 AM
    Author     : Jatin
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
       <title>Page 2</title>
    </head>
    <body>
        <h3>
            Order Info
        </h3>
        Hello ${sessionScope.var} 
        <br>
        You have ordered Product ${param.product} .
    </body>
</html>
