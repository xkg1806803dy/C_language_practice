#include <stdio.h>
#include <stdlib.h>
#define maxint 32767
#define max  100
struct sdd
{
    char  ch[max];
    int  gg[max][max];
    int   dot,arc;
}pdd,*sa;

void mmd(struct sdd * sa)
{
    int choos(char ch);
    int i,n;
    char ch1,ch2;
    printf("顶的个数,总边数:");
    scanf("%d,%d",&sa->dot,&sa->arc);
    printf("%d",sa->arc);
    for(i=0;i<sa->dot;i++)
        for(n=0;n<sa->dot;n++)
           sa->gg[i][n]=maxint;
    printf("各个顶点：");
    for(i=0;i<sa->dot;i++)
       scanf("%c",&sa->ch[i]);
    printf("个点之间的关系：") ;
    for(i=0;i<sa->arc+1;i++)
    {
        scanf("%c%c",&ch1,&ch2);
        scanf("%d",&sa->gg[choos(ch1)][choos(ch2)]);
    }
}
int choos(char ch)
{
    int i;
    for(i=0;i<sa->dot;i++)
        if(ch==sa->ch[i]) break;
    return i-1;
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
    return 0;
}
