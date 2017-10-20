#include <cstdio>
int main()
{
    int n,a[10],b,s=0;
    scanf ("%d",&n);
    for (int i=1;i<=n;i++)
      scanf ("%d",&a[i]);
    scanf ("%d",&b);
    b+=50;
    for (int i=1;i<=n;i++)
      if (a[i]<=b)++s;
    printf ("%d",s);
    return 0;
}
