#include <stdio.h>
#include <stdlib.h>
#define max 10
typedef struct edg
{
    int adjvex;
    struct edg *next;
}edg;  //表头结点

typedef struct  ver
{
    char data;
    edg *first;
}ver;

typedef struct alg
{
    ver adjlist[max];
    int vexnum,arcnum;
}alg;

int choos(char ch,alg *sa)
{
    int i;
    for(i=0;i<sa->vexnum;i++)
        if(ch==sa->adjlist[i].data) break;
    return i-1;
}

void creat(alg *s)
{
    printf("顶的个数,总边数:");
    scanf("%d,%d",&s->vexnum,&s->arcnum);
    int i;
    printf("各个顶点：");
    for(i=0;i<s->vexnum;i++)
    {
        scanf("%c",&s->adjlist[i].data);
        s->adjlist[i].first=NULL;
    }
    printf("个点之间的关系：") ;
    for(i=0;i<s->arcnum;i++)
    {
        char v1,v2;
        int x,y;
        printf("%c\t",s->adjlist[i].data);
        scanf("%c%c",&v1,&v2);
        x=choos(v1,s);   y=choos(v2,s);
        edg *p1,*p2;
        p1=(edg *)malloc(sizeof(edg));
        p2=(edg *)malloc(sizeof(edg));
        p1->adjvex=y;
        printf("%c\n",s->adjlist[x].data);
        printf("%c\n",s->adjlist[y].data);
        p1->next=s->adjlist[i].first;
        s->adjlist[i].first=p1;
        p2->adjvex=x;
        p2->next=s->adjlist[i].first;
        s->adjlist[i].first=p2;
    }
}
int vise[max]={0};
void sdef( alg g,int v)
{
    edg *p=NULL;
    int j;
    printf("%c",g.adjlist[v].data); vise[v]=1;
    p=g.adjlist[v].first;
    while(p!=NULL)
    {
        j=p->adjvex;
        if(vise[j]==0) sdef(g,j);
        p=p->next;
    }
}
//广度
struct sd
{
    int froat,rear;
    int asd[max];
};
int vise2[max]={0};
void gde(alg g,int v)
{
    struct sd pdd;
    edg *p=NULL;
    pdd.froat=0; pdd.rear=0;  pdd.asd=NULL;

}
void jid(struct sd s,int q)
{
    s.asd[s.rear]=q;
    s.rear++;
}

int main()
{
    alg s;
    creat(&s);
    sdef(s,0);
    return 0;
}

