package com.bf.botbinoo.web.kakao.ctr;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

/**
@file KakaoController.java
@brief Kakao 연동 샘플 스니펫
@author Copyright (c) 2021 by botbinoo@naver.com
@remarks https://dev.botbinoo.pe.kr/
*/

@Controller
@RequestMapping(value="/kakao")
public class KakaoController {

    @RequestMapping(value="/map")
    public String map() {
        return "map/kakaomap";
    }
}
