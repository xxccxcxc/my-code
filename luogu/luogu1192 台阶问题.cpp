#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
int a[100001],n,k;
int main()
{
    cin >>n>>k;
    for (int i=1;i<=n;i++)
    {
        for (int j=i-1;j>=i-k&&j>=1;j--)
          a[i]=(a[i]+a[j])%100003;
        if (i<=k)a[i]+=1;
    }
    cout <<a[n];
    return 0;
}
