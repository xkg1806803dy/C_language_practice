#include <stdio.h>
#include <stdlib.h>

int qingNdekc(int n)
{
    int i; __int64 s=1;
       for(i=1;i<=n;i++)
           s*=i;
    return s%100;
}

int Nde2cf(int n)
{
    int i; __int64 s=1;
    if (n!=0 )
       for(i=0;i<n;i++)
          s*=2;
    return s%100;
}
void sc(int n)
{
    if(n==1) printf("%d\n",2*qingNdekc(1)%100 );
    if(n==2) printf("6\n",2*(qingNdekc(2)+qingNdekc(1))%100);
    if(n==3) printf("%d\n",2*(qingNdekc(3)+qingNdekc(2)+1)%100);
    if(n==4) printf("%d\n",2*(qingNdekc(4)+qingNdekc(3)+qingNdekc(2)+1)%100);
    if(n>4)  printf("%d\n",(qingNdekc(n)+qingNdekc(n-1)+qingNdekc(n-2)+qingNdekc(n-3)+qingNdekc(n-1))*2%100);
}


int main()
{
    int T,n;
    while (scanf("%d",&T)!=EOF&&T!=0)
    {
        scanf("%d",&n);
        sc(n);
    }
    return 0;
}
