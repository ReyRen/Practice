//
//  ks04.c
//  Practice
//
//  Created by Rey Ren on 2017/10/18.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//
/*
 4、从键盘中输入一个不超过40个字符的字符串，再输入3个位数（每次删除一个字符），删除对应 位数的字符，然后输出删除指定字符后的字符串。
 输入：hellokityManGood
 3  6   9
 helokityManGood
 
 heloktyManGood
 
 heloktyMnGood
 
 输出：heloktyMnGood
 要求1：编写业务接口并实现核心功能 70分
 要求2：写出测试用例 30分
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int delAlpa(char *p, int pos)
{
    int i = 0;
    int len = 0;
    
    if (p == NULL) {
        return -1;
    }
    
    len = strlen(p);
    //Pos位置从0开始
    for (i = pos; i < len; i++) {
        p[i] = p[i + 1];//把\0赋前面了
    }
    //p[len - 1] = '\0';
    return 0;
}

int main_04()
{
    int ret = 0;
    char str[] = "hellokityManGood";
    ret = delAlpa(str, 3);
    if (ret != 0) {
        printf("func delAlpa() err:%d \n", ret);
    }
    ret = delAlpa(str, 6);
    if (ret != 0) {
        printf("func delAlpa() err:%d \n", ret);
    }
    ret = delAlpa(str, 9);
    if (ret != 0) {
        printf("func delAlpa() err:%d \n", ret);
    }
    
    
    return 0;
}
