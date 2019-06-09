#include "book_define.h"











Status InitList(SqList *L)//Sequence 顺序 List 表
{
    //构造一个空的顺序表L
    L->elem=(Book *)malloc(MAXSIZE*sizeof(Book));//创建空间
    if(!L->elem)
        exit(ERROR);//定义ERROR为假等于0，顺序表创建失败
    L->length=0;
    //L->listsize=MAXISIZE;
    return OK;
}


//顺序表取值
Status GetElem(SqList L,int i,ElemType *e)//Elem 元素 Type 类型
{
    if(i<1||i>L.length)
        return ERROR;//ERROR 错误
    *e=L.elem[i-1];
    return OK;
}


//顺序表查找
int LocateElem(SqList L,ElemType e)//Locate 查找
{
    for(int i=0; i<L.length; i++)
    {
        if(L.elem[i].price==e.price)
            return i+1;
    }
    return 0;
}


//顺序表插入
Status ListInsert(SqList *L,int i,ElemType e)
{
    if((i<1)||(i>L->length+1))
        return ERROR;
    if(L->length==MAXISIZE)
        return ERROR;
    for(int j=L->length; j>=i-1; j--)
    {
        L->elem[j+1]=L->elem[j];
        L->elem[i-1]=e;
        ++L->length;
        return OK;
    }
}


//顺序表删除
Status ListDelete(SqList *L,int i)
{
    if((i<1)||(i>L->length))
        return ERROR;
    for(int j=i; j<=L->length-1; j++)
        L->elem[j-1]=L->elem[j];
    --L->length;
    return OK;
}


int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    SqList list;
    if(InitList(&list)==-1)
        return 0;//创建失败，停止运行
    for(int i=1; i<=3; i++) //按顺序插入前3本书
    {
        Book insert;
        scanf("%s %s %f",insert.no,insert.name,&insert.price);
        ListInsert(&list,i,insert);
    }
    Book get;
    GetElem(list,2,&get);//查找第二本书
    printf("%s %s %f\n",get.no,get.name,get.price);
    ListDelete(&list,2);//删除第二本书
    GetElem(list,2,&get);//查找第二本书
    printf("%s %s %f\n",get.no,get.name,get.price);
    return 0;
}
