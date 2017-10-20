#include <cstdio>
int a[31][31];
int main()
{
    int n,m;
    scanf ("%d%d",&n,&m);
    a[0][1]=1;
    for (int i=1;i<=m;i++)
      for (int j=1;j<=n;j++)
        a[i][j]=a[i-1][j-1==0?n:j-1]+a[i-1][j==n?1:j+1];
    printf ("%d",a[m][1]);
    return 0;
}
