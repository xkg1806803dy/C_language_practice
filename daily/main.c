#include <stdio.h>
#include <stdlib.h>
struct smz
{
    int cuoh2,fengziyu;
    struct smz *lch,*rch;
};

int ap1,ap2;
struct smz * srwde (struct smz *s,int h1,int h2)
{
    s=(struct smz *)malloc(sizeof(struct smz));
    s->cuoh2=h2;
    s->fengziyu=h1;
    if(s->fengziyu!=0||s->cuoh2!=0)
    {
        if(s->fengziyu!=0)
            s->fengziyu=h1-ap2;
        else
            s->cuoh2=h2-ap1;
        s->lch=srwde(s->lch,s->fengziyu,s->cuoh2);
        s->rch=srwde(s->rch,s->fengziyu,s->cuoh2);
    }
    return s;
}
float num=0,winf=0;
void per(struct smz *s1)
{
    if(s1->cuoh2!=0||s1->fengziyu!=0)
    {
        per(s1->lch);
        per(s1->rch);
    }
    else
    {
        if(s1->cuoh2==0)
            num++;
        else
        {
            num++;
            winf++;
        }
    }
}

int main()
{
    int hp1,hp2;
    scanf("%d%d%d%d",&hp1,&hp2,&ap1,&ap2);
    struct smz hp;
    hp.fengziyu=hp1;
    hp.cuoh2=hp2;
    hp=*srwde(&hp,hp1,hp2);
    per(&hp);
    printf("%.4f",winf/num*100);
    return 0;
}
