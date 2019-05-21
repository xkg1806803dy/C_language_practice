/*#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int n;
    char a[1001],b[1001];
    scanf("%d",&n);
    while(n--)
    {
        printf("Case:%d\n",n+1);
        int i=0;
        scanf("%s",&a);
        printf("%s",a);
        printf(" + ");
        i=0;
        getchar();
        scanf("%s",b);
        printf("%s",b);
        printf(" = ");
        int j=0,dd,x,count=0;
        int ta=strlen(a),tb=strlen(b);
        if(ta<tb)
        {
            dd=tb;
            while(tb--)
            {
                if(ta-1>0) x='a[ta-1]'+'a[tb-1]'+count;
                else  x= 'b[tb-1]'+count;
                if(x>9) {x=x%10; count=1;}
                b[tb-1]='x';
                ta--;
            }
            for(i=0;i<dd;i++) printf("%c",b[i]);
            printf("\n");
        }
        else
        {
            dd=ta;
            while(ta--)
            {
                if(tb-1>0) x='a[ta-1]'+'a[tb-1]'+count;
                else  x= 'b[ta-1]'+count;
                if(x>9) {x=x%10; count=1;}
                b[ta-1]='x';
                tb--;
            }
            for(i=0;i<dd;i++) printf("%c",a[i]);
            printf("\n");
        }
    }
    return 0;
}
*/
#include <stdio.h>
#include <string.h>

int main()
{
    int T,lena,lenb,lenc,ct,flag;
    char a[1002],b[1002];
    int i,j;

    scanf("%d",&T);

    for(i = 0; i < T; i++)
    {
        int c[1002] = {0};

        scanf("%s%s",&a,&b);

        lena = strlen(a);
        lenb = strlen(b);

        ct = 0;


        while(lena > 0&&lenb > 0)
        {
            if(c[ct] + a[lena-1] + b[lenb-1] - '0' > '9')
            {
                c[ct] = c[ct] + a[lena-1] - '0' + b[lenb-1] - '0' - 10;
                c[ct+1]++;
            }
            else
            {
                c[ct] = c[ct] + a[lena-1] - '0' + b[lenb-1] - '0';
            }

            lena--;
            lenb--;
            ct++;
        }
        if(lena > 0)
        {
            for(j = lena-1; j >= 0; j--)
            {
                c[ct] = c[ct] + a[lena-1] - '0';

                ct++;
                lena--;
            }
        }
        else if(lenb > 0)
        {
            for(j = lenb-1; j >= 0; j--)
            {
                c[ct] = c[ct] + b[lenb-1] - '0';

                ct++;
                lenb--;
            }
        }
        else if(c[ct] != 0)
        {
            ct++;
        }

        printf("Case %d:\n",i+1);
        printf("%s + %s = ",a,b);

        for(j = ct-1; j >= 0; j--)
            printf("%d",c[j]);
        if(i < T-1)
            printf("\n");

        printf("\n");
    }
    return 0;
}
