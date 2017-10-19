//
//  copy构造函数规则研究.cpp
//  Practice
//
//  Created by Rey Ren on 2017/10/18.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//

#include "iostream"
using namespace std;

/*
 1.如果写了copy构造函数，那么编译器就不会再提供无参构造函数
 2.如果写了有参或无参构造函数，编译器也不会提供无参构造函数
 
 */

class Test
{
public:
protected:
private:
    int a;
    int b;
};

int main()
{
    
    
    return 0;
}
