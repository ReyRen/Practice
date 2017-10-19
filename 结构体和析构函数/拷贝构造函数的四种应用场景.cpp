//
//  拷贝构造函数的四种应用场景.cpp
//  Practice
//
//  Created by Rey Ren on 2017/10/18.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//
/*
 void f(Location p){}
 void main{
     Location A(1,2)
     f(A)
 }
 用实参A初始化方法f中的p那么就是调用了拷贝构造函数
 
 */

#include <stdio.h>
#include "iostream"

using namespace std;

class AA
{
public:
    AA() //无参构造函数 默认构造函数
    {
        cout<<"我是构造函数，自动被调用了"<<endl;
    }
    AA(int _a) //无参构造函数 默认构造函数
    {
        a = _a;
    }
    //     AA(const AA &obj2)
    //     {
    //         cout<<"我也是构造函数，我是通过另外一个对象obj2，来初始化我自己"<<endl;
    //         a = obj2.a + 10;
    //     }
    ~AA()
    {
        cout<<"我是析构函数，自动被调用了"<<endl;
    }
    void getA()
    {
        printf("a:%d \n", a);
    }
protected:
private:
    int a;
};

//单独搭建一个舞台
void ObjPlay01()
{
    AA a1; //变量定义
    
    //赋值构造函数的第一个应用场景
    //我用对象1 初始化 对象2
    AA a2 = a1; //定义变量并初始化
    
    a2 = a1; //用a1来=号给a2 编译器给我们提供的浅copy
}

//单独搭建一个舞台
void ObjPlay02()
{
    AA a1(10); //变量定义
    
    //赋值构造函数的第一个应用场景
    //我用对象1 初始化 对象2
    AA a2(a1); //定义变量并初始化
    
    //a2 = a1; //用a1来=号给a2 编译器给我们提供的浅copy
    a2.getA();
}

int main0101()
{
    ObjPlay02();
    system("pause");
    return 0;
}
