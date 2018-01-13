//
//  LinkList.h
//  LinkList
//
//  Created by Holmes on 2018/1/10.
//  Copyright © 2018年 Holmes. All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h

#include <stdio.h>
#include <stdlib.h>


/*
    单向链表
 */
//常用参数
//数据的最大空间
#define Maxsize 100
#define ElemType  int

typedef struct LNode{
    ElemType data;
    struct LNode *next;
} LinkList;

//创建链表
//头插法
LinkList* createLinkHead(LinkList *L);
//尾插法
LinkList* createLinkTail(LinkList *L);
//插入操作，将值e插入到单链表的第i个位置
int insertLinkList(LinkList *L, ElemType e, int pos);
//删除第i个元素的操作节点
int deleteLinkList(LinkList *L, int pos);
//修改第i个元素的操作节点
int alterLinkListFromPos(LinkList *L, int pos, ElemType e);
//修改第一个值为e的元素的值
int alterLinkListFromValue(LinkList *L, ElemType, ElemType ex);
//得出元素的长度
int lengthOfLinklist(LinkList *L);
//得出第i个元素的值
LinkList* getValueLinklistOfPos(LinkList *L, int pos);
//遍历链表
void mapLinklist(LinkList *L);


#endif /* LinkList_h */
