#include <stdio.h>
#include <stdlib.h>
/*����һ����ά���飺

int maze[5][5] = {

0, 1, 0, 0, 0,

0, 1, 0, 1, 0,

0, 0, 0, 0, 0,

0, 1, 1, 1, 0,

0, 0, 0, 1, 0,

};

����ʾһ���Թ������е�1��ʾǽ�ڣ�0��ʾ�����ߵ�·��ֻ�ܺ����߻������ߣ�����б���ߣ�Ҫ�������ҳ������Ͻǵ����½ǵ����·�ߡ�*/
int maze[5][5];
int flag[5][5]= {0};

int choose(int j,int i)
{
    int sum=1;
    while(j<5&&i<4&&j>=0&&i>=0)
    {
        if(maze[j][i+1]!=0&&flag[j][i+1]!=1)
        {
            flag[j][i+1]=1;
            if( choose(j,i+1)==1)
                printf("(%d,%d)\n",j,i+1);
            else continue;
        }
        else  if(maze[j+1][i]!=0&&flag[j+1][i]!=1)
        {
            flag[j+1][i]=1;
            if( choose(j+1,i)==1)
                printf("(%d,%d)\n",j+1,i);
            else continue;
        }
        else  if(maze[j][i-1]!=0&&flag[j][i-1]!=1)
        {
            flag[j][i-1]=1;
            if( choose(j,i-1)==1)
                printf("(%d,%d)\n",j,i-1);
            else continue;
        }
        else  if(maze[j-1][i]!=0&&flag[j-1][i]!=1)
        {
            flag[j-1][i]=1;
            if( choose(j-1,i)==1)
                printf("(%d,%d)\n",j-1,i);
            else continue;
        }
        else
        {
            sum=0;
            break;
        }
    }
    return sum;
}

int main()
{
    int i,j;
    for(i=0; i<5; i++)
        for(j=0; j<5; j++)
            scanf("%d",&maze[i][j]);
    i=j=0;
    printf("(%d,%d)\n",j,i);
    choose(j,i);
    return 0;
}
