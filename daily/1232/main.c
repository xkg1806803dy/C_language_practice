#include <stdio.h>
#include <stdlib.h>//1213
int father[1005];

int find(int x)
{
    int r=x;
    while(father[r]!=r)
      r=father[r];
    return r;
}
void Union(int x,int y)
{
    int ry,rx;
    rx=find(x);
    ry=find(y);
    if(rx!=ry)
      father[rx]=ry;
}
int main()
{
    int m,n;
    while(~scanf("%d",&n)&&n)
    {
        int x,y,i;
        for(i=1;i<=n;i++)
            father[i]=i;
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d",&x,&y);
            Union(x,y);
        }
        int times=-1;
        for(i=1;i<=n;i++)
        {
            if(father[i]==i) times++;
        }
        printf("%d\n",times);
    }
    return 0;
}
