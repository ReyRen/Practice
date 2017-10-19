//
//  C++对象管理模型.cpp
//  Practice
//
//  Created by Rey Ren on 2017/10/19.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//
/*
 C++类对象中的成员变量和成员函数是分开存储的
     成员变量：
         普通的成员变量：存储于对象中， 与struct变量有相同的内存布局和字节对齐方式
         静态成员变量：存储于全局数据区中
     成员函数：
         存储于代码段
 C++编译器对普通成员函数进行了内部处理
     this指针，谁调用了，内部转换用C语言定义的结构体，然后再这些成员函数中多加了参数，就是把这个结构体传进去了
     也就是说：c++中类的普通成员函数都隐士的包含一个指向当前对象的this指针
 */

#include "iostream"
using namespace std;


class C1
{
public:
    int i; //4
    int j; //4
    int k; //4
protected:
private:
}; //12

class C2
{
public:
    int i; //4
    int j; //4
    int k; //4
    
    static int m; //4
public:
    int getK() const { return k; } //4
    void setK(int val) { k = val; } //4
    
protected:
private:
}; //24 16 12

int main()
{
    C2 c1, c2;
    c1.getK();
    c2.getK();
    printf("sizeof(C1):%ld \n", sizeof(C1));//12
    printf("sizeof(C2):%ld \n", sizeof(C2));//12
    return 0;
}
