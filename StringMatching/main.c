//
//  main.c
//  StringMatching
//  create by lw


#include <stdio.h>
#include <string.h>

//算法需求：字符串匹配模式
//具体：两个字符串--主串S，模式串T，得到模式串在主串中第一次出现的位置。不存在返回999
//S: abacabab
//T: abab
//得到字符串的位置(4)。
#define MAXSIZE  100


char S[] = "aaaaaaab"; // (10)
char T[] = "aaab";

//KMP算法的next数组
int next[MAXSIZE];

//BF(Brute-Force)暴力匹配算法 返回当前的位置
int BFMatchingFunc(char S[], char T[]);
//KMP算法
int KMPMatchingFunc(char S[], char T[]);
//没有做过优化处理
int KMPMatchingFunc2(char S[], char T[]);

int main(int argc, const char * argv[]) {
    int  ret1 = BFMatchingFunc(S, T);
    int  ret2 = KMPMatchingFunc2(S, T);
    printf("BF:s,t匹配发生在: %d \n", ret1);
    printf("KMP:s,t匹配发生在: %d \n", ret2);

    return 0;
}

//暴力求解思路：
//首先进行一一比对，如果发生不匹配，T串首位与S串的下一个进行循环比对。
int BFMatchingFunc(char S[], char T[]) {
    int i = 0 , j = 0;
    //得到两个串的长度。
    int SL = (int)strlen(S);
    int TL = (int)strlen(T);
    //大循环进行在两个串的长度范围进行
    while (i < SL && j < TL) {
        if (S[i] == T[j]) {
            //相等i，j右移
            i++; j++;
        } else {
            //不相等，i进行回溯并+1，j=0
            i = i-j+1;
            j = 0;
            //这里做一下优化
            //当不相等的时候，如果新的i和加上串T的长度大于串S的长度，直接返回不存在。（进一步的优化步骤）
            if (i + TL > SL) {
                return 999;
            }
        }
    }
    
    return i - j;
}


//KMP算法
//主要是为了模式串T不匹配是的回溯，根据模式串的前后特点，生成模式串next回溯特点数组，利用这个数组进行一定量的回溯。

//得到KMP数组的算法
void getKMPNext(char T[]) {
    //l是前缀相同的长度
    int l = -1, i = 0;
    next[0] = -1;
    int TL = (int)strlen(T);
    while (i < TL) {
        if (l == -1 || T[i] == T[l]) {
            l++;
            i++;
            next[i] = l;
        } else {
            l = next[l];
        }
    }
}

//KMP数组的意义：
//KMP数组代表的每位数字的最大前缀的长度。譬如说：当比较到第n位的时候发生了不匹配的时候，我们会根据数组进行回溯到指定位置，回溯的位数是看之前的串（不包括当前的这一位）最大公共前后缀的位数，说明这几位比较是多余的。
int KMPMatchingFunc(char S[], char T[]) {
    getKMPNext(T);   //将KMP数组初始化一下
    
    int i = 0, j = 0;
    //得到两个串的长度。
    int SL = (int)strlen(S);
    int TL = (int)strlen(T);
    
    while (i < SL && j < TL) {
        if (j == -1 || S[i] == T[j]) {
            i++;
            j++;
        } else {
            //优化
            if ( i - j + 1 + TL > SL ) {
                return 999;
            }
            j = next[j];
        }
    }
    return i-j;
}


//没有做过优化处理
int KMPMatchingFunc2(char S[], char T[]) {
    getKMPNext(T);   //将KMP数组初始化一下
    
    int i = 0, j = 0;
    //得到两个串的长度。
    int SL = (int)strlen(S);
    int TL = (int)strlen(T);
    
    while (i < SL && j < TL) {
        if (j == -1 || S[i] == T[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j >= TL) {
        return i-j;
    } else {
        return 999;
    }
}


