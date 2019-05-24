#include <stdio.h>
#include <stdlib.h>
#define maxVertex  10
#define MaxEdge 100
typedef struct
{
    int form,to;
    int weight;
}EdgeType;
typedef struct
{
    char vertex[maxVertex];
    EdgeType edge[MaxEdge];
    int vertesNum,edgeNum;
}EdgGraph;

int findRoot(int parent[],int v)
{
    int t=v;
    while(parent[t]>-1)
        t=parent[t];
    return t;
}
void Kreuskal(EdgGraph * g)
{
    int i,num=0,vex1,vex2;
    int parant[g->vertesNum];
    for(i=0;i<g->vertesNum;i++)
        parant[i]=-1;
    for(num=0,i=0;num<g->edgeNum;i++)
    {
        vex1=findRoot(parant,g->edge[i].form);
        vex2=findRoot(parant,g->edge[i].to);
        if(vex1!=vex2)
        {
            printf("(%d,%d)%d",g->edge[i].form,g->edge[i].to,g->edge[i].weight);
            parant[vex2]=vex1;
            num++;
        }
    }
}


int main()
{

    return 0;
}
