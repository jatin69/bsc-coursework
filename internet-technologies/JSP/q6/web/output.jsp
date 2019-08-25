<%-- 
    Document   : output
    Created on : 5 Nov, 2016, 11:00:58 PM
    Author     : Jatin
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib prefix="cu" uri="WEB-INF/tlds/custom.tld" %>

<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Q6 Advice </title>
    </head>
    <body>

        <cu:hello name="${param.name}" />   
        <cu:choco texture="${param.texture}"/>

    </body>
</html>
