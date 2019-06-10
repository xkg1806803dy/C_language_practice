#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char sum[100010];


struct sdd
{
    int num;
    char s[10010];
}aid[10010];

void handle()
{
    int i,j=0,t=0;
    struct sdd *p,*p1;
    struct sdd aid[10010];
    p1=p=&aid[0];
    int len;
    len=strlen(sum);
    p=(struct sdd*)malloc(sizeof(struct sdd));
    p->num=1;
    for(i=0;i<len;i++)
    {
        if(sum[i]=='P') { p=&aid[++j];p->num=j+1;  p=(struct sdd*)malloc(sizeof(struct sdd)); t=strlen(p1); p1=p; continue; }
        if(sum[i]=='B') { p=&aid[++j];p->num=j+1;  p=(struct sdd*)malloc(sizeof(struct sdd)); int x;
        x=strlen(p1); strncpy(p,p1,x-1);t=x-1;  continue; }
        p[j].s[t]=sum[i];
    }
}
int main()
{
    int k,n,m,j,t;
    scanf("%s",&sum);
    handle();
    scanf("%d",&k);
    char ch[10010];
    while(k--)
    {
        int tim=0,i;
        scanf("%d%d",&n,&m);
        t=strlen(aid[m-1].s)-strlen(aid[n-1].s);
        strcpy(ch,aid[m-1].s);
        if(t<0) {printf("0\n"); continue;}
        for(i=0;i<t;i++)
        {
            if(strncmp(aid[n-1].s,ch,strlen(aid[n-1].s)==0)) tim++;
            else
            {
                char a;
                for(j=1;j<=strlen(ch);j++)
                {
                    a=ch[j];
                    ch[j-1]=a;
                }
            }
        }
        printf("%d\n",tim);
    }
    return 0;
}
