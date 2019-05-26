#include <stdio.h>
#include <stdlib.h>
struct er
{
    int num;
    struct er *lch,*rch;
}erc;

void choose(struct er *s,int snum)
{
    struct er *p;
    if(s!=NULL)
    {
        if(snum>s->num )
        {
            choose(s->rch,snum);
            p=(struct er *)malloc(sizeof(struct er));
            s->rch=p;
            p->num=snum;
            p->lch=NULL;
            p->rch=NULL;
        }
        else
        {
            choose(s->lch,snum);
            p=(struct er *)malloc(sizeof(struct er));
            s->lch=p;
            p->lch=NULL;
            p->num=snum;
            p->rch=NULL;
        }
    }
}
void  create(struct er *s)
{
    struct er *p,*p1;
    p=s;
    p=(struct er *)malloc(sizeof(struct er));
    scanf("%d",&p->num);
    int s1=p->num,s2;
    while(scanf("%d",&s2)!=EOF&&s2!=-20)
    {
        choose(p,s2);
    }
    /*while(scanf("%d",&s2)!=EOF&&s2!=-20)
    {
        if(s2>s1)
        {
            if(p->rch!=NULL)
            {

                p1=(struct er *)malloc(sizeof(struct er));
            }
            else
            {
                p1=p->rch;
            p1=(struct er *)malloc(sizeof(struct er));
            p1->num=s2;
            }
            p1->lch=NULL;
            p1->rch=NULL;
        }
        else
        {
            p1->lch;
            p1=(struct er *)malloc(sizeof(struct er));
            p1->num=s2;
            p1->lch=NULL;
            p1->rch=NULL;
            p=p1;
        }
    }*/
}
void midlist(struct er *s)
{
    if(s!=NULL)
    {
        midlist(s->lch);
        printf("%d",s->num);
        midlist(s->rch);
    }
}
int main()
{
    struct er erc;
    create(&erc);
    midlist(&erc);
    return 0;
}
