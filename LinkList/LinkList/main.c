//
//  main.c
//  LinkList
//
//  Created by Holmes on 2018/1/8.
//  Copyright © 2018年 Holmes. All rights reserved.
//

#include <stdio.h>
#include "OrderList.h"
#include "LinkList.h"
#include "DDLinklist.h"

//线性表
//线性表测试
void orderListFunc();
void linkListFunc();
void DDLinkListFunc();


int main(int argc, const char * argv[]) {

    //orderListFunc();
    
    //linkListFunc();
    
    DDLinkListFunc();
    
    return 0;
}

//双向链表测试
void DDLinkListFunc() {
    DDLinklist *L;
    L = createDDLinklist(L);
    mapDDLinklist(L);
    
    printf("length: %d \n", getLengthDDNode(L));
    
    int i = 4;
    printf("index: %d , number: %d \n", i, getDDNodeOfIndex(L, i)->data);
    
    alterDDNodeOfindex(L, 3, 222);
    mapDDLinklist(L);
    
    preInsertDDNode(L, 3, 111);
    beInsertDDNode(L, 4, 333);
    mapDDLinklist(L);
    for (int i = 0; i < 3; i++) {
        deleteDDNode(L, 3);
        printf("after delete %d:", i);
        mapDDLinklist(L);
    }
}

//单链表测试
void linkListFunc() {
    LinkList *L;
    //头插法
//    L = createLinkHead(L);
    //尾插法
    L = createLinkTail(L);
    mapLinklist(L);
    
    printf("list length: %d\n", lengthOfLinklist(L));
    int p = 4;
    //修改第i个位置的数据
    alterLinkListFromPos(L, 4, 222);
    mapLinklist(L);
    
    //修改数值第一个数值为e的值
    alterLinkListFromValue(L, 222, 40);
    
    //查询第p个位置的数据
    LinkList *g = getValueLinklistOfPos(L, p);
    printf("pos: %d, data: %d\n", p, g->data);
    
    //前插
    insertLinkList(L, 111, 4);
    mapLinklist(L);
    
    //删除
    deleteLinkList(L, 4);
    mapLinklist(L);

}

//线性表测试
void orderListFunc() {
    Sqlist L;

    int a[] = {1,2,3,4,5,6,7,8};
    createList(&L, a, 8);

    mapList(&L);
    
    printf("is empty: %d \n", isEmpty(&L));
    
    printf("得到第%d个元素的值是:%d \n", 4, getElemOfN(&L, 4));
    
    printf("get length: %d \n", lengthOfList(&L));
    
    printf("find  %d 's postion is %d \n", 7, findNumberList(&L, 7));
    
    insertDataList(&L, 4, 11);
    mapList(&L);
    
    deleteDataOfN(&L, 5);
    mapList(&L);

    
}
