package com.bf.botbinoo.utils;

import java.security.MessageDigest;

import org.springframework.stereotype.Component;

/**
@file StringUtil.java
@brief 문자열 유틸 프로그램
@author Copyright (c) 2021 by botbinoo@naver.com
@remarks https://dev.botbinoo.pe.kr/
*/

@Component
public final class StringUtil {

	public final int UTIL_VERSION = 1;
	public final String CHAR_SET = "UTF-8";

	public String fillStr(String target, String symbol, int size)
	{
		if(isEmpty(target)) target = "";
		if(target.length() >= size) return target;
		StringBuffer sb = new StringBuffer();
		sb.append(target);
		
		int pt = target.length();
		do
		{
			sb.append(symbol); 
			pt++;
		}
		while(pt < size);
		return sb.toString();
	}
	
	public boolean isNumeric(String target)
	{
		if(isEmpty(target)) return false;
		String regx = "^[0-9]+";
		return target.matches(regx);
	}
	
	public int toNumber(String target)
	{
		if(!isNumeric(target)) return 0;
		return Integer.parseInt(target);
	}
	
	public boolean isEmpty(String target) 
	{
		return target == null || "".equals(target);
	}
	
	public boolean isEmptyString(String target) 
	{
		return "".equals(target);
	}
	
	public boolean isNull(String target) 
	{
		return target == null;
	}
	
	public String safeTrim(String target) 
	{
		return (isEmpty(target) ? "" : target.trim());
	}
		
	public String doEncryptSha256(String msg) throws Exception {
	    MessageDigest md = MessageDigest.getInstance("SHA-256");
	    md.update(msg.getBytes());
	    StringBuilder builder = new StringBuilder();
	    for (byte b: md.digest()) 
	    {
	    	builder.append(String.format("%02x", b));
	    }
	    return builder.toString();
	}
}
