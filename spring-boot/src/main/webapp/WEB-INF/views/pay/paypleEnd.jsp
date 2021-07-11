<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>

<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/functions" prefix="fn" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt" %>

<%@ include file="/WEB-INF/views/cmmn/header.jsp" %> 
<body>
<h3>결과</h3><br>

${param}

<br><br>
<a href="${pageContext.request.contextPath}/payple/buy">
<h3>돌아가기</h3>
</a>
</body>