#include <stdio.h>
#include <stdlib.h>
//先 中 后 二叉树
typedef struct nb
{
    char data;
    struct nb * lchild;
    struct nb *rchild;
}nb;

void preorder(nb *s)
{
    if(s==NULL) return;
    else {
    printf("%c",s->data);
    preorder(s->lchild);
    preorder(s->rchild);
    }
}

void inorder(nb *s)
{
    if(s==NULL) return;
    else {
    preorder(s->lchild);
    printf("%c",s->data);
    preorder(s->rchild);
    }
}

void postorder(nb *s)
{
    if(s==NULL) return;
    else {
    preorder(s->lchild);
    preorder(s->rchild);
    printf("%c",s->data);
    }
}

nb *creat(nb *s)
{
    char ch;
    scanf("%c",&ch);
    if(ch=='#') s=NULL;
    else
    {
        s=(nb*)malloc(sizeof(nb));
        s->data=ch;
        s->lchild=creat(s->lchild);
        s->rchild=creat(s->rchild);
    }
    return s;
}

void delet(nb *s)
{
    if(s==NULL) return;
    delet(s->lchild);
    delet(s->rchild);
    free(s);
}

int main()
{
    nb *head=NULL;
    head=creat(head);
    printf("输出前：");
    preorder(head);
    printf("输出中：");
    inorder(head);
    printf("输出后：");
    postorder(head);
    delet(head);
    return 0;
}
