//
//  友元函数.cpp
//  Practice
//
//  Created by Rey Ren on 2017/10/20.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//

#include <stdio.h>
#include "iostream"
using namespace std;

class A
{
public:
    A()
    {
        a1 = 100;
        a2 = 200;
    }
    int getA1()
    {
        return this->a1;
    }
    friend void setA1(A *p, int a1);//声明这个函数是这个类的好朋友,友元函数实际上是全局函数
protected:
private:
    int a1;
    int a2;
};

void setA1(A *p, int a1)
{
    p->a1 = a1;
}

int main()
{
    A mya1;
    mya1.getA1();//获取私有成员
    return 0;
}
