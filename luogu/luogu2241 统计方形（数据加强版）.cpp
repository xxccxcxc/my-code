#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    long long s=0,n,m;
    cin >>n>>m;
    for (int i=n<m?n:m;i>=1;i--)s+=(n-i+1)*(m-i+1);
    cout <<s<<' '<<(n*n+n)*(m*m+m)/4-s;
    return 0;
}
