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
    int w=1,t=0,n,s=0,a[40001]={0};
    cin >>n;
    for (int i=1;;i++)
      if (s<n*n)
        {cin >>a[i];s+=a[i];}
      else
        break;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (a[w]==0)
            {
                ++w;
                t=t==1?0:1;
            }
            --a[w];
            cout <<t;
        }
        cout <<endl;
    }
    return 0;
}
