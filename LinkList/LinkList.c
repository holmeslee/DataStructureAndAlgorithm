//
//  LinkList.c
//  LinkList
//
//  Created by Holmes on 2018/1/10.
//  Copyright © 2018年 Holmes. All rights reserved.
//

#include "LinkList.h"

//创建链表
//头插法
LinkList* createLinkHead(LinkList *L) {
    LinkList *t;
    ElemType inputNum;
    //先初始化一个空的链表
    L = (LinkList*)malloc(sizeof(LinkList));
    L->data = 999;  //999代表的是头
    L->next = NULL;
    //开始添加
    printf("please input:\n");
    scanf("%d", &inputNum);
//    循环添加，只到“-1”结束
    while (inputNum != -1) {
        t = (LinkList*)malloc(sizeof(LinkList));
        t->data = inputNum;
        t->next = L->next;
        L->next = t;
        scanf("%d", &inputNum);
    }
    return L;
}
//尾插法
LinkList* createLinkTail(LinkList *L) {
    LinkList *t, *r;
    ElemType inputNum;
    //先初始化一个空的链表
    L = (LinkList*)malloc(sizeof(LinkList));
    L->data = 999;  //999代表的是头
    r = L;
    //开始添加
    printf("please input:\n");
    scanf("%d", &inputNum);
    //    循环添加，只到“-1”结束
    while (inputNum != -1) {
        t = (LinkList*)malloc(sizeof(LinkList));
        t->data = inputNum;
        r->next = t;
        r = t;
        scanf("%d", &inputNum);
    }
    r->next = NULL;
    return L;
}
//插入操作，将值e插入到单链表的第i个位置前面
int insertLinkList(LinkList *L, ElemType e, int pos) {
    LinkList *t = L;
    int i = 0;
    if (pos > lengthOfLinklist(L) || pos < 0) {
        return 0;
    }
    // 循环跳出，pos=i;
    while (pos > i+1) {
        t = t->next;
        i++;
    }
    LinkList *s = (LinkList*)malloc(sizeof(LinkList));
    s->data = e;
    s->next = t->next;
    t->next = s;
    return 1;
}
//删除第i个元素的操作节点
int deleteLinkList(LinkList *L, int pos) {
    if (pos > lengthOfLinklist(L) || pos < 0) {
        return 0;
    }
    LinkList *p = getValueLinklistOfPos(L, pos-1);
    p->next = p->next->next;
    free(p->next);
    return 1;
}
//修改第i个元素的操作节点
int alterLinkListFromPos(LinkList *L, int pos, ElemType e) {
    if (pos > lengthOfLinklist(L) || pos < 0) {
        return 0;
    }
    LinkList *t = getValueLinklistOfPos(L, pos);
    t->data = e;
    return 1;
}
//修改第一个值为e的元素的值
int alterLinkListFromValue(LinkList *L, ElemType e, ElemType ex) {
    LinkList *t = L;
    while (1) {
        if (t->next == NULL) {
            return 0;
        } else {
            if (t->data == e) {
                t->data = ex;
                return 1;
            } else {
                t = t->next;
            }
        }
    }
}
//得出元素的长度
int lengthOfLinklist(LinkList *L) {
    int l = 0;
    LinkList *t = L;
    while(t->next != NULL) {
        l++;
        t = t->next;
    }
    return l;
}
//得出第i个元素的值
LinkList* getValueLinklistOfPos(LinkList *L, int pos) {
    LinkList *t = L;
    int i = 0;
    if (pos > lengthOfLinklist(L) || pos < 0) {
        return 0;
    }
    while (pos > i) {
        i++;
        t = t->next;
    }
    return t;
}

void mapLinklist(LinkList *L) {
    LinkList *t = L;
    while (t->next != NULL) {
        printf("%d ", t->next->data);
        t = t->next;
    }
    printf("\n");
}
