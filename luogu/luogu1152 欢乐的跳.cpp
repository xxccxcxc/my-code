#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;
int main()
{
    int n,a,b,t,i,p[1001]={0};
    cin >>n>>a;
    for (int i=2;i<=n;i++)
    {
        cin >>b;
        if (abs(a-b)<n)++p[abs(a-b)];
        a=b;
    }
    for (i=1;i<n;i++)
      if (p[i]!=1)
        break;
    if (i==n)cout <<"Jolly";
    else cout <<"Not jolly";
    return 0;
}
