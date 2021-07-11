<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>

<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/functions" prefix="fn" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt" %>

<%@ include file="/WEB-INF/views/cmmn/header.jsp" %> 

    <header>
        <div>
        	<h1>결제 테스트</h1>
        </div>
    </header>
    <main>
        <div>
        	상품명 : <input type="text" id="productName" value="[테스트] 프리 메이플 후원"><br>
        	가격 : <input type="number" id="price" value="100"> 원
        	<br><br>
        	사용자 식별키 : <input type="number" id="userSeq" value="77"><br>
        	사용자 이름 : <input type="text" id="userName" value="전민우"><br>
        	사용자 이메일 : <input type="email" id="userEmail" value="botbinoo@naver.com"><br>
        	전달할 내용1 : <input type="text" id="userMent1" value=""><br>
        	전달할 내용2 : <input type="text" id="userMent2" value=""><br>
        	<br><br>
        	* 빌링키 : <input type="text" id="billkey" value=""><br>
        </div>
        <div id="btnPayment">결재!</div>
    </main>
    
    <script src="https://testcpay.payple.kr/js/cpay.payple.1.0.1.js" type="text/javascript"></script>
    <!-- <script src="https://cpay.payple.kr/js/cpay.payple.1.0.1.js"></script> 운영 -->
    <script>
    
        $('#btnPayment').on('click', function (event) {
            
            var obj = new Object();
            obj.PCD_CPAY_VER = "1.0.1";
            obj.PCD_PAY_TYPE = "card";       	
            obj.PCD_PAY_WORK = "CERT";

            /* 01 : 빌링키결제 */
            obj.PCD_CARD_VER = "01"
            
            /* 간편결제 구분 */
            obj.PCD_SIMPLE_FLAG = "Y";
            obj.PCD_PAYER_AUTHTYPE = "pwd";
            
            /* 가맹점 인증요청 */
            obj.payple_auth_file = "${pageContext.request.contextPath}/payple/pg/auth/test/mall";
            
            obj.PCD_PAYER_NO = $('#userSeq').val();
            obj.PCD_PAYER_NAME = $('#userName').val();
            obj.PCD_PAYER_HP = "01077564321";
            obj.PCD_PAYER_EMAIL = $('#userEmail').val();
            obj.PCD_PAY_GOODS = $('#productName').val();
            obj.PCD_PAY_TOTAL = $('#price').val();
            obj.PCD_PAY_ISTAX = "Y";
            obj.PCD_PAY_TAXTOTAL = 10;
            
            if($('#billkey').val() && $('#billkey').val() != '') obj.PCD_PAYER_ID = $('#billkey').val();
            obj.PCD_USER_DEFINE1 = $('#userMent1').val();
            obj.PCD_USER_DEFINE2 = $('#userMent2').val();
            
            obj.PCD_RST_URL = '${pageContext.request.contextPath}/payple/payment';
            
            PaypleCpayAuthCheck(obj);
            
            event.preventDefault(); 	

    });  
        
    </script>