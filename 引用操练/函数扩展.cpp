//
//  函数扩展.cpp
//  Practice
//
//  Created by Rey Ren on 2017/10/2.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//

#include <stdio.h>
#include "iostream"
using namespace std;

//默认参数规则:如果默认参数出现，后面的就都必须使用默认参数
//当函数重载遇上默认函数参数会出现二义性
void printAB(int x = 3)
{
    printf("x:%d\n", x);
}

//定义一个数组类型
typedef int MYTYPEArray[10];
MYTYPEArray a1;//= int a[10];

//定义一个数组类型指针
typedef int (*MYArrayP)[10];//数组指针，MYArrayP + 1 跳40个字节
MYArrayP myarray = NULL;
//myarray = &a1;

int func(int a)
{
    return a;
}

typedef int (*PFUNC)(int a);//定义了指向函数的指针

//函数名就是函数的入口地址，函数名就是指针变量
int main()
{
    printAB(2);
    printAB();
    
    PFUNC p = func;
    
    return 0;
}
