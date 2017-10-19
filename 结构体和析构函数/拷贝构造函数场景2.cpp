//
//  拷贝构造函数场景2.cpp
//  Practice
//
//  Created by Rey Ren on 2017/10/18.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//


#include "iostream"
using namespace std;


class Location
{
public:
    Location( int xx = 0 , int yy = 0 )
    {
        X = xx ;  Y = yy ;  cout << "Constructor Object.\n" ;
    }
    Location( const Location & p )         //复制构造函数
    {
        X = p.X ;  Y = p.Y ;   cout << "Copy_constructor called." << endl ;
    }
    ~Location()
    {
        cout << X << "," << Y << " Object destroyed." << endl ;
    }
    int  GetX () { return X ; }        int GetY () { return Y ; }
    private :   int  X , Y ;
} ;

void f ( Location  p )
{
    cout << "Funtion:" << p.GetX() << "," << p.GetY() << endl ;
}

void mainobjplay()
{
    Location A ( 1, 2 ) ;
    f ( A ) ;
}

int main_0303()
{
    mainobjplay();
    system("pause");
    return 0;
}


