//
//  类的封装.cpp
//  Practice
//
//  Created by Rey Ren on 2017/10/3.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//

#include <stdio.h>
#include "iostream"
using namespace std;

//圆的例子
class Circle
{
public:
    double r;
    double s;
public:
    double getR()
    {
        return r;
    }
    void setR(double val)
    {
        r = val;
    }
public:
    double getS()//增减功能的时候，是在修改类
    {
        s = 3.14f*r*r;
        return s;
    }
};

int main()
{
    Circle c1, c2;//通过类定义对象
    c1.setR(10);//给对象传值
    cout << "圆的面积是:" << c1.getS() << endl;
    return  0;
}
