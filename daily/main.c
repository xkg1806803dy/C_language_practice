#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int A,B,n;
    while(scanf("%d%d%d",&A,&B,&n)&&(A||B||n))
    {
        int i,a[50],s;
        a[2]=1; a[1]=1;
        for(i=3;i<=49;i++)
            a[i]=(A*a[i-1]+B*a[i-2])%7;
        s=n%49;
        a[0]=a[49];
        printf("%d\n",a[s]);
    }
    return 0;
}
