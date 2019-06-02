#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,num;
    scanf("%d",&n);
    while(n--)
    {
        __int64 s=1;
        scanf("%d",&num);
        for(i=1;i<1000;i++)
        {
            s+=i*i*i;
            if(s>num)
            {
                printf("%d\n",i);break;
            }
        }
    }
    return 0;
}
