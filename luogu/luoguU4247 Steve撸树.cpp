#include <cstdio>
int main()
{
    int n,x,a,ans=0;
    scanf ("%d%d",&n,&x);
    while (n--)
    {
        scanf ("%d",&a);
        ans+=a;
    }
    printf ("%d",ans/x);
    return 0;
}

