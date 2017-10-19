//
//  demo01.cpp
//  Practice
//
//  Created by Rey Ren on 2017/10/17.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//

#include <stdio.h>
#include "iostream"

using namespace std;

class Test{
public:
    Test(int _a = 0, int _b = 0){
        p = (char *)malloc(100);
        strcpy(p, "111111");
        a = _a;
        b = _b;
        cout << "我是有参的构造函数" << endl;
    }
    Test(){
        cout << "我是构造函数，自动被调动了" << endl;
    }
    ~Test(){//析构函数没参数与返回
        cout << "我是析构函数，自动被调用了" << endl;
        if(p != NULL){
            free(p);
        }
    }
protected:
private:
    int a;
    int  b;
    char *p;
};

//单独搭建一个舞台
void ObjPlay()
{
    //Test t1(1, 2);
    //Test t1 = (1 ,2);
    Test t1 = Test(1,2);//用对象放问属性不管是.还是->，属性必须是public的
    cout << "展示t1的生命周期" << endl;
}

int main_0008()
{
    ObjPlay();
    
    return 0;
}

