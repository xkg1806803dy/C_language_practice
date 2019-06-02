#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,n,a,num,len;
    scanf("%d",&n);
    while(n--)
    {
        int bbd[51][2], i,j;
        scanf("%d",&a);
        for(i=0;i<a;i++)
        {
            scanf("%d%d",&bbd[i][0],&bbd[i][1]);
        }
        int t,p;
        for (i=0;i<a;i++)
        {

            for(j=i+1;j<a;j++)
           {
               if(bbd[i][0]>bbd[j][0]) {t=bbd[i][0]; p=bbd[i][1];  bbd[i][0]=bbd[j][0];bbd[i][1]=bbd[j][1];   bbd[j][0]= t; bbd[j][1]=p; }
           }
        }
        char b[31];   b[0]='+';
        for(x=0;x<a;x++)
        {
            b[bbd[x][0]-1]='+'; b[bbd[x][0]]='\0';
            for(i=1;i<bbd[x][0]-1;i++)
                 b[i]='-';
            for(j=0;j<bbd[x][1];j++)
            printf(">%s>\n",b);
            printf("\n");
        }
    }
    return 0;
}
