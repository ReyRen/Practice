//
//  子类类继承对类访问属性的影响.cpp
//  Practice
//
//  Created by Rey Ren on 2017/10/27.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//

//类的继承方式对子类对外访问属性影响

#include <cstdlib>
#include <iostream>

using namespace std;

class A
{
private:
    int a;
protected:
    int b;
public:
    int c;
    
    A()
    {
        a = 0;        b = 0;        c = 0;
    }
    
    void set(int a, int b, int c)
    {
        this->a = a;        this->b = b;        this->c = c;
    }
};

class B : public A
{
public:
    void print()
    {
        cout<<"a = "<<a;
        cout<<"b = "<<b;
        cout<<"c = "<<endl;
    }
};

class C : protected A
{
public:
    void print()
    {
        cout<<"a = "<<a;
        cout<<"b = "<<b;
        cout<<"c = "<<endl;
    }
};

class D : private A
{
public:
    void print()
    {
        cout<<"a = "<<a;
        cout<<"b = "<<b<<endl;
        cout<<"c = "<<c<<endl;
    }
};

int main_01()
{
    
    A aa;
    B bb;
    C cc;
    D dd;
    
    aa.c = 100;
    bb.c = 100;
    cc.c = 100;
    dd.c = 100;
    
    aa.set(1, 2, 3);
    bb.set(10, 20, 30);
    cc.set(40, 50, 60);
    dd.set(70, 80, 90);
    
    bb.print();
    cc.print();
    dd.print();
    
    
    system("pause");
    return 0;
}

