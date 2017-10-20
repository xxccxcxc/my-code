#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    long long a,b,s=0;
    scanf("%I64d%I64d",&a,&b);
    for (int i=a;i<=b;i++)
    {
        if (abs(i)%4!=2)++s;
    }
    printf("%I64d",s);
    return 0;
}
