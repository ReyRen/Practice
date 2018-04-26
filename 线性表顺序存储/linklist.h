//
//  linklist.h
//  线性表顺序存储
//
//  Created by Rey Ren on 2018/4/24.
//  Copyright © 2018年 whoami.company. All rights reserved.
//

#ifndef linklist_h
#define linklist_h

typedef void LinkList;

typedef struct _tag_LinkListNode
{
    struct _tag_LinkListNode * next;
}LinkListNode;

LinkList * LinkList_Create();

void LinkList_Destory(LinkList * list);

void LinkList_Clear(LinkList * list);

int LinkList_Length(LinkList * list);

int LinkList_Insert(LinkList * list, LinkListNode * node, int pos);

LinkListNode * LinkList_Get(LinkList * list, int pos);

LinkListNode * LinkList_Delete(LinkList * list, int pos);


#endif /* linklist_h */
