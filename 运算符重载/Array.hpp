//
//  Array.hpp
//  Practice
//
//  Created by Rey Ren on 2017/10/21.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//

#ifndef Array_hpp
#define Array_hpp

#include <stdio.h>
class Array
{
public:
    Array(int length);
    Array(const Array &obj);
    int length();
    void setData(int index, int value);
    int getData(int index);
    ~Array();
protected:
private:
    int mLength;
    int *mySpace;
public:
    int& operator[](int i);
    //实现等号操作符运算重载
    Array& operator=(Array &a1);
    //实现==操作
    bool operator==(Array &a2);
    bool operator!=(Array &a2);
};

#endif /* Array_hpp */
