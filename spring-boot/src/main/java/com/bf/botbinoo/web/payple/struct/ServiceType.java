package com.bf.botbinoo.web.payple.struct;

/**
@file ServiceType.java
@brief 서비스 방식에 대한 구분
@author Copyright (c) 2021 by botbinoo@naver.com
@remarks https://dev.botbinoo.pe.kr/
*/

public enum ServiceType 
{
	TEST("test")
	, PROD("prod");
	
	public String type;
	
	ServiceType(String type)
	{
		this.type = type;
	}
}
