//
//  ks02.c
//  Practice
//
//  Created by Rey Ren on 2017/10/4.
//  Copyright © 2017年 Rey Ren. All rights reserved.
//
/*
 编写一个业务函数，实现按行读取文件。把内容按照第三种内存模型打包数据传出，把行数通过函数参数传出。
 函数原型有两个，任意选择其一
 要求1：请自己任意选择一个接口（函数），并实现功能；70分
 要求2：编写测试用例。30分
 要求3：自己编写内存释放函数
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **readFile1(const char *pfilename/*in*/, int *lineNum/*in out*/);
int readFile2(const char *pfilename/*in*/, char ***p/*out*/, int *lineNum/*int out*/);

int main00001()
{
    char *pfilename = "/Users/reyren/Desktop/test.txt";
    int lineNum = 0;
    int i = 0;
    char **res = NULL;
    res = readFile1(pfilename, &lineNum);
    if (res == NULL) {
        return -1;
    }
    for (i = 0; i < lineNum; i++) {
        printf("%s\n",res[i]);
    }
    return 0;
}
char **readFile1(const char *pfilename/*in*/, int *lineNum/*in out*/)
{
    FILE *fp = NULL;
    char **pRes = NULL;
    char *p = NULL;
    int lineNUM = 0;
    int stLen = 0;
    int i = 0;
    char buf[4096]={0};
    if(pfilename == NULL || lineNum == NULL)
    {
        printf("filename or linenum error:\n");
        goto END;
    }
    fp = fopen(pfilename, "r");
    if(fp == NULL)
    {
        printf("fp errir:\n");
        goto END;
    }
    while(!feof(fp))
    {
        memset(buf, 0, sizeof(buf));
        p = fgets(buf, 4096, fp);
        if(p  == NULL)//如果回车到下一行保存退出的话会报fgets的一个错误
        {
            break;
        }else
        {
            
            lineNUM++;
        }
    }
    pRes = (char **)malloc(lineNUM * sizeof(char *));
    if(pRes == NULL)
    {
        printf("malloc error:");
        goto END;
    }
    fseek(fp, 0L, SEEK_SET);
    while(!feof(fp))
    {
        memset(buf, 0, sizeof(buf));
        p = fgets(buf, 4096, fp);
        if(p  == NULL)
        {
            printf("fgets error:");
            goto END;
        }
        stLen = strlen(buf);
        pRes[i] = (char *)malloc((stLen + 1)*sizeof(char));
        if(pRes == NULL)
        {
            printf("malloc error:");
            goto END;
        }
        strcpy(pRes[i], buf);
        i++;
    }
END://这段代码是正常结束也会执行的
    if(fp != NULL)
    {
        fclose(fp);
    }
    *lineNum = lineNUM;
    return pRes;
}
