#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    long long s=1;
    int x,n;
    cin >>x>>n;
    for (int i=1;i<=n;i++)
      s+=s*x;
    cout <<s;
    return 0;
}

