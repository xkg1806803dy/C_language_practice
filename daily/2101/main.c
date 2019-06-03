#include <stdio.h>
#include <stdlib.h>

int main()
{
    __int64 a,b;
    while (scanf("%I64d%I64d",&a,&b)!=EOF)
    {
        int t;
        t=(a+b)%86;
        if(t==0) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
