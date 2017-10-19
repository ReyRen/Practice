//
//  深copy浅copy.cpp
//  Practice
//
//  Created by Rey Ren on 2017/10/18.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//

#include "iostream"
using namespace std;


class Name
{
public:
    Name(const char *pname)
    {
        size = strlen(pname);
        pName = (char *)malloc(size + 1);
        strcpy(pName, pname);
    }
    Name(Name &obj)
    {
        //用obj来初始化自己
        pName = (char *)malloc(obj.size + 1);
        strcpy(pName, obj.pName);
        
        size = obj.size;
    }
    ~Name()
    {
        cout<<"开始析构"<<endl;
        if (pName!=NULL)
        {
            free(pName);
            pName = NULL;
            size = 0;
        }
    }
    
protected:
private:
    char *pName;
    int size;
};

void playObj()
{
    Name obj1("obj1.....");
    Name obj2 = obj1;//这里会调用obj2的系统默认的拷贝构造函数（如果自己没有写的话），而不是匿名函数，因为并不是函数返回类
                        //注意：如果调用系统的拷贝构造函数，就是将obj1栈中的地址复制到了obj2属性的栈中，所以他们其实指向了同一块儿堆或其他内存空间，然后释放一个在释放另一个的是就ggs
    cout<<"业务操作。。。5000"<<endl;
    
}
int main01010101()
{
    playObj();
    return 0;
}
