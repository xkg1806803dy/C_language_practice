#include <stdio.h>
#include <stdlib.h>
//有点问题
struct sb
{
    struct sb *lchild;
    struct sb *rchild;
    char ch;
}FBI;

void cjyig(struct sb *s,char ch[],int N)
{
    char  ch1[N];
    if(N==1) return;
    else
    {
        s=(struct sb *) malloc(sizeof(struct sb));
       int i,flog1=0,t=0,flog2=0;//flog1=1 字符串中有0；flog1=1 字符串 有1；
       for(i=0;i<N;i++)
       {
           if(ch[i]=='1') flog2=1;
           if(ch[i]=='0') flog1=1;
           if(i>N/2-1)
           {
               ch1[t]=ch[i];
               t++;
           }
       }
       if(flog1==1&&flog2==0) s->ch='B';
       if(flog1==0&&flog2==1) s->ch='I';
       if(flog1==0&&flog2==0) s->ch='F';
       cjyig(s->lchild,ch,N/2);
       cjyig(s->rchild,ch1,N/2);
    }
}

void sc(struct sb *s)
{
    if(s->lchild)  sc(s->lchild);
    if(s->rchild)  sc(s->lchild);
    printf("%c",s->ch);
}

int main()
{
    int i,N,a=1;
    char ch[1000];
    scanf("%d",&N);
    for(i=0;i<N;i++)
        a*=2;

    scanf("%s",&ch);
    struct sb *s;
    s=&FBI;
    cjyig(s,ch,a);
    sc(s);
    return 0;
}
