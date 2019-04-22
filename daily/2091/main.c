#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j;
    char ch;
    while (scanf("%c",&ch)!=EOF&&ch!='@' )
    {
        scanf("%d",&n);
        getchar();
        for(i=0; i<n; i++)
        {
            for(j=0; j<n-i-1; j++)  printf(" ");
            printf("%c",ch);
            if(i!=0)
            {
                for(j=0;j<i*2-1;j++) printf(" ");
                printf("%c",ch);
            }
            else printf("\n");
        }
        for(i=0;i<2*n-1;i++)
            printf("%c",ch);
        printf("\n");
    }
    return 0;
}
/*#include <stdio.h>

int main()
{
    char c;
    int n;
    int flag=0;
    while(scanf("%c",&c)!=EOF && c!='@')
    {
        scanf("%d",&n);
        getchar();
        if(flag)
            printf("\n");
        flag=1;
        for(int i=0; i<n-1; i++)
        {
            for(int j=0; j<n-i-1; j++)
            {
                printf(" ");
            }
            printf("%c",c);
            if(i!=0)
            {
                for(int t=0; t<2*i-1; t++)
                    printf(" ");
                printf("%c\n",c);
            }
            else
                printf("\n");
        }
        for(int i=0; i<2*n-1; i++)
        {
            printf("%c",c);
        }
        printf("\n");
    }
    return 0;
}*/
