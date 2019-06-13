#include <stdio.h>
#include <stdlib.h>
int hash[10005];
int a[10005];
int main()
{
    memset(hash,0,sizeof(hash));
    int t,n,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            hash[a[i]]=i;
        }
        int flag=0;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                int p2=a[i]+a[j];
                if(p2%2)
                    continue;
                if((hash[p2/2]>i&&hash[p2/2]<j)||(hash[p2/2]<i&&hash[p2/2]>j) )
                   {flag=1;break;}
            }
        }
        if(flag==1) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
