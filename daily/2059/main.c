#include <stdio.h>
#include <stdlib.h>

/*int main()
{
    int l,vr,vt1,vt2,t,c,n,p,a[100],i,time1,time2;
    scanf("%d,%d,%d,%d,%d,%d,%d,%d",&l,&n,&c,&t,&vr,&vt1,&vt2,a[0]);
    for(i=1; i<n; i++)
    {
        scanf("%d",&a[i]);
        a[i]=a[i]-a[i-1];
    }
    time1=l/vr;
    p=0;
    time2=rain(a,n,vt1,vt2,c,t);
    if(time1>time2)
        p=1;
    time2=c/vt1+(l-c)/vt2;
    if(time1>time2)
        p=1;
    if(p==1)
        printf("What a pity rabbit!");
    else
        printf("Good job,rabbit!");
    return 0;
}
int   rain(int a[],int n,int vt1,int vt2,int c,int t)
{
    int T=0,i;
    for(i=0; i<n; i++)
    {
        if(a[i]>c)
            T=c/vt1+(a[i]-c)/vt2+t+T;
        else
        {
            T=a[i]/vt1+t+T;
            a[i+1]=a[i+1]+a[i]-c;
        }
    }
    return T;
}*/
int main()
{
    float N,jl,cTime,Vr,Vt,Vt1,a[20],Len;
    scanf("%f",&Len);
    getchar();
    scanf("%f,%f,%f",&N,&jl,&cTime);  getchar();
    scanf("%f,%f,%f",&Vr,&Vt,&Vt1);
    scanf("%f",&a[0]);
    for(i=1; i<N; i++)
    {
        scanf("%d",&a[i]);
        a[i]=a[i]-a[i-1];
    }
    float timer,timet;
    timer=Len/Vr;

}
