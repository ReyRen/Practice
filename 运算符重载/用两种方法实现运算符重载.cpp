//
//  用两种方法实现运算符重载.cpp
//  Practice
//
//  Created by Rey Ren on 2017/10/21.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//

#include "iostream"
using namespace std;

//a + bi //复数
class Complex
{
public:
    friend Complex operator+(Complex &c1, Complex &c2);
    friend Complex operator*(Complex &c1, Complex &c2);
    friend Complex& operator++(Complex &c1); //前置++
    friend Complex operator++(Complex &c1, int);
    Complex(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    void printCom()
    {
        cout<<a<<" + "<<b<<"i "<<endl;
    }
    //通过类成员函数完成-操作符重载
    Complex operator-(Complex &c2)
    {
        Complex tmp(a - c2.a, this->b - c2.b);
        return tmp;
    }
    //通过成员函数完成前置--
    Complex& operator--()
    {
        this->a--;
        this->b--;
        return *this;
    }
    
    //通过类成员函数完成后置--
    Complex operator--(int)
    {
        Complex tmp = *this;
        this->a--;
        this->b--;
        return tmp;
    }
    
private:
    int a;
    int b;
};

Complex operator+(Complex &c1, Complex &c2)
{
    Complex tmp(c1.a + c2.a, c1.b + c2.b);
    return tmp;
}

Complex operator*(Complex &c1, Complex &c2)
{
    Complex tmp(c1.a*c2.a, c1.b*c2.b);
    return tmp;
}

//前置++
Complex& operator++(Complex &c1)
{
    c1.a ++;
    c1.b ++;
    return c1;
}

//后置++ 全局函数
Complex operator++(Complex &c1, int)
{
    Complex tmp = c1;
    c1.a++;
    c1.b++;
    return tmp;
}

void main()
{
    
    Complex c1(1, 2), c2(3, 4);
    
    //全局函数方法去实现操作符重载
    //1 承认操作符重载是一个函数
    //2 根据操作数，1个操作数 2个操作数，完成函数的参数
    //3 根据函数原型，实现需要业务
    //Complex c31 = operator+(c1, c2);
    Complex c3 = c1 + c2;
    
    //用类成员函数实现-运算符重载
    Complex c4 = c1 - c2;
    c4.printCom();
    //c1.operator-(c2);
    
    {
        //问题1 根据类型
        int a = 10, b = 1;
        int c = a + b;
    }
    
    //前置++ 全局函数
    ++c1;
    c1.printCom();
    
    //前置-- 成员函数
    --c1;
    c1.printCom();
    //c1.operator--()
    
    //后置++ 全局函数
    c1++; //operator++(c1);
    c1.printCom();
    
    //后置-- 类成员函数
    c1--;  //c1.operator--()
    c1.printCom();
    
    
    
    
    
    system("pause");
}



