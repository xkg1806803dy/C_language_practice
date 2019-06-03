#include <stdio.h>
#include <stdlib.h>

int  main()
{
    int i,j,m,n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n<0)
            continue;
        int a[10000]= {0};
        m=0;
        a[0]=1;
        for(i=1; i<=n; i++)
            for(j=0; j<=m; j++)
            {
                a[j]=a[j]*i;
                if(j>0&&a[j-1]>=10000)
                {
                    a[j]=a[j]+a[j-1]/10000;
                    a[j-1]=a[j-1]%10000;
                }
                if(a[m]>=10000)
                    m++;
            }
        printf("%d",a[m]);
        for(i=m-1; i>=0; i--)
            printf("%04d",a[i]);
        printf("\n");
    }
    return 0;
}

