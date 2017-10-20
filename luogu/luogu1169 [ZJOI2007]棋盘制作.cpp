#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <climits>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <deque>
#include <map>
using namespace std;
int n,m,ans=1,ans1=1;
bool a[2005][2005];
int f[2005][2005],f1[2005][2005],f2[2005][2005];
int main()
{
    cin >>n>>m;
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
      {
          scanf ("%d",&a[i][j]);
          if (i%2==0)a[i][j]=!a[i][j];
          if (j%2==0)a[i][j]=!a[i][j];
      }
    /*for (int i=1;i<=n;i++){
      for (int j=1;j<=m;j++)
        cout <<a[i][j]<<' ';cout <<endl;}*/
    for (int i=1;i<=n;i++)f[i][1]=1;
    for (int j=1;j<=m;j++)f[1][m]=1;
    for (int i=2;i<=n;i++)
      for (int j=2;j<=m;j++)
      {
          if (a[i][j]==a[i-1][j]&&a[i][j]==a[i][j-1]&&a[i][j]==a[i-1][j-1])
            f[i][j]=min(f[i-1][j],min(f[i-1][j-1],f[i][j-1]))+1;
          else f[i][j]=1;
          ans=max(ans,f[i][j]);
      }
    /*for (int i=1;i<=n;i++){
      for (int j=1;j<=m;j++)
        cout <<f[i][j]<<' ';cout <<endl;}*/
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
        ans=max(ans,f[i][j]);
    cout <<ans*ans<<endl;
    for (int i=2;i<=n;i++)
      for (int j=1;j<=m;j++)
        if (a[i][j]==a[i-1][j])
          f1[i][j]=f1[i-1][j]+1;
    for (int i=n-1;i>=1;i--)
      for (int j=1;j<=m;j++)
        if (a[i][j]==a[i+1][j])
          f2[i][j]=f2[i+1][j]+1;
    /*for (int i=1;i<=n;i++){
      for (int j=1;j<=m;j++)
        cout <<f1[i][j]<<' ';cout <<endl;}
    for (int i=1;i<=n;i++){
      for (int j=1;j<=m;j++)
        cout <<f2[i][j]<<' ';cout <<endl;}*/
    for (int i=1;i<=n;i++)
    {
        int t=1,s1=f1[i][1],s2=f2[i][1];
        for (int j=1;j<=m;j++)
        {
            ans1=max(ans1,(s1+s2+1)*(j-t+1));
            if (j==m)break;
            if (a[i][j]!=a[i][j+1])
            {
                t=j+1;
                s1=f1[i][j+1];
                s2=f2[i][j+1];
            }
            else
            {
                s1=min(s1,f1[i][j+1]);
                s2=min(s2,f2[i][j+1]);
            }
        }
    }
    cout <<ans1;
    return 0;
}

