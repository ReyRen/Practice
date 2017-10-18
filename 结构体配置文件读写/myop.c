//
//  myop.c
//  Practice
//
//  Created by Rey Ren on 2017/10/16.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//应用层的业务逻辑

#include "myop.h"
#include "cfg_op.h"

//添加老师
int AddTeacher(char *pfileName, Teacher *pTe)
{
    int ret;
    //准备写配置文件的关键字，根据ID动态构建
    char Teacher_InfoID[128];
    char Teacher_Name[128];
    char Teacher_Age[128];
    char Teacher_StudentInfo[1024];
    char infoId[128];
    char infoAge[128];
    
    sprintf(Teacher_InfoID, "%s%d", "Teacher_InfoID_", pTe->infoId);
    sprintf(Teacher_Name, "%s%d", "Teacher_Name_", pTe->infoId);
    sprintf(Teacher_Age, "%s%d", "Teacher_Age_", pTe->infoId);
    sprintf(Teacher_StudentInfo, "%s%d", "Teacher_StudentInfo_", pTe->infoId);
    sprintf(infoId, "%d", pTe->infoId);//把int型变量转成buf
    sprintf(infoAge, "%d", pTe->age);
    
    ret = SetCfgItem(pfileName, Teacher_InfoID, infoId, strlen(infoId));
    if (ret != 0) {
        printf("func WriteCfgItem() err: %d \n",ret);
        return ret;
    }
    ret = SetCfgItem(pfileName, Teacher_Name, pTe->name, strlen(pTe->name));
    if (ret != 0) {
        printf("func WriteCfgItem() err: %d \n",ret);
        return ret;
    }
    ret = SetCfgItem(pfileName, Teacher_Age, infoAge, strlen(infoAge));
    if (ret != 0) {
        printf("func WriteCfgItem() err: %d \n",ret);
        return ret;
    }
    ret = SetCfgItem(pfileName, Teacher_StudentInfo, pTe->student, strlen(pTe->student));
    if (ret != 0) {
        printf("func WriteCfgItem() err: %d \n",ret);
        return ret;
    }
    return 0;
}

//显示老师
int ModifyTeacher(char *pfileName, Teacher *pTe)
{
    int ret;
    char Teacher_InfoID[128];
    char Teacher_Name[128];
    char Teacher_Age[128];
    char Teacher_StudentInfo[1024];
    char infoId[128] = {0};//防止系统没给加上/0
    char infoAge[128] = {0};
    int tmpLen = 0;
    
    sprintf(Teacher_InfoID, "%s%d", "Teacher_InfoID_", pTe->infoId);
    sprintf(Teacher_Name, "%s%d", "Teacher_Name_", pTe->infoId);
    sprintf(Teacher_Age, "%s%d", "Teacher_Age_", pTe->infoId);
    sprintf(Teacher_StudentInfo, "%s%d", "Teacher_StudentInfo_", pTe->infoId);
//    sprintf(infoId, "%d", pTe->infoId);//把int型变量转成buf
//    sprintf(infoAge, "%d", pTe->age);
    
    ret = GetCfgItem(pfileName, Teacher_InfoID, infoId, &tmpLen);
    pTe->infoId = atoi(infoId);//转成int
    if (ret != 0) {
        printf("func GetCfgItem() err: %d\n", ret);
        return ret;
    }
    ret = GetCfgItem(pfileName, Teacher_Name, pTe->name, &tmpLen);
    if (ret != 0) {
        printf("func GetCfgItem() err: %d\n", ret);
        return ret;
    }
    ret = GetCfgItem(pfileName, Teacher_Age, infoAge, &tmpLen);
    pTe->age = atoi(infoAge);
    if (ret != 0) {
        printf("func GetCfgItem() err: %d\n", ret);
        return ret;
    }
    ret = GetCfgItem(pfileName, Teacher_StudentInfo, pTe->student, &tmpLen);
    if (ret != 0) {
        printf("func GetCfgItem() err: %d\n", ret);
        return ret;
    }
    return 0;
}

