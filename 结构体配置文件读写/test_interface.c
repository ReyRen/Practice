//
//  test_interface.c
//  Practice
//
//  Created by Rey Ren on 2017/10/16.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//界面层的业务逻辑

#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "myop.h"

#define  DB_sid            "oracle_sid"
#define  DB_User        "appuser"
#define  DB_PassWord    "appuser"
#define     CFG_FILENAME    "c:/cfg.ini"

void main_menu()
{
    printf("\n1 Test AddTeacher(测试保存老师信息)    ");
    printf("\n2 Test ModifyTeacher(测试显示老师信息)    ");
    printf("\n0 exit(0)        (程序退出)        ");
    printf("\nplease enter your choice:[1/2/0]: ");
    return;
}


int  Test_AddTeacher()
{
    int rv = 0;
    char *pfileName = "/Users/reyren/Desktop/teacherinfo.ini";
    Teacher t1;
    memset(&t1, 0, sizeof(Teacher));
    t1.infoId = 1;
    t1.age = 11;
    strcpy(t1.name, "name");
    strcpy(t1.student, "s1,s2,s3");
    
    rv = AddTeacher(pfileName, &t1);
    if (rv != 0) {
        printf("func AddTeacher() err:%d \n",rv);
        return rv;
    }
    printf("读写配置项绿灯测试通过\n");
    
End:
    return rv;
    
}

int  Test_ModifyTeache()
{
    
    int rv = 0;
    char *pfileName = "/Users/reyren/Desktop/teacherinfo.ini";
    Teacher t1;
    memset(&t1, 0, sizeof(Teacher));
    t1.infoId = 1;
    rv = ModifyTeacher(pfileName, &t1);
    if(rv != 0)
    {
        printf("func ModifyTeacher() err:%d \n", rv);
        return rv;
    }
    printf("\n读写配置项绿灯测试通过\n");
    
End:
    return rv;
    
}

int  main_()
{
    int        rv = 0;
    int        choice = 0;
    
    for(;;)
    {
        main_menu();
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                Test_AddTeacher();   break;
            case 2:
                Test_ModifyTeache();   break;
            case 0:
                exit(0);
            default:
                exit(0);
        }
    }
    
End:
    return rv;
    
}
