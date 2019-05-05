#include <stdio.h>
#include <stdlib.h>
typedef struct nb
{
    int data;
    struct nb *next;
}nb;
nb *creat(int n);
void  sdds(nb * rear,int m);
int main()
{
    int n,m;
    nb *rear=NULL;
    printf("输入约瑟夫环长：");
    scanf("%d",&n);
    printf("请输入密码");
    scanf("%d",&m);rear=creat(n);
    sdds(rear,m);
    return 0;
}

nb *creat(int n)
{
    nb* rear=NULL,*s;
    int i;
    rear=(nb*)malloc(sizeof(nb));
    rear->data=i;
    rear->next=rear;
    for(i=2;i<=n;i++)
    {
        s=(nb*)malloc(sizeof(nb));
        s->data=i;
        s->next=rear->next;
        rear->next=s;
        rear=s;
    }
    return rear;
}

void sdds(nb * rear,int m)
{
    nb * per=rear,*p=rear->next;
    int count=1;
    printf("出环顺序：");
    while(p->next!=p)
    {
        if(count<m)
        {
            per=p; p=p->next;
            count++;
        }
        else{
            printf("%-3d",p->data);
            per->next=p->next;
            free(p);
            p=per->next;
            count++;
        }
    }
    printf("%-3d",p->data);
    free(p);
}
