#include <stdio.h>
#include <stdlib.h>

int m=13;
int H(int n)
{
    return n%m;
}

int hashSaerch(int ht[],int m,int k,int *p )
{
    int i,j,flag=0;
    j=H(k);
    i=j;
    while(ht[i]!=0&&flag==0)
    {
        if(ht[i]==k)
        {
            *p=i;
            return 1;
        }
        else
            i=(i+1)%m;
        if(i==j)
            flag=1;
    }
    if(flag==1)
    {
        printf("溢出");
        exit(-1);
    }
    else
    {
        ht[i]=k;
        *p=i;
        return 0;
    }
}

int main()
{
    int ht[14]= {0};
    int i=1,x=1,*p,t;
    while(x!=0)
    {
        scanf("%d",&x);
        if(x==0)
            break;
        t=hashSaerch(ht,m,x,*p);
        ht[*p]=x;
        if(t==0)
            printf("%d这个数字不存在\n",x);
        else
            printf("%d存在\n",x);

    }

    return 0;
}
