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
    //����һ���յ�˳���L
    L.elem=new Elemtype(MAXISIZE);//Elemtype�������ͣ������Ԫ��Ϊ�ṹ�壬�����ǽṹ������,�����ҽ�Book==Elemtype
    if(!L.elem)
        exit(OVERFLOW);//�൱��exit(0);
    L.length=0;
    return OK;//����OKΪ�����1��˳������ɹ�
}




Status GetElem()
{
    if(i<1||i>L.length)
        return ERROR;//��ȡֵ���±겻�ڸ����䣬ȡֵʧ��
    e=L.elem[i-1];//����ȡֵ����e
    return OK;//ȡֵ�ɹ�
}



int LocateElem(SqList L,ElemType e)
{
    for(i=0; i<L.length; i++)
    {
        if(L.elem[i]==e)//������ֱ�ӱȽϽṹ�壩
            return i+1;//�ж�����ҵ���������Ƿ����,�����±�
    }
    return 0;//�����궼û�ҵ�������ʧ��
}



Status ListInsert(SqList &L,int i,ElemType e)//iҪ�����λ�ã�eҪ�����ֵ
{
    if(i<1||i>L.length+1)
        return ERROR;//ͬȡֵ�к�����ͬ
    if(L->length==MAXISIZE)
        return ERROR;//���L�ĳ��ȵ������ռ䣬�������������޷�����
    for(j=L->length; j>=i-1; j--)//�Ӳ��봦������ֵ������
        {
        L->elem[j+1]=L->elem[j];
        L->elem[i-1]=e;//����Ԫ��
        ++L->length;//L����+1
        return OK;//����ɹ�
    }
}



Status ListDelete(SqList *L,int i)
{
    if((i<1)||(i>L->length))
        return ERROR;//ͬȡֵ�к�����ͬ
    for(int j=i; j<=L->length-1; j++) //��ɾ���㿪ʼ������һ����ֵ����ǰһ��
        L->elem[j-1]=L->elem[j];
    --L->length;//L����-1
    return OK;//ɾ���ɹ�
}
