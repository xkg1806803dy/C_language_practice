#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
    int A,B,n;
    while(scanf("%d%d%d",&A,&B,&n)&&(A||B||n))
    {
        int i;
        long int  x=1,y=1,s;
        for(i=3;i<=n;i++)
        {
            s=(A*y+B*x)%7;
            x=y; y=s;
        }
        printf("%ld\n",s);
    }
    return 0;
}
