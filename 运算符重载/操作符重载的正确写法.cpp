//
//  操作符重载的正确写法.cpp
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
    friend ostream& operator<<(ostream &out, Complex &c1);
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
    Complex operator+(Complex &c2)
    {
        Complex tmp(a + c2.a, this->b + c2.b);
        return tmp;
    }
    //通过成员函数完成前置--
    Complex& operator--()
    {
        this->a--;
        this->b--;
        return *this;
    }
    //通过成员函数完成前置--
    Complex& operator++()
    {
        this->a++;
        this->b++;
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
    //通过类成员函数完成后置--
    Complex operator++(int)
    {
        Complex tmp = *this;
        this->a++;
        this->b++;
        return tmp;
    }
    
private:
    int a;
    int b;
};

void main61()
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

ostream& operator<<(ostream &out, Complex &c1)
{
    //out<<"12345，生活真是苦"<<endl;
    out<<c1.a<<" + "<<c1.b<<"i "<<endl;
    return out;
}
int main()
{
    Complex c1(1, 2), c2(3, 4);
    int a = 10;
    char *p = "addddd";
    cout<<"a"<<a<<endl;
    cout<<"p"<<p<<endl;
    
    //Complex自定义类型 。a + bi ab ba
    cout<<c1;
    
    //全局函数
    //cout<<c1;
    //operator<<(cout, c1);
    
    //1
    //类成员函数
    //因为你没有方法拿到cout这个类的源码。。。。AOP C++
    //cout.operator<<(c1);
    
    //2 支持链式编程
    cout<<c1<<"abcc";
    
    //函数返回值当左值，要求返回一个引用。。。。。
    
    //cout.operator<<(c1).operator<<("abcd");
    
    //s<<"abcd"
    
    //s cout.operator<<(c1);
    
    //s.operator<<("abcd");
    
    
    
    return 0;
    
}




