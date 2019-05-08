#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compute(char *s);
int comp(char s1,char s2);

int main()
{
    char s[100];
    int result;
    printf("输入表达式:");
    scanf("%s",s); strcat(s,"#");
    result=compute(s);
    printf("表达式的结果：%d",result);
    return 0;
}

int compute(char *s)
{
    char a[100],b[100];
    b[0]='#';
    int top1=-1,top2=0;
    int i,k,x,y,z,op;
    for(i=0;s[i]!='\0';)
    {
        if(s[i]>=48&&s[i]<=57)
            a[++top1]=s[i++]-48;
        else
        {
            k=comp(s[i],b[top2]);
            if(k==1)  b[++top2]=s[i++];
            else if(k==-1)
            {
                y=a[top1--];
                x=a[top1--];
                op=b[top2--];
                switch(op)
                {
                    case '+':z=x+y; break;
                    case '-':z=x-y; break;
                    case '*':z=x*y;break;
                    case '/':z=x/y; break;
                    default:break;
                }
                a[++top1]=z;
            }
            else { top2--; i++; }
        }
    }
    return a[top1];
}

int comp(char s1,char s2)
{
    switch (s1)
    {
       case '+':
       case '-':if(s2=='('||s2=='#') return 1;else return -1;break;
       case '*':
       case '/': if(s2=='('||s2=='#') return 1;else return -1;break;
       case '(':return 1; break;
       case ')':if(s2=='(') return 0; else return -1; break;
       case '#':if(s2=='#') return 0; else return-1; break;
    }
}
