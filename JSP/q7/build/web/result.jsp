<%-- 
    Document   : result
    Created on : 6 Nov, 2016, 12:32:36 AM
    Author     : Jatin
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib prefix="t" uri="WEB-INF/tlds/q7custom.tld" %>

<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>q7 Substring</title>
    </head>
    <body>  
    <h2>
        Substring is :
    </h2>
    <t:substring input="${param.string}" start="${param.start}" end="${param.end}" />
</body>
</html>
