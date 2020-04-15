//
//  1048.c
//  huawei_c
//
//  Created by 李俊杰 on 2020/4/14.
//  Copyright © 2020 李俊杰. All rights reserved.
//

//最长字符串链
//输入：["a","b","ba","bca","bda","bdca"]
//输出：4
//解释：最长单词链之一为 "a","ba","bda","bdca"

#include <stdio.h>
#include <stdlib.h>

/*判断a是否为b的前身
  返回1表示是，返回0表示否*/

int isPreString(char *a,char *b)
{
    if(strlen(a) + 1 != strlen(b)){
        return 0;
    }
    int i=0,j=0;
    while(i < strlen(a) && j < strlen(b)){
        if(a[i] == b[j]){
            i++;
            j++;
            continue;
        }
        else{
            j++;
        }
    }
    if(i == strlen(a)){
        return 1;
    }
    return 0;
}

int max(int a,int b){
    return a > b ?a:b;
}

/*dp*/
int longestStrChain(char ** words, int wordsSize){
    if(words == NULL){
        return 0;
    }
    if(wordsSize < 1){
        return 0;
    }
    /*定义*/
    int i = 0 ,j = 0;
    char *temp;
    int *dp;
    int ret = 0;
    //排序字符串按照长度
    for (i = 0; i < wordsSize; ++i) {
        for (j = i + 1; j < wordsSize; ++j) {
            if (strlen(words[i]) > strlen(words[j])) {
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
    dp = (int *)malloc((wordsSize) * sizeof(int));
    for(int i =0 ; i<wordsSize ;++i)
    {
        dp[i] = 1;
    }
    
    // 如果单词 word[i] 是word[j]的前身，那么word[j] = max(dp[j],dp[i]+1)
    for (i = 0; i < wordsSize-1; ++i) {
        for (j = i + 1; j < wordsSize; ++j) {
            if (isPreString(words[i],words[j])) {
                dp[j] = max(dp[j],dp[i] + 1);
            }
        }
    }
    // 从dp[]中选出最大值，即最长字符串链
    for (i = 0; i < wordsSize; ++i) {
        if (ret < dp[i]) {
            ret = dp[i];
        }
    }
    return ret;

}
