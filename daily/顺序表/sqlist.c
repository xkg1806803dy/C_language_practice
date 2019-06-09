#include "book_define.h"











Status InitList(SqList *L)//Sequence ˳�� List ��
{
    //����һ���յ�˳���L
    L->elem=(Book *)malloc(MAXSIZE*sizeof(Book));//�����ռ�
    if(!L->elem)
        exit(ERROR);//����ERRORΪ�ٵ���0��˳�����ʧ��
    L->length=0;
    //L->listsize=MAXISIZE;
    return OK;
}


//˳���ȡֵ
Status GetElem(SqList L,int i,ElemType *e)//Elem Ԫ�� Type ����
{
    if(i<1||i>L.length)
        return ERROR;//ERROR ����
    *e=L.elem[i-1];
    return OK;
}


//˳������
int LocateElem(SqList L,ElemType e)//Locate ����
{
    for(int i=0; i<L.length; i++)
    {
        if(L.elem[i].price==e.price)
            return i+1;
    }
    return 0;
}


//˳������
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


//˳���ɾ��
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
        return 0;//����ʧ�ܣ�ֹͣ����
    for(int i=1; i<=3; i++) //��˳�����ǰ3����
    {
        Book insert;
        scanf("%s %s %f",insert.no,insert.name,&insert.price);
        ListInsert(&list,i,insert);
    }
    Book get;
    GetElem(list,2,&get);//���ҵڶ�����
    printf("%s %s %f\n",get.no,get.name,get.price);
    ListDelete(&list,2);//ɾ���ڶ�����
    GetElem(list,2,&get);//���ҵڶ�����
    printf("%s %s %f\n",get.no,get.name,get.price);
    return 0;
}
