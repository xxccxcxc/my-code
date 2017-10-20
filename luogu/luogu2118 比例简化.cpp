#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstring>
using namespace std;
int gys(int bcs,int cs)
{
    if (cs==0)return bcs;
    return gys(cs,bcs%cs);
}
int main()
{
    ios::sync_with_stdio(false);
    int a,b,n,sa,sb;
    double ab,c,minn=10000;
    cin >>a>>b>>n;
    ab=double (a*1.0/b);
    for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
      {
          if (gys(i,j)!=1)continue;
          c=double (i*1.0/j);
          if (c>=ab&&c-ab<minn)
          {
              minn=c-ab;
              sa=i;
              sb=j;
          }
      }
    cout <<sa<<' '<<sb<<endl;
    return 0;
}

