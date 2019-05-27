#include <stdio.h>
#include <stdlib.h>
//4296
int main()
{
    int n,wiht,len,a[100001],le[100001],wih[100001];
	while (~scanf("%d",&n))
	{
		int i=0;
		while(n--)
		{
			scanf("%d%d",&wiht,&len);
		    a[i]=wiht+len;
			wih[i]=wiht;
			le[i++]=len;
		}
		for(i=0;i<strlen(a);i++)
		{
			int  s=a[i];len=le[i];wiht=wih[i];
            for(int j=i+1;j<strlen(a);j++)
			{
				if(s<a[j]) { a[i]=a[j]; a[j]=s; s=a[i];
				         le[i]=le[j]; le[j]=len; len=le[i];
						 wih[i]=wih[j];wih[j]=wiht; wiht = wih[i];
				}
			}
		}
		int sum[100000]={0};
	    for(i=0;i<strlen(a);i++ )
		{
 		     for(int j=i+1;j<strlen(a);j++)
			     sum[i]+=wih[j];
             printf("%d",sum[i]-le[i]);
		}
	}
}
