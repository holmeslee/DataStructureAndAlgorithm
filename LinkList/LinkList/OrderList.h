//
//  OrderList.h
//  LinkList
//
//  Created by Holmes on 2018/1/8.
//  Copyright © 2018年 Holmes. All rights reserved.
//

#ifndef OrderList_h
#define OrderList_h


/*
    顺序表
    静态分配，使用的数组进行
 */
//常用参数
//数据的最大空间
#define Maxsize 100
#define ElemType  int



#include <stdio.h>
#include <stdlib.h>

typedef struct {
    ElemType data[Maxsize];  //顺序表的元素
    int length;              //顺序表当前的长度
}Sqlist;


//创建表
void createList(Sqlist *L, int *a , int n);
//初始化表
void initList(Sqlist *L);
//销毁表
void destroyList(Sqlist *L);
//判断是否表空
int isEmpty(Sqlist *L);
//计算表长度
int lengthOfList(Sqlist *L);
//输出表中数据（遍历顺序表）
void mapList(Sqlist *L);
//得到表中第N个元素的值
int getElemOfN(Sqlist *L, int n);
//判断某数据是否在顺序表中的位置
int findNumberList(Sqlist *L , ElemType e);
//在一个位置上插入一个数据（前插）
int insertDataList(Sqlist *L, int pos, ElemType e);
//删除某个位置上的一个数据
void deleteDataOfN(Sqlist *L, int n);

#endif /* OrderList_h */
