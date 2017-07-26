<%-- 
    Document   : judge
    Created on : 31 Oct, 2016, 6:17:43 PM
    Author     : Jatin
--%>

<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/functions" prefix="fn" %>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%@ page errorPage="errorPage.jsp" %>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>q5 - Judge </title>
    </head>
    <body>
    <center>
        <h1>Game Result</h1></center>
        <%!
            int i, len;
            String word;
            char c;
            boolean flag;

        %>
        <c:choose>
            <c:when test="${fn:contains(param.option,'even')}">
                <% i = 0; %>
            </c:when>
            <c:when test="${fn:contains(param.option,'odd')}">
                <% i = 1; %>
            </c:when>
        </c:choose>
        <%
            flag = true;
            word = request.getParameter("word");
            len = word.length();
            for (; i < len; i += 2) {
                c = word.charAt(i);
                if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                out.print("<h2>You win !!</h2>");
            } else {
                out.print("<h2>You lose !!</h2>");
            }

        %>

</body>
</html>
