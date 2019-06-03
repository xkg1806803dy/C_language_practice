#include <stdio.h>
#include <stdlib.h>
#define N 40000
int s[N];

int main()
{
    int i,j,k,t,n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(s,0,sizeof(s[0]));
        s[0]=1;
        for(i=2;i<=n;i++)
        {
            for(j=0,t=0;j<N;j++)
            {
                k=s[j]*i+t;
                t=k/10;
                s[j]=k%10;
            }
        }
    for(i=N-1;!=s[i];i--);
    while(i+1)
        printf("%d",s[i--]);
    printf("\n");
            //putchar('\n');
    }
    return 0;
}
