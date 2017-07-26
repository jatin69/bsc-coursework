<%-- 
    Document   : index
    Created on : 6 Nov, 2016, 1:09:59 AM
    Author     : Jatin
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib prefix="t" uri="WEB-INF/tlds/q8custom.tld" %>

<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Q8 String Reversal</title>
    </head>
    <body>
        <h1>String Reversal</h1>
        <form action="index.jsp" method="get" >
            String:<input type="text" name="string"/> 

            <input type="submit" value=" Reverse String"/>
        </form> 
        <br>
        <t:rev input="${param.string}" />

    </body>
</html>
