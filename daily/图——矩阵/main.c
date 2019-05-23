#include <stdio.h>
#include <stdlib.h>
#define maxint -1
#define max  100
struct sdd
{
    char  ch[max];
    int  gg[max][max];
    int   dot,arc;
}pdd,*sa;

void mmd(struct sdd * sa)
{
    int choose(char ch);
    int i,n;
    char ch1,ch2;
    printf("顶的个数,总边数:");
    scanf("%d,%d",&sa->dot,&sa->arc);
    for(i=0;i<sa->dot;i++)
        for(n=0;n<sa->dot;n++)
           sa->gg[i][n]=maxint;
    printf("各个顶点：");
    for(i=0;i<sa->dot;i++)
       scanf("%c",&sa->ch[i]);
    printf("个点之间的关系：");
    for(i=0;i<sa->arc+1;i++)// 有向
    {
        scanf("%c%c",&ch1,&ch2);
        scanf("%d",&sa->gg[choose(ch1)][choose(ch2)]);
    }
    /*for(i=0;i<sa->arc+1;i++)// 无向
    {
        int num1;
        int a1,a2;
        scanf("%c%c",&ch1,&ch2);
        scanf("%d",&num1);
        a1=choose(ch1);  a2=choose(ch2);
        sa->gg[a1][a2]=num1;
        sa->gg[a2][a1]=num1;
        printf("%d  %d\n",sa->gg[a1][a2],sa->gg[a2][a1]);
    }*/
}
int choose(char ch)
{
    int i;
    for(i=0;i<sa->dot;i++)
        if(ch==sa->ch[i]) break;
    return i-1;
}

int check(int xi[],int pp)//寻找最短边的序号
{
    int i,j=0,rain[10];
    for(i=0;i<pp;i++)
    {
        if(xi[i]!=maxint)
            rain[j++]=xi[i];
    }
    int x=rain[0];
    for(i=1;i<j;i++)
    {
        if(rain[i]<x) x=rain[i];
    }
    return x;
}
void prim(struct sdd *g,char v)
{
    int k,i,h,j;
    k=choose(v);
    int adjvex[max],lowcost[max];
    for(i=0;i<g->dot;i++)
    {
        lowcost[i]=g->gg[k][i];
        adjvex[i]=k;
    }
    lowcost[k]=0;
    for(h=1;h<g->dot;h++)
    {
        j=check(lowcost,g->dot);
        printf("(%d,%d)%d",j,adjvex[j],lowcost[j]);
        lowcost[j]=0;
        for(i=0;i<g->dot;i++)
           if(g->gg[i][j]<lowcost[i])
           {
               lowcost[i]=g->gg[i][j];
               adjvex[i]=j;
           }
    }
}

int main()
{
    sa=&pdd;
    int i,n;
    mmd(sa);
    for(i=0;i<sa->dot;i++)
    {
        for(n=0;n<sa->dot;n++)
        printf("%d ",sa->gg[i][n]);
        printf("\n");
    }
    char ch;
    printf("输入你想要的第一个顶点:");
    scanf("%c",&ch);
    prim(sa,ch);
    return 0;
}
