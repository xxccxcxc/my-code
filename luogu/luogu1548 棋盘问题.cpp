#include <cstdio>
int main()
{
    int s=0,n,m;
    scanf ("%d%d",&n,&m);
    for (int i=n<m?n:m;i>=1;i--)s+=(n-i+1)*(m-i+1);
    printf ("%d %d",s,(n*n+n)*(m*m+m)/4-s);
    return 0;
}
