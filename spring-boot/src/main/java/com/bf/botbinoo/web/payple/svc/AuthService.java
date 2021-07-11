package com.bf.botbinoo.web.payple.svc;

import java.util.HashMap;
import java.util.Map;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;

import com.bf.botbinoo.utils.HttpConnectionUtil;

/**
@file AuthService.java
@brief 페이플 결재 인증 서비스
@author Copyright (c) 2021 by botbinoo@naver.com
@remarks https://dev.botbinoo.pe.kr/
*/

@Service
public class AuthService {

	@Value("${cpay.payple.prod.id}")
	public String prodPaypleId;

	@Value("${cpay.payple.prod.url}")
	public String prodPaypleUrl;

	@Value("${cpay.payple.prod.key}")
	public String prodPaypleKey;
	
	@Value("${cpay.payple.test.id}")
	public String testPaypleId;

	@Value("${cpay.payple.test.url}")
	public String testPaypleUrl;

	@Value("${cpay.payple.test.key}")
	public String testPaypleKey;

	public Map<String, Object> getAuthBody(String type)
	{
		Map<String,Object> bodyMap = new HashMap<String,Object>();
		Map<String,Object> resultMap = new HashMap<String,Object>();
		
		switch(type)
		{
			case "prod":
				resultMap.put("url", prodPaypleUrl);
				bodyMap.put("cst_id", prodPaypleId);
				bodyMap.put("custKey", prodPaypleKey);
				break;
			default:
				resultMap.put("url", testPaypleUrl);
				bodyMap.put("cst_id", testPaypleId);
				bodyMap.put("custKey", testPaypleKey);
				break;
		}
		resultMap.put("body", bodyMap);
		return resultMap;
	}

	@SuppressWarnings({ "unchecked", "rawtypes" })
	public Map<String, Object> getAuthMall(String type)
	{
		Map<String,Object> authMap = getAuthBody(type);
    	return HttpConnectionUtil.sendHttpPostThenJson((String) authMap.get("url"), "", (Map)authMap.get("body"));
	}

	@SuppressWarnings({ "unchecked", "rawtypes" })
	public Map<String, Object> getAuthPuserDel(String type)
	{
		Map<String,Object> authMap = getAuthBody(type);
		((Map)authMap.get("body")).put("PCD_PAY_WORK", "PUSERDEL");
    	return HttpConnectionUtil.sendHttpPostThenJson((String) authMap.get("url"), "", (Map)authMap.get("body"));
	}

	@SuppressWarnings({ "unchecked", "rawtypes" })
	public Map<String, Object> getAuthPuserInfo(String type)
	{
		Map<String,Object> authMap = getAuthBody(type);
		((Map)authMap.get("body")).put("PCD_PAY_WORK", "PUSERINFO");
    	return HttpConnectionUtil.sendHttpPostThenJson((String) authMap.get("url"), "", (Map)authMap.get("body"));
	}
}
