//
//  OrderList.c
//  LinkList
//
//  Created by Holmes on 2018/1/8.
//  Copyright © 2018年 Holmes. All rights reserved.
//

#include "OrderList.h"



//创建表
void createList (Sqlist *L, int *a , int n) {
    //线性表不需要分配空间。
    //L = (Sqlist*)malloc(sizeof(ElemType));
    for ( int i = 0; i < n; i++) {
        L->data[i] = a[i];
    }
    L->length = n;
}
//初始化空表
void initList(Sqlist *L) {
   // L = (Sqlist*)malloc(sizeof(ElemType));
    L->length = 0;
}
//销毁表
void destroyList(Sqlist *L) {
    L->length = 0;
}
//判断是否表空
int isEmpty(Sqlist *L) {
    return L->length == 0;
}
//计算表长度
int lengthOfList(Sqlist *L) {
    return L->length;
}
//输出表中数据（遍历顺序表）
void mapList(Sqlist *L) {
    for (int i = 0 ; i < L->length; i++) {
        printf("%d \n", L->data[i]);
    }
}
//得到表中第N个元素的值
int getElemOfN(Sqlist *L, int n) {
    if (n < 0 || n >= L->length) {
        return  0;
    } else {
        n = L->data[n-1];
        return n;
    }
}
//判断某数据是否在顺序表中的位置
int findNumberList(Sqlist *L , ElemType e) {
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == e) {
            return i+1;
        }
    }
    
    return 0;
}
//在一个位置上插入一个数据（前插）
int insertDataList(Sqlist *L, int pos, ElemType e) {
    if (pos < 0 || pos > L->length) {
        return 0;
    }
    
    for (int i = L->length; i >= pos; i--) {
        L->data[i] = L->data[i-1];
    }
    L->data[pos-1] = e;
    L->length++;
    
    return 1;
}
//删除某个位置上的一个数据
void deleteDataOfN(Sqlist *L, int n) {
    for (int i = n; i < L->length; i++) {
        L->data[i-1] = L->data[i];
    }
    L->length--;
}
