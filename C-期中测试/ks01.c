//
//  ks01.c
//  Practice
//
//  Created by Rey Ren on 2017/10/3.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//
/*
 1 编写一个业务函数，实现字符串（前后各有三个空格，单词前后也均有空格）
 "   i am student, you are teacher   " ，
 各个单词首字符大写，结果如下"   i am student,  you are teacher   " ，
 要求1：实现所有接口  70
 要求2：写出测试程序  30
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int GetString(const char *str1 /*in*/, char *str2 /*in*/);
int GetString_Adv(const char *str1/*in*/, char **str2 /*out*/);
int GetString_Adv_Free1(char *str2);
int GetString_Adv_Free2(char **str2);

int main001()
{
//    int ret = 0;
//    const char *str1 = "   i am student, you are teacher   ";
//    char buf[1024] = {0};
//    ret = GetString(str1, buf);
//    if (ret == 0) {
//        printf(buf);
//    }
    int ret = 0;
    const char *str1 = "   i am student, you are teacher   ";
    const char *str2 = NULL;
    ret = GetString_Adv(str1, &str2);
    if (ret == 0) {
        printf("%s\n",str2);
    }
    
    return 0;
}

int GetString(const char *str1 /*in*/, char *str2 /*in*/)
{
    int ret = 0;
    int i = 0;
    char *p1 = NULL;
    char *p2 = NULL;
    
    if(str1 == NULL || str2 == NULL){
        ret = -1;
        return ret;
    }
    int len = strlen(str1);
    strcpy(str2, str1);
    p1 = str2 + 1;
    p2 = str2;
    for(i = 0; i < len && ((*p1) != NULL); i++)
    {
        if((isalpha(*p1)) && (isspace(*p2))){
            *p1 = *p1 - 32;
        }
        p2 = p1;
        p1++;
    }
    return ret;
}
int GetString_Adv(const char *str1/*in*/, char **str2 /*out*/)
{
    int ret = 0;
    int i;
    int len;
    char *p1 = NULL;
    char *p2 = NULL;
    char *ptmp = NULL;
    if(str2 == NULL || str1 == NULL)
    {
        ret = -1;
        return ret;
    }
    len = strlen(str1);
    ptmp = (char *)malloc((len + 1)*sizeof(char));
    if(ptmp == NULL)
    {
        ret = -2;
        return ret;
    }
    memset(ptmp, 0, (len + 1)*sizeof(char));
    strcpy(ptmp, str1);
    p1 = ptmp + 1;
    p2 = ptmp;
    for(i = 0; i < len && ((*p1) != NULL); i++)
    {
        if((isalpha(*p1)) && (isspace(*p2))){
            *p1 = *p1 - 32;
        }
        p2 = p1;
        p1++;
    }
    *str2 = ptmp;
    return ret;
}
int GetString_Adv_Free1(char *str2)
{
    if (str2 == NULL) {
        return -1;
    }
    free(str2);
    str2 = NULL;
    return 0;
}
int GetString_Adv_Free2(char **str2)
{
    char *tmp = NULL;
    if (str2 == NULL) {
        return -2;
    }
    tmp = *str2;
    if (tmp != NULL) {
        free(tmp);
        *str2 = NULL;
        return 0;
    }
    return -3;
}
