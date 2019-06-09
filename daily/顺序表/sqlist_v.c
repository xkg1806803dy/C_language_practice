#include 'book_define.h'
#define MAXISIZE 10000
typedef struct
{
    char no[20];
    char name[50];
    float price;
} Book;




Status InitList(SqList &L)
{
    //构造一个空的顺序表L
    L.elem=new Elemtype(MAXISIZE);//Elemtype数据类型，因定义的元素为结构体，所以是结构体类型,所以我将Book==Elemtype
    if(!L.elem)
        exit(OVERFLOW);//相当于exit(0);
    L.length=0;
    return OK;//定义OK为真等于1，顺序表创建成功
}




Status GetElem()
{
    if(i<1||i>L.length)
        return ERROR;//所取值的下标不在该区间，取值失败
    e=L.elem[i-1];//将所取值赋给e
    return OK;//取值成功
}



int LocateElem(SqList L,ElemType e)
{
    for(i=0; i<L.length; i++)
    {
        if(L.elem[i]==e)//（不能直接比较结构体）
            return i+1;//判断你查找的书的数据是否相等,返回下标
    }
    return 0;//遍历完都没找到，查找失败
}



Status ListInsert(SqList &L,int i,ElemType e)//i要插入的位置，e要插入的值
{
    if(i<1||i>L.length+1)
        return ERROR;//同取值中含义相同
    if(L->length==MAXISIZE)
        return ERROR;//如果L的长度等于最大空间，即数据已满，无法插入
    for(j=L->length; j>=i-1; j--)//从插入处把所有值往后移
        {
        L->elem[j+1]=L->elem[j];
        L->elem[i-1]=e;//插入元素
        ++L->length;//L长度+1
        return OK;//插入成功
    }
}



Status ListDelete(SqList *L,int i)
{
    if((i<1)||(i>L->length))
        return ERROR;//同取值中含义相同
    for(int j=i; j<=L->length-1; j++) //从删除点开始，将后一个的值赋给前一个
        L->elem[j-1]=L->elem[j];
    --L->length;//L长度-1
    return OK;//删除成功
}
