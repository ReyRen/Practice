//
//  运算符重载.cpp
//  Practice
//
//  Created by Rey Ren on 2017/10/20.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//

#include <stdio.h>
#include "iostream"
using namespace std;

class Complex
{
public:
    friend Complex operator+(Complex &c1, Complex &c2);//通过友元函数实现符号重载
    Complex(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    void printCom()
    {
        cout << "a:" << a << "b" << b << "i"<<endl;
    }
protected:
private:
    int a;
    int b;
};
//通过全局函数完成加对象
//    Complex add(Complex &c1, Complex &c2)
//    {
//        Complex c3(c1.a + c2.a, c1.b + c2.b);
//        return c3;
//    }
Complex operator+(Complex &c1, Complex &c2)
{
    Complex c3(c1.a + c2.a, c1.b + c2.b);
    return c3;
}

int main()
{
    {
        int a = 0;
        int b = 0;
        int c = a + b;
        //对于基础类型，编译器已经知道如何进行加减
    }
    Complex c1(1,2), c2(3,4);
    //为什么要有操作重载
    //用户自定义类型，编译器不知道类型如何进行加减
    //Complex c3 = add(c1, c2);//返回的是匿名对象，如果返回的是引用，就不是匿名函数了
    //Complex c3 = operator+(c1, c2);
    //运算符重载的本质就是通过函数实现的
    Complex c3 = c1 + c2;
    return 0;
}
