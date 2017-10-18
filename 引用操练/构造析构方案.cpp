//
//  构造析构方案.cpp
//  Practice
//
//  Created by Rey Ren on 2017/10/3.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

class Test {
public:
    //构造函数，完成对象的初始化,无参构造函数，也是默认狗仔函数
    Test(){
        a = 10;
    }
    Test(int mya){//带参数的构造函数
        a = mya;
    }
    //赋值构造函数，也是拷贝构造函数
    Test(const Test& obj){
        
    }
private:
    int a;
};
int main01()
{
    //Test t1(10);//第一种调用有参构造方法的方式
    //Test t2 = 11;//会默认调用有参函数
    Test t3 = Test(12);//相当于我们手工调用构造函数
    
    return 0;
}
