//
//  全局函数和普通函数.cpp
//  Practice
//
//  Created by Rey Ren on 2017/10/20.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//
/*
 函数的返回值如果没有用引用那么返回的就是匿名对象，用匿名对象进行对象的初始化，那么就是匿名对象直接转换成初始化的对象
 Person p1 = add();
 如果用匿名对象不是初始化对象，就是进行等号操作
 Person p1;
 p1 = add();
 
 */

#include <stdio.h>
#include "iostream"

using namespace std;

class Test
{
public:
    Test(int a, int b)
    {
        this->a = a;//注意为什么this->是因为this是调用者取地址传进来的，所以this其实是个结构体指针
        this->b = b;
    }
    int getA()
    {
        return a;
    }
    int getB()
    {
        return b;
    }
    Test& add(Test &t2)//如果不加引用的话，返回的就是个匿名对象，现在为了返回的还是调用者本身
    {
        this->a = this->a + t2.getA();
        this->b = this->b + t2.getB();
        return *this;//this其实就是调用者（t1）的地址，然后*取回元素状态
    }
protected:
private:
    int a;
    int b;
};
//全局函数
//如果把全局函数转成成员函数，少了一个操作数，通过this指针被隐藏
Test add(Test &t1, Test &t2)
{
    Test t3(t1.getA() + t2.getA(), t1.getB() + t2.getB());
    return t3;//创建了一个匿名对象
}

int main()
{
    Test t1(1,2);//Test(&t1, 1, 2);
    Test t2(3, 4);
    Test t3 = add(t1, t2);//匿名对象的赋值
    t1.add(t2);//---->add(&t1, t2);
    
    return 0;
}
