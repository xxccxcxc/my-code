#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
using namespace std;
int main()
{
    int m,n,qx[501],kq[501],t,p[501]={0},pp;
    cin >>m>>n;
    for (int i=1;i<=n;i++)cin >>qx[i];
    for (int i=1;i<=n;i++)cin >>kq[i];
    for (int i=1;i<n;i++)
      for (int j=i+1;j<=n;j++)
        if (kq[i]<kq[j])
        {
            t=kq[i];kq[i]=kq[j];kq[j]=t;
            t=qx[i];qx[i]=qx[j];qx[j]=t;
        }
    for (int i=1;i<=n;i++)
    {
        pp=0;
        for (int j=qx[i];j>=1;j--)
          if (p[j]==0)
          {
              p[j]=i;
              pp=1;
              break;
          }
        if (pp==0)m-=kq[i];
    }
    cout <<m;
    return 0;
}

