#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    long int n,m,i,a;
    while(scanf("%ld%ld",&n,&m)!=EOF&&(n||m))
    {
        /*s=0;
        for(i=1; i<=n; i++)
        {
            if(s==0) j=i;
            s+=i;
            if(s==m) {  printf("[%ld,%ld]\n",j,i); i=j; s=0; }
            if(s>m)  {i=j; s=0;}
        }*/
        for( i=sqrt(2*m);i>=1;i--)
		{
            a=(m-((i-1)*i)/2)/i;
			if(m==a*i+(i*(i-1))/2)
			{
			    if(a+i-1>n) return 0;
                printf("[%ld,%ld]\n",a,a+i-1);
			}

		}
		printf("\n");
    }
    return 0;
}
