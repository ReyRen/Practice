//
//  强化练习03.cpp
//  Practice
//
//  Created by Rey Ren on 2017/10/19.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//

#include "iostream"
using namespace std;

class MyTest
{
public:
    MyTest(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    
    MyTest(int a, int b)
    {
        this->a = a;
        this->b = b;
        
        MyTest(a, b, 100);//这里产生一个匿名对象，如果没有人接的话，马上就析构，c是始终没有赋值的
    }
    ~MyTest()
    {
        printf("MyTest~:%d, %d, %d\n", a, b, c);
    }
    
protected:
private:
    int a;
    int b;
    int c;
    
public:
    int getC() const { return c; }
    void setC(int val) { c = val; }
};

int main()
{
    MyTest t1(1, 2);
    printf("c:%d", t1.getC()); //请问c的值是？
    system("pause");
    return 0;
}
