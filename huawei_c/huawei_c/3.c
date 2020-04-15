//
//  3.c
//  huawei_c
//
//  Created by 李俊杰 on 2020/4/15.
//  Copyright © 2020 李俊杰. All rights reserved.
//


//无重复字符的最长子串
/*输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。*/

//滑动窗口
//i:窗口的第一个字符位置.j:窗口之外的第一个字符.k:用于遍历窗口

#include <stdio.h>


int lengthOfLongestSubstring(char * s){
    int ret = 0;
    int len = strlen(s);
    int i =0;
    for(int j = 0 ; j<len;j++){
        for(int k = i ; k<j;k++){
            if(s[k] == s[j]){
                ret = ret>(j-i)?ret:(j-i);
                i = k+1;
            }
        }
        ret = ret>(j-i+1)?ret:(j-i+1);
    }
    return ret;
}
