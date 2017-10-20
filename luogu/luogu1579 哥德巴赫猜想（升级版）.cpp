#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
bool zs(int x)
{
    for (int i=2;i<=sqrt(x);i++)if (x%i==0)return 0;
    return 1;
}
int main()
{
    int n,p=1;
    cin >>n;
    for (int i=2;i<=n;i++){
      for (int j=i;j<n-i;j++)
      {
          if (zs(i)&&zs(j)&&zs(n-i-j))
            {cout <<i<<' '<<j<<' '<<n-i-j;p=0;break;}
      }if (!p)break;}
    return 0;
}

