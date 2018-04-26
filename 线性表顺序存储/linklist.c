//
//  linklist.c
//  线性表顺序存储
//
//  Created by Rey Ren on 2018/4/24.
//  Copyright © 2018年 whoami.company. All rights reserved.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linklist.h"

typedef struct _tag_LinkList
{
    LinkListNode header;
    int length;
    
}TLinkList;


LinkList * LinkList_Create()
{
    TLinkList * ret = (TLinkList *)malloc(sizeof(TLinkList));
    if (ret == NULL) {
        return NULL;
    }
    ret->header.next = NULL;
    ret->length = 0;
    return ret;
}

void LinkList_Destory(LinkList * list)
{
    if (list == NULL) {
        return;
    }
    free(list);
    return;
}

void LinkList_Clear(LinkList * list)
{
    TLinkList * tlist = NULL;
    if (list == NULL) {
        return;
    }
    tlist = (TLinkList *)list;
    tlist->length = 0;
    tlist->header.next = NULL;
    return;
}

int LinkList_Length(LinkList * list)
{
    TLinkList * tlist = (TLinkList *)list;
    if (tlist == NULL) {
        return -1;
    }
    return tlist->length;
}

int LinkList_Insert(LinkList * list, LinkListNode * node, int pos)
{
    int i = 0;
    TLinkList *tList = NULL;
    LinkListNode *current = NULL;
    tList = (TLinkList *)list;
    current = &tList->header;//LinkListNode中的header并不是指针，只是在这个结构体中有一个next指针而已.所以必须取地址表示将头节点的地址传给current
    for (i = 0; i < pos && (current->next != NULL); i++) {
        current = current->next;
    }
    node->next = current->next;
    current->next = node;
    tList->length ++;
    return 0;
}

LinkListNode * LinkList_Get(LinkList * list, int pos)
{
    int i = 0;
    TLinkList *tList = NULL;
    LinkListNode *current = NULL;
    LinkListNode *ret = NULL;
    tList = (TLinkList *)list;
    
    if (list == NULL || pos < 0 || pos >= tList->length) {
        return NULL;
    }
    current = &tList->header;
    for (i = 0; i < pos && (current->next != NULL); i++) {
        current = current->next;
    }
    ret = current->next;
    return ret;
}

LinkListNode * LinkList_Delete(LinkList * list, int pos)
{
    int i = 0;
    TLinkList *tList = NULL;
    LinkListNode *current = NULL;
    LinkListNode *ret = NULL;
    tList = (TLinkList *)list;
    
    if (list == NULL || pos < 0 || pos >= tList->length) {
        return NULL;
    }
    current = &tList->header;
    for (i = 0; i < pos && (current->next != NULL); i++) {
        current = current->next;
    }
    ret = current->next;
    
    current->next = ret->next;
    tList->length--;
    
    return ret;
}
