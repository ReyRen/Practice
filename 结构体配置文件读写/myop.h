//
//  myop.h
//  Practice
//
//  Created by Rey Ren on 2017/10/16.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef _INC_MY_OP_H
#define _INC_MY_OP_H

#ifdef  __cplusplus
extern "C" {
#endif /* myop_h */
    
typedef struct _Teacher
{
    int infoId;
    char name[64];
    int age;
    char student[1024];
}Teacher;
//添加老师
int AddTeacher(char *pfileName, Teacher *pTe);
    
//显示老师
int ModifyTeacher(char *pfileName, Teacher *pTe);
    
#ifdef  __cplusplus
}
#endif

#endif
