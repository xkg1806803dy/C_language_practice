#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i,j=0,t1,t2,t3,s;
        int a[900];
        for(i=n;i<=m;i++)
        {
            t1=i/100; t2=i/10%10; t3=i%10;
            s=t1*t1*t1+t2*t2*t2+t3*t3*t3;
            if(i==s) a[j++]=i;
        }
        if(j==0) printf("no\n");
        else
        {
            for(i=0;i<j-1;i++)
            {
                printf("%d ",a[i]);
            }
            printf("%d\n",a[i]);
        }
    }
    return 0;
}
