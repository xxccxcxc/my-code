#include <cstdio>
#include <algorithm>
int main()
{
    int n,a[10001],s=0;
    scanf ("%d",&n);
    for (int i=1;i<=n;i++)scanf ("%d%d",&a[i],&a[i]);
    std::sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)s+=abs(a[i]-a[n/2+1]);
    printf ("%d",s);
    return 0;
}
