//
//  Array.cpp
//  Practice
//
//  Created by Rey Ren on 2017/10/21.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//

#include "Array.hpp"
#include "iostream"
using namespace std;

Array::Array(int length)
{
    if (length < 0) {
        length = 0;
    }
    mLength = length;
    mySpace = new int[mLength];
}
Array::Array(const Array &obj)
{
    mLength = obj.mLength;
    mySpace = new int[mLength];
    for (int i = 0; i < mLength; i++) {
        mySpace[i] = obj.mySpace[i];
    }
}
int Array::length()
{
    return mLength;
}
void Array::setData(int index, int value)
{
    mySpace[index] = value;
}
int Array::getData(int index)
{
    return mySpace[index];
}
Array::~Array()
{
    mLength = -1;
    delete[] mySpace;//释放数组格式
}
//以下表示运算符重载函数
//从数组中拿元素
//int Array::operator[](int i)
//{
//    return mySpace[i];
//}
int& Array::operator[](int i)
{
    return mySpace[i];//因为要当左值所以必须返回元素本身,返回引用相当于c++编译器帮我们取了mySpace[i]的地址
}

//实现等号操作符重载
Array& Array::operator=(Array &a1)
{
    int i = 0;
    if (this->mySpace != NULL) {//因为构造函数中已经分配内存了
        delete [] mySpace;
        this->mLength = 0;
    }
    //a1的所有元素给了a3
    this->mLength = a1.mLength;//这里的等号并没有用重载函数，因为编译器会根据两边的数据类型进行判断是用系统的还是自定义的
    this->mySpace = new int[a1.mLength];
    for (i = 0; i < this->mLength; i++) {
        mySpace[i] = a1[i];//因为[]已经重载了
    }
    return *this;//c++编译器会自动在这里取成地址的
}

//实现==
bool Array::operator==(Array &a2)
{
    if (this->mLength != a2.mLength) {
        return false;
    }
    for (int i = 0; i < this->mLength; i++) {
        if (this->mySpace[i] != a2[i]) {
            return false;
        }
    }
    return true;
}

bool Array::operator!=(Array &a2)
{
    return !(*this == a2);
}
//当返回的不是引用的时候就会返回匿名对象，给匿名对象的时候也会调用拷贝构造函数。不能返回局部变量的引用，因为指向的内存空间被析构了，但是直接赋值给int double这种的话，也是可以的，因为会将值放在寄存器或者其他地方，一旦进行=赋值后，就消失所以不能赋值给引用。也就是说虽然是析构了，但是这个值还是有的，只是放在了没有地址的寄存器或者其他中，一旦=操作就释放了，所以其实是得不到的，但是直接给了一个变量，那可以。反正把这几个场景记住
