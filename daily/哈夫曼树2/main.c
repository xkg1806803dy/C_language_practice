#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
struct BTreeNode
{
    ElemType data;
    struct BTreeNode* left;
    struct BTreeNode* right;
};

//1、输出二叉树，可在前序遍历的基础上修改。
//   采用广义表格式，元素类型为int
void PrintBTree_int(struct BTreeNode* BT)
{
    if (BT != NULL)
    {
        printf("%d", BT->data); //输出根结点的值
        if (BT->left != NULL || BT->right != NULL)
        {
            printf("(");
            PrintBTree_int(BT->left); //输出左子树
            if (BT->right != NULL)
                printf(",");
            PrintBTree_int(BT->right); //输出右子树
            printf(")");
        }
    }
}

//2、根据数组 a 中 n 个权值建立一棵哈夫曼树，返回树根指针
struct BTreeNode* CreateHuffman(ElemType a[], int n)
{
    int i, j;
    struct BTreeNode **b, *q;
    b = malloc(n*sizeof(struct BTreeNode));
    //初始化b指针数组，使每个指针元素指向a数组中对应的元素结点
    for (i = 0; i < n; i++)
    {
        b[i] = malloc(sizeof(struct BTreeNode));
        b[i]->data = a[i];
        b[i]->left = b[i]->right = NULL;
    }
    for (i = 1; i < n; i++)//进行 n-1 次循环建立哈夫曼树
    {
        //k1表示森林中具有最小权值的树根结点的下标，k2为次最小的下标
        int k1 = -1, k2;
        //让k1初始指向森林中第一棵树，k2指向第二棵
        for (j = 0; j < n; j++)
        {
            if (b[j] != NULL && k1 == -1)
            {
                k1 = j;
                continue;
            }
            if (b[j] != NULL)
            {
                k2 = j;
                break;
            }
        }
        //从当前森林中求出最小权值树和次最小
        for (j = k2; j < n; j++)
        {
            if (b[j] != NULL)
            {
                if (b[j]->data < b[k1]->data)
                {
                    k2 = k1;
                    k1 = j;
                }
                else if (b[j]->data < b[k2]->data)
                    k2 = j;
            }
        }
        //由最小权值树和次最小权值树建立一棵新树，q指向树根结点
        q = malloc(sizeof(struct BTreeNode));
        q->data = b[k1]->data + b[k2]->data;
        q->left = b[k1];
        q->right = b[k2];

        b[k1] = q;//将指向新树的指针赋给b指针数组中k1位置
        b[k2] = NULL;//k2位置为空
    }
    free(b); //删除动态建立的数组b
    return q; //返回整个哈夫曼树的树根指针
}

//3、求哈夫曼树的带权路径长度
ElemType WeightPathLength(struct BTreeNode* FBT, int len)//len初始为0
{
    if (FBT == NULL) //空树返回0
        return 0;
    else
    {
     if (FBT->left == NULL && FBT->right == NULL)//访问到叶子结点
     {
            printf("+ %d * %d ",FBT->data,len);
            return FBT->data * len;
     }
     else //访问到非叶子结点，进行递归调用，
     {    //返回左右子树的带权路径长度之和，len递增
     return WeightPathLength(FBT->left,len+1)+WeightPathLength(FBT->right,len+1);
     }
    }
}

//4、哈夫曼编码（可以根据哈夫曼树带权路径长度的算法基础上进行修改）
void HuffManCoding(struct BTreeNode* FBT, int len)//len初始值为0
{
    //定义静态数组a，保存每个叶子的编码，数组长度至少是树深度减一
    static int a[10];
    int i;
    //访问到叶子结点时输出其保存在数组a中的0和1序列编码
    if (FBT != NULL)
    {
        if (FBT->left == NULL && FBT->right == NULL)
        {
            printf("权值为%d的编码：", FBT->data);
            for (i = 0; i < len; i++)
                printf("%d", a[i]);
            printf("\n");
        }
        else //访问到非叶子结点时分别向左右子树递归调用，
        {    //并把分支上的0、1编码保存到数组a的对应元素中，
             //向下深入一层时len值增1
            a[len] = 0;
            HuffManCoding(FBT->left, len + 1);
            a[len] = 1;
            HuffManCoding(FBT->right, len + 1);
        }
    }
}

int main()
{
    int n, i;
    ElemType* a;
    struct BTreeNode* fbt;
    printf("输入构造哈夫曼树中带权叶子结点数(n)：");
    while(1)
    {
        scanf("%d", &n);
        if (n > 1)
            break;
        else
            printf("重输n值：");
    }
    a = malloc(n*sizeof(ElemType));
    printf("输入%d个整数作为权值：", n);
    for (i = 0; i < n; i++)
        scanf(" %d", &a[i]);
    fbt = CreateHuffman(a, n);
    printf("广义表形式的哈夫曼树：");
    PrintBTree_int(fbt);
    printf("\n");
    printf("哈夫曼树的带权路径长度：\n");
    printf("=");
    printf("\n=%d\n", WeightPathLength(fbt, 0));
    printf("树中每个叶子结点的哈夫曼编码：\n");
    HuffManCoding(fbt, 0);

    return 0;
}
