//
//  引用当左值.cpp
//  Practice
//
//  Created by Rey Ren on 2017/9/26.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//

#include <iostream>
using namespace std;


int j()
{
    static int a = 10;//static修饰变量的时候是一个状态变量
    a++;
    return a;//main中j() = 100;是报错的，因为j()的运算结果是一个数值，没有内存地址，不能当左值;
}
//被调用的函数当左值的时候，必须返回引用
int& j1()
{
    static int a = 10;//static修饰变量的时候是一个状态变量
    a++;
    return a;//main中j1() = 100；是可以的，因为返回的是变量本身，也就是把a的内存地址给返回出去了，然后c++编译器一看，这是个引用，就直接自动执行*p操作
}

int getAA()
{
    int a;
    a = 10;
    return a;
}

int& getAA2()
{
    int a;
    a = 10;
    return a;
}

int main02()
{
    int a1 = 0;
    int a2 = 0;
    a1 = getAA();//10
    a2 = getAA2();//虽然返回引用但是把这个值存到了变量中了，所有不会乱码
    int &a3 = getAA2();//返回的值因为没有内存块儿但是返回了数字所以放到了寄存器或者内存中临时的没有地址，一旦完成赋                            值则这块 儿内存消失，所以打印a3是乱码，因为没有指向了。
    
    return 0;
}
int g1(int *p)
{
    *p = 100;
    return *p;
}
int& g2(int *p)
{
    *p = 100;
    return *p;
}
int main03()
{
    int a1 = 10;
    a1 = g2(&a1);
    //用引用去接收函数的返回值，是不是乱码，关键是看返回的空间是不是背回收了
    int &a2 = g2(&a1);//不是乱码了，因为内存空间没有消失，a2是一个地址，如果不用打印执行%d的话。
    return 0;
}
