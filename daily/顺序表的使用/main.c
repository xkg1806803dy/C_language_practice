#include <stdio.h>
#include <stdlib.h>
#define maxsize 100
//Япад
typedef struct
{
    int date[maxsize];
    int length;
}seqlist;

void CreatList(seqlist *l,int a[],int n)
{
    if(n>maxsize) return;
    for(int i=0;i<n;i++)
       l->date[i]=a[i];
    l->length=n;
}

void printflist(seqlist *l)
{
    for(int i=0 ;i<l->length;i++)
        printf("%d",l->date);
}

int  Loacte(seqlist *l,int x)
{
    for(int i=0; i<l->length;i++)
        if(l->date[i]==x)  return i+1;
    return 0;
}

void Insert(seqlist *l,int i,int x)
{
    if(l->length>=maxsize) return;
    for (int j=l->length;j>=i;j--)
        l->date[j]=l->date[j-1];
    l->date[i-1]=x;
    l->length++;
}

int main()
{
    int r[5]={1,2,3,4,5},i,x;
    seqlist l;
    CreatList(&l,r,5);
    printflist(&l);
    Insert(&l,2,8);
    printflist(&l);
    return 0;
}
