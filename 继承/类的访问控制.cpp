//
//  类的访问控制.cpp
//  Practice
//
//  Created by Rey Ren on 2017/10/26.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//

#include <stdio.h>
#include "iostream"
using namespace std;

/*
 private:修饰的成员变量成员属性在类的内部能使用
 public: 修饰的成员变量和成员函数，能再类的内部用也能在类的外部用
 protected: 修饰的成员变量和成员函数，在类的内部能使用，但是在类的外部不能被使用,但是在子类中能调用，出了子类和父类的花括号就调不上了
 */
class Parent
{
public:
    Parent(int a = 0, int b = 0, int c = 0)
    {
        
    }
    int c;
protected:
    int b;
private:
    int a;
};
//子类从父类公有继承
class Child : public Parent
{
public:
    void  print()
    {
        cout << "b:" << b << "c:" << c << endl;
    }
protected:
private:
};

int main()
{
    Child c1;
    c1.c = 10;
    
    return 0;
}
