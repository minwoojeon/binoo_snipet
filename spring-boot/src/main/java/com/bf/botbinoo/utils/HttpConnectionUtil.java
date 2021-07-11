package com.bf.botbinoo.utils;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;
import java.nio.charset.StandardCharsets;
import java.util.HashMap;
import java.util.Map;

import javax.net.ssl.HttpsURLConnection;

import org.springframework.boot.json.GsonJsonParser;
import org.springframework.web.bind.annotation.RequestMethod;

import net.minidev.json.JSONObject;

/**
@file HttpConnectionUtil.java
@brief http 웹 통신 유틸 프로그램
@author Copyright (c) 2021 by botbinoo@naver.com
@remarks https://dev.botbinoo.pe.kr/
*/

public class HttpConnectionUtil {
	
	public static String sendHttpJson(Map<String,String> headerMap, String targetUrl, Map<String,Object> bodyMap, RequestMethod methodType) 
	{
		URLConnection urlConnection;
        StringBuilder stb = new StringBuilder();
        boolean isSSL = false;
        try {
            URL url = new URL(targetUrl);
            if( "https".contains(targetUrl) )
            	isSSL = true;

            urlConnection = (isSSL ? (HttpsURLConnection) url.openConnection(): (HttpURLConnection) url.openConnection());
            urlConnection.setDoOutput(true);

            for(String key : headerMap.keySet()) 
            	urlConnection.setRequestProperty(key, headerMap.get(key)); 
            
            OutputStream outputStream;
//            if(RequestMethod.POST.equals(methodType))
            {
                if( isSSL )
                    ((HttpsURLConnection) urlConnection).setRequestMethod(methodType.name());
                else
                    ((HttpURLConnection) urlConnection).setRequestMethod(methodType.name());
                outputStream = (isSSL ? (HttpsURLConnection) urlConnection : (HttpURLConnection) urlConnection).getOutputStream();
                outputStream.write( JSONObject.toJSONString(bodyMap).getBytes(StandardCharsets.UTF_8) );
                outputStream.flush();
                outputStream.close();
            }
            BufferedReader reader = new BufferedReader(new InputStreamReader(urlConnection.getInputStream(), StandardCharsets.UTF_8));
            String line = "";
            while( (line = reader.readLine()) != null )
                stb.append(line);
            
            reader.close();
            if( isSSL )
                ((HttpsURLConnection)urlConnection).disconnect();
            else
                ((HttpURLConnection)urlConnection).disconnect();

        } catch (MalformedURLException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return stb.toString();
	}
	public static Map<String, Object> sendHttpPostThenJson(String url, String token, Map<String, Object> bodyMap)
	{
		Map<String,String> headerMap = new HashMap<String,String>();
		headerMap.put("Accept-Charset", "UTF-8");
		headerMap.put("Context_Type", "application/json");
		return new GsonJsonParser().parseMap(sendHttpJson(headerMap, url, bodyMap, RequestMethod.POST));
	}
	public static Map<String, Object> sendHttpGetThenJson(String url, String token, Map<String, Object> bodyMap)
	{
		Map<String,String> headerMap = new HashMap<String,String>();
		headerMap.put("Accept-Charset", "UTF-8");
		headerMap.put("Context_Type", "application/json");
		return new GsonJsonParser().parseMap(sendHttpJson(headerMap, url, bodyMap, RequestMethod.GET));
	}
}
