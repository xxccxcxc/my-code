#include <cstdio>
void fj(int n)
{
    int p=0,t,i;
    fh:
    t=1;
    if (p)printf ("+");
    else p=1;
    for (i=0;;i++)
    {
        if (t*2>n)break;
        t*=2;
    }
    n-=t;
    if (i==1)printf ("2");
    else if (i==0)printf ("2(0)");
    else {printf ("2(");fj(i);printf (")");}
    if (n)goto fh;
}
int main()
{
    int n;
    scanf ("%d",&n);
    if (n==0)printf ("0");
    else fj(n);
    return 0;
}
