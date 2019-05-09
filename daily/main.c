#include <stdio.h>
#include <stdlib.h>
#define max  100
struct nb
{
    int data;
    struct nb *lchild,*rchild;
}nb;

void preorder(struct nb *root)
{
    struct nb* s[max],*bt=root;
    int top=-1;
    while(bt!=NULL||top!=-1)
    {
        while(bt!=NULL)
        {
            printf("%d",bt->data);
            s[++top]=bt;
            bt=bt->lchild;
        }
        if(top!=-1)
        {
            bt=s[top--];
            bt=bt->rchild;
        }
    }
}

struct dd
{
    struct nb *ptr;
    int flag;
}dd;
void postorder(struct nb *root)
{
   struct  dd s1[max];
   int top=-1;
   struct nb *bt =root;
    while(bt!=NULL||top!=-1)
    {
        while(bt!=NULL)
        {
            top++;
            s1[top].ptr=bt;  s1[top].flag=1;
            bt=bt->lchild;
        }
        while(top!=-1&&s1[top].flag==2)
        {
            bt=s1[top--].ptr;
            printf("%d",bt->data);
        }
        if(top!=-1)
        {
            s1[top].flag=2;
            bt=s1[top].ptr;
        }
    }
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
