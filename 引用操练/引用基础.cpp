//
//  引用基础.cpp
//  Practice
//
//  Created by Rey Ren on 2017/9/26.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//

#include "iostream"

using namespace std;

int main01()
{
    int a = 10;
    int &b = a;//b就是a的别名
    
    b = 14;
    printf("a:%d b:%d\n", a, b);//14 14
    
    
    
    return 0;
}
