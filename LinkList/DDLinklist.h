//
//  DDLinklist.h
//  LinkList
//
//  Created by Holmes on 2018/1/10.
//  Copyright © 2018年 Holmes. All rights reserved.
//

#ifndef DDLinklist_h
#define DDLinklist_h

#include <stdio.h>
#include <stdlib.h>

/*
    DoubleDirectionLinklist
    双向链表
 */
//常用参数
//数据的最大空间
#define Maxsize 100
#define ElemType  int

typedef struct DDNode {
    ElemType data;
    struct DDNode *prior, *next;
}DDLinklist;

//创建
DDLinklist *createDDLinklist(DDLinklist *L);
//遍历
void mapDDLinklist(DDLinklist *L);
//获得第i个元素的节点
DDLinklist *getDDNodeOfIndex(DDLinklist* L, int loc);
//获得链表的长度
int getLengthDDNode(DDLinklist* L);
//修改第i个元素的节点
int alterDDNodeOfindex(DDLinklist* L, int loc, ElemType e);
//前插
int preInsertDDNode(DDLinklist *L, int loc, ElemType e);
//后插
int beInsertDDNode(DDLinklist *L, int loc, ElemType e);
//删除
int deleteDDNode(DDLinklist *L, int loc);

#endif /* DDLinklist_h */
