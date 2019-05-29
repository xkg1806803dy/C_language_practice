#include <stdio.h>
#include <stdlib.h>
char a[2][100][100];

int main()
{
    int n,N,M,T;
    int a2[100][2];
    scanf("%d",n);
    while(n--)
    {
        int i,j,t=0;
        scanf("%d%d%d",N,M,T);
        for(i=0;i<M;i++)
        {
            scanf("%s",&a[0][i]);
            /*for(j=0;j<N;j++)
            if(a[0][i][j]=='#')  { a1#[t][0]=i; a1#[t++][1]=j;}*/
            getchar();
        }
        t=0;
        for(i=0;i<M;i++)
        {
            scanf("%s",&a[1][i]);
            for(j=0;j<N;j++)
            if(a[1][i][j]=='#') {a2[t][1]=j; a2[t++][0]=i;}
            getchar();
        }
        int x=0,y=0,z=0,time=0;  t=0;
        while(a[z][y][x+1]!='*'&&(x+1)<N)
        {
            if(a[z][y][x+1]=='#')
            {
                z=1;
                y=a2[t][0];
                x=a2[t++][1];
            }
            x++;
            time++;
        }
        while(a[z][y+1][x]!='*'&&(y+1)<M)
        {
            if(a[z][y+1][x]=='#')
            {
                z=1;
                y=a2[t][0];
                x=a2[t++][1];
            }
            y++;
            time++;
        }
        while(a[z][y][x-1]!='*'&&0<=(x-1))
        {
            if(a[z][y][x-1]=='#')
            {
                z=1;
                y=a2[t][0];
                x=a2[t++][1];
            }
            x--;
            time++;
        }
        while(a[z][y-1][x]!='*'&&0<=(y-1))
        {
            if(a[z][y-1][x]=='#')
            {
                z=1;
                y=a2[t][0];
                x=a2[t++][1];
            }
            y--;
            time++;
        }
        if(time>T) printf("NO\n");
        else printf("Yes\n");
    }
    return 0;
}
