//
//  ArrayTest.cpp
//  Practice
//
//  Created by Rey Ren on 2017/10/21.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//

#include <stdio.h>
#include "iostream"
#include "Array.hpp"

using namespace std;

int main()
{
    Array a1(10);
    for (int i = 0; i < a1.length(); i++){
        //a1.setData(i, i);
        a1[i] = i;//a1.operator[](i) = i
    }
    for (int i = 0; i <a1.length(); i++) {
        printf("Array %d: %d\n",i,a1.getData(i));
    }
    Array a2 = a1;//copy constructor
    
    for(int i=0; i<a2.length(); i++)
    {
        //printf("array %d: %d\n", i, a2.getData(i));
        printf("array %d: %d\n", i, a2[i]);//[]是个方法，所以相当于a2.operator[]
    }
    
    //功能2
    Array a3(20);//已经分配内存了
    a2 = a3 = a1;
    //a2 = void
    //a3.operator=(a1);
    
    
    //a1.operator==(a2);
    if (a1 == a2)  //功能3
    {
        printf("相等\n");
    }
    else
    {
        printf("不相等\n");
    }
    
    
    if (a1 != a2) //功能4
    {
        printf("不相等\n");
    }
    else
    {
        printf("相等\n");
    }
    
    return 0;
}
