//
//  指针的引用.cpp
//  Practice
//
//  Created by Rey Ren on 2017/9/26.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//

#include "iostream"

using namespace std;

struct Teacher
{
    char name[64];
    int age;
};
/*
int getTe(Teacher **myp)
{
    Teacher *p = (Teacher *)malloc(sizeof(Teacher));
    if (p == NULL)
    {
        return -1;
    }
    memset(p, 0, sizeof(Teacher));
    p->age = 33;
    *myp = p;
    return 0;
}
 */
//指针的引用
int getTe(Teacher* &myp)
{
    myp = (Teacher *)malloc(sizeof(Teacher));
    myp->age = 34;
   
    return 0;
}
int main()
{
    Teacher *p = NULL;
    //getTe(&p);
    getTe(p);//myp就相当于是p的别名
    printf("age:%d \n",p->age);
    return 0;
}
