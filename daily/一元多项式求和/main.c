#include <stdio.h>
#include <stdlib.h>
typedef struct nb
{
    int xis;//系数
    int zs;//指数
    struct nb * next;
}nb;

nb *add (nb * a,nb *b);
nb *creat();
void daying(nb *s);

int main()
{
    nb *a=NULL,*b=NULL;
    a=creat(); daying(a);
    b=creat(); daying(b);
    a=add(a,b);
    printf("结果是:");
    daying(a);
    return 0;
}

nb *creat()
{
    nb *s=NULL,*r=NULL,*first=NULL;
    int xis,zx;
    first=( nb *)malloc(sizeof(nb));
    r=first;
    printf("输入系数和指数：");
    scanf("%d,%d",&xis,&zx);
    while(xis!=0)
    {
        s=(nb *)malloc(sizeof(nb));
        s->xis=xis;s->zs=zx;
        r->next=s;  r=s;
        scanf("%d,%d",&xis,&zx);
    }
    r->next=NULL;
    return first;
}

nb * add(nb * a,nb *b)
{
    nb * pre=a, *p=pre->next;
    nb* qre=b, *q=qre->next;
    nb *sd=NULL;
    while(p!=NULL&&q!=NULL )
    {
        if(p->zs<q->zs)
        {
            pre=p; p=p->next;
        }
        else if (p->zs>q->zs)
        {
            sd=q->next;
            pre->next=q;
            q->next=p;
            q=sd;
        }
        else
        {
            p->xis=p->xis+q->xis;
            if(p->xis==0)
            {
                pre->next=p->next;
                free(p);
                p=pre->next;
            }
            else {pre=p; p=p->next;}
            qre->next=q->next;
            free(q);
            q=qre->next;
        }
    }
    if(q!=NULL) pre->next=q;
    free(b);
    return a;
}
void daying(nb * s)
{
    nb * p=s->next;
    if(p==NULL)  printf("%dx%d",p->xis,p->zs);
    p=p->next;
    while(p!=NULL)
    {
        if(p->xis>0)
            printf("+%dx%d",p->xis,p->zs);
        else
            printf("-%dx%d",p->xis,p->zs);
        p=p->next;
    }
    printf("\n");
}
