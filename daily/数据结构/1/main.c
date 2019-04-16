#include <stdio.h>
#include <stdlib.h>


struct Sd
{
    struct Sd *base;
    struct Sd *top;
};
struct book
{
    int x;
    char a[10];
};
int Init(struct Sd *s)\\初始化
{
    s->base=(struct Sd *)malloc(sizeof(struct Sd)*10 );
    if(!s->base) return 0;
    s->top=s->base;
    return 1;
}
int  push (struct Sd *s,struct book *e )\\入栈
{
    if(s->top-s->base==sizeof(struct Sd)*10) return 0;
    s->top=e;
    s->top++;
    return 1;
}

int pop(struct Sd *s,struct book *e) \\出栈
{
    if(s->base=s->top)  return 0;
    e=s->top;
    printf("%d,%s",e->x,e->a);
    s->top--;
    return 1;
}
int GetTop(struct Sd *s)
{
    if(s->top!=s->base)
    return *(s->top);
}
int main()
{
    return 0;
}
