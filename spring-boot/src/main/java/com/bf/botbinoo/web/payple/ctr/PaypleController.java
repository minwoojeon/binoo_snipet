package com.bf.botbinoo.web.payple.ctr;

import java.util.Map;

import javax.servlet.http.HttpServletRequest;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import com.bf.botbinoo.web.payple.struct.AuthType;
import com.bf.botbinoo.web.payple.struct.ServiceType;
import com.bf.botbinoo.web.payple.svc.AuthService;

/**
@file PaypleController.java
@brief 페이플 샘플 컨트롤러
@author Copyright (c) 2021 by botbinoo@naver.com
@remarks https://dev.botbinoo.pe.kr/
*/

@Controller
@RequestMapping(value="/payple")
public class PaypleController {
	
	@Autowired
	AuthService authService;

    @RequestMapping(value="/buy")
    public String checkout() {
        return "pay/paypleOpen";
    }
    @RequestMapping(value="/payment")
    public String payment(HttpServletRequest req) {
        return "pay/paypleEnd";
    }
    
    // NOTICE : payple auth
    @ResponseBody
    @RequestMapping(value="/pg/auth/{type}/{pcdPayWork}")
    public Map<String, Object> getPGAuth(
    		HttpServletRequest req
    		, ModelMap model
    		, @PathVariable(value = "type") String type
    		, @PathVariable(value = "pcdPayWork") String pcdPayWork
    		) {

    	if(ServiceType.TEST.type.equals(type) || ServiceType.PROD.type.equals(type))
    	{
    		// NOTICE: TEST || PROD
    		if(AuthType.MALL.type.equals(pcdPayWork))				// NOTICE: 몰 인증
    			return authService.getAuthMall(type);
    		else if(AuthType.PUSERDEL.type.equals(pcdPayWork))		// NOTICE: 등록카드 삭제 인증
    			return authService.getAuthPuserDel(type);
    		else if(AuthType.PUSERINFO.type.equals(pcdPayWork))		// NOTICE: 등록카드 조회 인증
    			return authService.getAuthPuserInfo(type);
    	}
    	// ERROR
    	return null;
    }
}
