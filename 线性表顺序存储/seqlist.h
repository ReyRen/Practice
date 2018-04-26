//
//  seqlist.h
//  C++demo10
//
//  Created by Rey Ren on 2018/4/24.
//  Copyright © 2018年 whoami.company. All rights reserved.
//

#ifndef seqlist_h
#define seqlist_h

typedef void SeqList;//it means that can return any addresses
typedef void SeqListNode;

SeqList * SeqList_Create(int capacity);

void SeqList_Destory(SeqList * list);

void SeqList_clear(SeqList * list);

int SeqList_Length(SeqList * list);

int SeqList_Capacity(SeqList * list);

int SeqList_Insert(SeqList * list, SeqListNode * node, int pos);

SeqListNode * SeqList_Get(SeqList * list, int pos);

SeqListNode * SeqList_Delete(SeqList * list, int pos);

#endif /* seqlist_h */
