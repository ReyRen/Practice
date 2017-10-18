//
//  const引用.cpp
//  Practice
//
//  Created by Rey Ren on 2017/9/27.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//

#include <stdio.h>
#include "iostream"

using namespace std;

int main01()
{
    int a  = 10;
    const int &b = a;
    //b = 11;通过引用修改a，修改不了
    
    
    return 0;
}
struct Teahcer1
{
    char name[64];
    int age;
};

void printTe(const Teahcer1 &t)
{
    //t.age = 11;//const让变量所指的内存空间拥有只读属性
    
}
int main()
{
    Teahcer1 t1;
    t1.age = 33;
    printTe(t1);
    
    const int b = 10;//可以是因为c++编译器为b（其实不是b）分配了个额外的地址
    //int &a = 19;是错的
    const int& a = 19;//正确，分配了一个额外的空间给使用
    
}
