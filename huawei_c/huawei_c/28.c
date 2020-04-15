//
//  28.c
//  huawei_c
//
//  Created by 李俊杰 on 2020/4/15.
//  Copyright © 2020 李俊杰. All rights reserved.
//

//实现 strStr()

/*
输入: haystack = "hello", needle = "ll"
输出: 2
*/

//使用memcmp

#include <stdio.h>


int strStr(char * haystack, char * needle){
    int lenhay = strlen(haystack);
    int lenneed = strlen(needle);
    if(haystack == NULL || needle == NULL || lenneed ==0){
        return 0;
    }
    for(int i =0 ;i<(lenhay-lenneed+1);i++){
        if( 0 == memcmp(&haystack[i], needle, lenneed)){
            return i;
        }
    }
    return -1;

}
