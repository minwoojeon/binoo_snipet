package com.bf.botbinoo.web.payple.struct;

/**
@file AuthType.java
@brief 인증방식에 대한 구분
@author Copyright (c) 2021 by botbinoo@naver.com
@remarks https://dev.botbinoo.pe.kr/
*/

public enum AuthType 
{
	MALL("mall")
	, PUSERDEL("puserdel")
	, PUSERINFO("puserinfo");
	
	public String type;
	
	AuthType(String type)
	{
		this.type = type;
	}
}
