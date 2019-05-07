#include <stdio.h>
#include <stdlib.h>

struct sd
{
    int data;
    int  lch,rch,parent;
    int buji;
}sd[20];

int ac[20]={0};

void hufu(struct sd  pk[20],int ac[],int n )
{
    int i,k,x,y,*d,*p;
    void select(struct sd pk[20],int n,int *d,int *p);
    for(i=0;i<2*n-1;i++)
    {
        pk[i].parent=-1;
        pk[i].lch=-1;
        pk[i].rch=-1;  pk[i].buji=0;
    }
    for(i=0;i<n;i++)
       pk[i].data=ac[i];
    for(k=n;k<2*n-1;k++)
    {
        d=&x;p=&y;
        select(sd,k,d,p);
        pk[k].data=pk[*d].data+   pk[*p].data;
        pk[*d].parent=k;
         pk[*p].parent=k;
        pk[k].lch=*d;    pk[k].rch=*p;
    }

}

 void select(struct sd pk[20],int n,int *d,int *p)
{
   int i,j,t;
   struct sd *s,*s1;
   for(i=0;i<n;i++)
   {
      if(pk[i].buji==1)  continue;
      else
       {
           s=&pk[i]; t=s->data;
          for(j=i+1;j<n;j++)
          {
              if(pk[j].buji==1)  continue;
              else {if(t>pk[j].data)   { t=pk[j].data; s=&pk[j]; }
              }
          }
          s->buji=1;
          d=s->data;
       }
      if(pk[i].buji==1)  continue;
      else
       {
           s1=&pk[i];  t=s1->data;
          for(j=i+1;j<n;j++)
          {
              if(pk[j].buji==1)  continue;
              else {if(t>pk[j].data)  {s1=&pk[j]; t=pk[j].data;  }
              }
          }
          s1->buji=1;
          p= s->data;
       }
   }
}

int main()
{
    int i,n;
    printf("输入你想输入数字的个数：(<10)");
    scanf("%d",&n);
    printf("输入你想输入的数字：");
    for(i=0;i<n;i++)
        scanf("%d",&ac[i]);
    hufu(sd,ac,n);
    return 0;
}
