//
//  拷贝构造函数第四个应用场景.cpp
//  Practice
//
//  Created by Rey Ren on 2017/10/18.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//



#include "iostream"
using namespace std;


class Location01
{
public:
    Location01( int xx = 0 , int yy = 0 )
    {
        X = xx ;  Y = yy ;  cout << "Constructor Object.\n" ;
    }
    Location01( const Location01 & p )         //复制构造函数
    {
        X = p.X ;  Y = p.Y ;   cout << "Copy_constructor called." << endl ;
    }
    ~Location01()
    {
        cout << X << "," << Y << " Object destroyed." << endl ;
    }
    int  GetX () { return X ; }        int GetY () { return Y ; }
    private :   int  X , Y ;
} ;

void f ( Location01  p )
{
    cout << "Funtion:" << p.GetX() << "," << p.GetY() << endl ;
}

Location01 g()
{
    Location01 A(1, 2);
    return A;
}



//对象初始化操作 和 =等号操作是两个不同的概念
void mainobjplay01()
{
    //Location01 B;这里定义B了，所以执行了B的构造函数，但是底下那种方式就是提高速度的方式，不需要调用B的构造函数了
    //B = g();//40 =等号操作,就是将返回的匿名对象浅拷贝值给了B。注意=操作就是浅拷贝值
    
    Location01 B = g();//42 对象初始化操作    直接将g()返回的匿名对象转变为B对象，匿名对象会新开辟新的内存空间，应该存在栈区，但不知道。
    //如果返回的匿名对象，来初始化另外一个同类型的类对象，那么匿名对象会直接转成新的对象。。。
    //匿名对象的去和留，关键看，返回时如何接过来。
    cout<<"测试测试"<<endl;
}

int main__()
{
    mainobjplay01();

    return 0;
}




