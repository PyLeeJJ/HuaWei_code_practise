//
//  14.c
//  huawei_c
//
//  Created by 李俊杰 on 2020/4/15.
//  Copyright © 2020 李俊杰. All rights reserved.
//


//最长公共前缀
/*
输入: ["flower","flow","flight"]
输出: "fl"
*/

//所有的和第一个字符串进行比较,方法挺巧妙的

#include <stdio.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize == 0){
        return "";
    }
    for(int i = 0;i<strlen(strs[0]);i++){
        for(int j = 0;j < strsSize;j++){
            if(strs[0][i] != strs[j][i]){
                strs[0][i] = '\0';
                break;
            }
        }
    }
    return strs[0];

}
