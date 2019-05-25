#include <stdio.h>
#include <stdlib.h>
//2064    2037
int main()
{
    int K,M,N,a[501][501]={0},j=0;
    char  i='-1',x,y;
    while(scanf("%d",&K)!=EOF&&K!=0)
    {
        scanf("%d%d",&M,&N);
        while(K--)
        {
            scanf("%c%c",&x,&y);
            if(i!=x) { i=x;  j=0; a[i][j++]=y;  }
            else a[i][j++]=y;
        }

    }
    return 0;
}
int ppt[500]={1};
int zzd(char s[][],int M )
{
    int a[M+1],i;
    for(i=0;i<M;i++)
        a[i]=strlen(s[i]);
    int t,x;
    for(i=0;i<M;i++)
        if(ppt[i]) {t=a[i]; x=i;break;}
    for(i=1;i<M;i++)
    {
        if(ppt[i]==0) continue;
        if(t>a[i]) {t=a[i]; x=i;}
    }
    ppt[x]=0;
    return x;
}
int ppt1[500]={1};
void choose(char s[][],int N,int M)
{
    int t,i,s1=0;
    t=zzd(s,M);
    for( i=0;i<M;i++ )
        if(s[t][i]!=0&&ppt1[i]!=0) {s1++; ppt1[i]=0 ; choose(s,N,M );break; }
    ppt1[t]=0;
    printf("%d",s);
}
