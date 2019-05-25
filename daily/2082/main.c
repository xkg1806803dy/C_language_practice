#include <stdio.h>
#include <stdlib.h>
__int64 sum=0;
int main()
{
    int n,a[27][3];
    for(i=1;i<27;i++)  a[i][0]=1;
    scanf("%d",&n);
    while(n--)
    {

        for(i=1;i<27;i++) scanf("%d",&a[i][1]);

    }
    return 0;
}
int pingzhen(int a[27][3],int s)
{
    int b[27]={0},i;
    for(i=1;i<27;i++)
    {
        if(b[i]<=50) b[i]=a[i][1]+pingzhen(a[27[3],b[i])
    }
}
