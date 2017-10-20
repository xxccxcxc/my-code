#include <cstdio>
int a[10001],n,m,t;
int main()
{
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n;i++)scanf ("%d",&a[i]);
    for (int i=m+1;i<=n;i++)
    {
        t=1;
        for (int j=2;j<=m;j++)if (a[j]<a[t])t=j;
        a[t]+=a[i];
    }
    t=1;
    for (int i=2;i<=m;i++)if (a[i]>a[t])t=i;
    printf ("%d",a[t]);
    return 0;
}
