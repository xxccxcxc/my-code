#include <iostream>
#include <cstdio>
using namespace std;
struct renmen{
    string mz;
    int bg;
    int dj;
    int sx;
}a[111];
void jh(int i,int j)
{
    int jh1;
    string jh2;
    jh2=a[i].mz;a[i].mz=a[j].mz;a[j].mz=jh2;
    jh1=a[i].bg;a[i].bg=a[j].bg;a[j].bg=jh1;
    jh1=a[i].dj;a[i].dj=a[j].dj;a[j].dj=jh1;
    jh1=a[i].sx;a[i].sx=a[j].sx;a[j].sx=jh1;
}
int main()
{
    int n,p;
    string t;
    scanf ("%d",&n);
    for (int i=1;i<=3;i++){cin >>t;cout <<t<<' ';cin >>t;cout <<t<<' ';cin >>t;scanf ("%d",&p);printf ("%d\n",p);}
    n-=3;
    for (int i=1;i<=n;i++){cin >>a[i].mz>>t;scanf ("%d%d",&a[i].bg,&a[i].dj);a[i].sx=i;}
    for (int i=1;i<n;i++)
    {
        p=1;
        for (int j=1;j<=n-i;j++)
          if (a[j].bg<a[j+1].bg)
          {
              jh(j,j+1);
              p=0;
          }
        if (p)break;
    }
    if (a[1].dj<a[2].dj)jh(1,2);
    for (int i=1;i<4;i++)
    {
        p=1;
        for (int j=3;j<=6-i;j++)
          if (a[j].dj<a[j+1].dj||(a[j].dj==a[j+1].dj&&a[j].sx>a[j+1].sx))
          {
              jh(j,j+1);
              p=0;
          }
        if (p)break;
    }
    for (int i=1;i<7;i++)
    {
        p=1;
        for (int j=7;j<=13-i;j++)
          if (a[j].dj<a[j+1].dj||(a[j].dj==a[j+1].dj&&a[j].sx>a[j+1].sx))
          {
              jh(j,j+1);
              p=0;
          }
        if (p)break;
    }
    for (int i=1;i<25;i++)
    {
        p=1;
        for (int j=14;j<=38-i;j++)
          if (a[j].dj<a[j+1].dj||(a[j].dj==a[j+1].dj&&a[j].sx>a[j+1].sx))
          {
              jh(j,j+1);
              p=0;
          }
        if (p)break;
    }
    for (int i=1;i<n-38;i++)
    {
        p=1;
        for (int j=39;j<=n-i;j++)
          if (a[j].dj<a[j+1].dj||(a[j].dj==a[j+1].dj&&a[j].sx>a[j+1].sx))
          {
              jh(j,j+1);
              p=0;
          }
        if (p)break;
    }
    for (int i=1;i<=n;i++)
    {
        cout <<a[i].mz<<' ';
        if (i<=2)printf("HuFa");
        else if (i<=2+4)printf("ZhangLao");
        else if (i<=2+4+7)printf("TangZhu");
        else if (i<=2+4+7+25)printf("JingYing");
        else printf("BangZhong");
        cout <<' '<<a[i].dj<<endl;
    }
    return 0;
}
