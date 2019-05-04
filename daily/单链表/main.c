#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int date;
    struct Node *next;
}

Node * inr()
{
    Node *first=(Node *)malloc(sizeof(Node));
    first->next=NULL;
    return first;
}

int empty(Node *s)
{
    if(s->next==NULL) return 1;
    else return 0;
}

void  sdasdf(Node * s)
{
    Node *p=s->next;
    while (p!=NULL)
    {
        printf("%d",p->date);
        p=p->next;
    }
}

int length(Node *s)
{
    Node *p=s->next;
    int count=0;
    while (p!=NULL)
    {
        p=p->next;
        count++;
    }
    return count;
}

int locate(Node *s,int x)
{
     Node *p=s->next;
     int count=1;
     while (p!=NULL)
     {
         if(p->date==x) return count;
         p=p->next;
         count++;
     }
     return 0;
}

int get(Node *s,int i,Node a)
{
    Node *p=s->next;
    int count =1;
    while (p!=NULL&&count <i)
    {
        p=p->next;
        count ++;
    }
    if(p==NULL) {printf("Î»ÖÃ´íÎó\n" );return 0;}
    else {*a=p->date;return 1;}
}
int Insert(Node *s,int i,int x)
{
     Node *p=s,*a=NULL;
    int count =0;
    while (p!=NULL&&count <i-1)
    {
        p=p->next;
        count++;
    }
    if(p==NULL) {printf("Î»ÖÃ´íÎó\n" );return 0;}
    else
    {
        a=(Node *)malloc(sizeof(Node));
        a->date=x;
        a->next=p->next; p->next=s;
        return 1;
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
