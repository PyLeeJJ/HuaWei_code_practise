//
//  151.c
//  huawei_c
//
//  Created by 李俊杰 on 2020/4/14.
//  Copyright © 2020 李俊杰. All rights reserved.
//

//反转字符串中的单词
/*输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。*/

#include <stdio.h>
#include <stdlib.h>

char * reverseWords(char * s){
    int len = strlen(s);
    if(len == 0){
        return s;
    }
    char *res = (char *)malloc(sizeof(char)*(len+2));
    char *stack = (char *)malloc(sizeof(char)*(len+2));
    //定义
    int t = 0,flag = 0,count = 0;
    for(int i = len - 1 ;i >= 0;i--){
        if(s[i] != ' '){
            stack[t++] = s[i];
            flag = 1;
        }
        else{
            while(t > 0){
                res[count++] = stack[--t];
            }
            if(flag == 1){
                res[count++] = ' ';
            }
            flag = 0;
        }
    }
    //处理第一个多的空格
    if(t == 0){
        if(count >0 ){
            count--;
        }
    }
    //处理第一个字符串
    while(t > 0){
        res[count++] = stack[--t];
    }
    res[count] = '\0';
    return res;
    
}
