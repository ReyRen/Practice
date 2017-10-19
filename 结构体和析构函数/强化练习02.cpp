//
//  强化练习02.cpp
//  Practice
//
//  Created by Rey Ren on 2017/10/18.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//

//对象做函数参数
//1 研究拷贝构造
//2 研究构造函数，析构函数的调用顺序

//总结 构造和析构的调用顺序

#include "iostream"
using namespace std;

class ABCD
{ //this（）
public:
    ABCD(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        printf("ABCD() construct, a:%d,b:%d,c:%d  \n", this->a, this->b, this->c);
    }
    ~ABCD()
    {
        printf("~ABCD() construct,a:%d,b:%d,c:%d  \n", this->a, this->b, this->c);
    }
    int getA()
    {
        return this->a;
    }
protected:
private:
    int a;
    int b;
    int c;
};


class MyE
{
public:
    MyE():abcd1(1,2,3),abcd2(4,5,6),m(100)
    {
        cout<<"MyD()"<<endl;
    }
    ~MyE()
    {
        cout<<"~MyD()"<<endl;
    }
    MyE(const MyE & obj):abcd1(7,8,9),abcd2(10,11,12),m(100)
    {
        printf("MyD(const MyD & obj)\n");
    }
    
protected:
    //private:
public:
    ABCD abcd1; //c++编译器不知道如何构造abc1
    ABCD abcd2;
    const int m;
    
};

int doThing(MyE mye1)
{
    printf("doThing() mye1.abc1.a:%d \n", mye1.abcd1.getA());
    return 0;
}

int run2()
{
    MyE myE;
    doThing(myE);//实参给形参初始化，会调用拷贝构造函数
    return 0;//最后析构实参的析构函数，然后又是先后创建的先析构
}

//
int run3()
{
    printf("run3 start..\n");
    
    ABCD abcd = ABCD(100, 200, 300);//这种方式是返回了一个匿名对象，然后匿名对象直接给了abcd了而不是又执行了一个copy构造函数（这就是c++提高了速度的一大原因）
    //若直接调用构造函数哪
    //想调用构造函数对abc对象进行再复制，可以吗？
    //在构造函数里面调用另外一个构造函数，会有什么结果？
    //ABCD(400, 500, 600); //临时对象的生命周期，弄出来后发现没用，就直接析构了
    printf("run3 end\n");
    return 0;
}

int main()
{
    run2();
    //run3();
    system("pause");
    return 0;
}


