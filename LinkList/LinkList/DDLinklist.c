//
//  DDLinklist.c
//  LinkList
//
//  Created by Holmes on 2018/1/10.
//  Copyright © 2018年 Holmes. All rights reserved.
//

#include "DDLinklist.h"


//创建
DDLinklist *createDDLinklist(DDLinklist *L) {
    L = (DDLinklist*)malloc(sizeof(DDLinklist));
    L->data = 999;
    L->next = NULL;
    
    DDLinklist *p = L;
    int inputNum;
    
    printf("please input: \n");
    scanf("%d", &inputNum);
    while (inputNum != -1) {
        DDLinklist *t = (DDLinklist*)malloc(sizeof(DDLinklist));
        t->data = inputNum;
        t->prior = p;
        t->next = p->next;
        p->next = t;
        p = p->next;
        scanf("%d", &inputNum);
    }
    return L;
    
}
//遍历
void mapDDLinklist(DDLinklist *L) {
    DDLinklist *t = L;
    while (t->next != NULL) {
        printf("%d ", t->next->data);
        t = t->next;
    }
    printf("\n");
}
//获得第i个元素的节点
DDLinklist *getDDNodeOfIndex(DDLinklist* L, int loc) {
    DDLinklist *t = L;
    if (loc < 0 || loc > getLengthDDNode(L)) {
        return NULL;
    }
    int i = 0;
    while (i < loc) {
        i++;
        t = t->next;
    }
    return t;
}
//获得链表的长度
int getLengthDDNode(DDLinklist* L) {
    int sum = 0;
    DDLinklist *t = L;
    while (t->next != NULL) {
        sum++;
        t = t->next;
    }
    return sum;
}
//修改第i个元素的节点
int alterDDNodeOfindex(DDLinklist* L, int loc, ElemType e) {
    if (loc < 0 || loc > getLengthDDNode(L)) {
        return 0;
    }
    DDLinklist *t = getDDNodeOfIndex(L, loc);
    t->data = e;
    return 1;
}
//前插
int preInsertDDNode(DDLinklist *L, int loc, ElemType e) {
    if (loc < 0 || loc > getLengthDDNode(L)) {
        return 0;
    }
    
    DDLinklist *pNode = (DDLinklist*)malloc(sizeof(DDLinklist));
    pNode->data = e;
    
    DDLinklist *t = getDDNodeOfIndex(L, loc);
    
    pNode->next = t;
    pNode->prior = t->prior;
    t->prior->next = pNode;
    t->prior = pNode;
    
    return 1;
}
//后插
int beInsertDDNode(DDLinklist *L, int loc, ElemType e) {
    if (loc < 0 || loc > getLengthDDNode(L)) {
        return 0;
    }
    
    DDLinklist *pNode = (DDLinklist*)malloc(sizeof(DDLinklist));
    pNode->data = e;
    
    DDLinklist *t = getDDNodeOfIndex(L, loc);
    
    pNode->next = t->next;
    pNode->prior = t;
    t->next->prior = pNode;
    t->next = pNode;
    
    return 1;
}
//删除
int deleteDDNode(DDLinklist *L, int loc) {
    if (loc < 0 || loc > getLengthDDNode(L)) {
        return 0;
    }
    DDLinklist *pNode = getDDNodeOfIndex(L, loc);
    pNode->prior->next = pNode->next;
    pNode->next->prior = pNode->prior;
    free(pNode);
    return 1;
}
