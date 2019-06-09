
#define MAXISIZE 100
#define OK 1
#define OVERLOW 0
#define ERROR 0
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10000//顺序表可能达到的最大长度
#define ElemType Book
#define Status int
typedef struct book
{
    char no[20];
    char name[50];
    float price;
}Book;
typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
}SqList;
Status InitList(SqList *L);
Status GetElem(SqList L,int i,ElemType *e);
int LocateElem(SqList L,ElemType *e);
Status ListInsert(SqList *L,int i,ElemType e);
Status ListDelete(SqList *L,int i);
