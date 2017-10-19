//
//  C++对象管理模型2.cpp
//  Practice
//
//  Created by Rey Ren on 2017/10/19.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//

#include "iostream"
using namespace std;

class Test
{
public:
    Test(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    void getA() //getA(this);内部都会在成员方法上加上this参数，然后这个this参数其实也即是对象结构体取地址
    {
        printf("a:%d \n", this->a);
        printf("a:%d \n", a);
    }
    
protected:
private:
    int a;
    int b;
};
int main()
{
    Test t(1,2); //====>Test(this, 1, 2);===>Test(&t, 1, 2);内部推演， t就是对象
    return 0;
}
