#include <stdio.h>
#include <stdlib.h>
typedef struct sd
{
    int date;
    struct sd *next;
}sd,*L;
int Initst(sd *s)//产生一个空栈
{
    s=NULL;
    return 0;
}

int push(sd *s,int e)
{
    struct sd *p;
    p=(sd *) malloc(sizeof(sd));
    p->date=e;
    p->next=s;
    s=p;
    return 1;
}

int Pop(sd *s,int *e)
{
    struct sd *p;
    if(s->date!=NULL) return 0;
    e=s->date;
    p=s;
    s=s->next;
    free(p);
    return 1;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
