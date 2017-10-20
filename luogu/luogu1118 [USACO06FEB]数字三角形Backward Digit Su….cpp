#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <deque>
#include <map>
using namespace std;
int n,m,yh[15],a[15];
bool p[15],ok;
void print()
{
    for (int i=1;i<=n;i++)
      cout <<a[i]<<' ';
}
void dfs(int x,int s)
{
    if (x==n&&s==m){print();ok=1;}
    if (x>=n||ok||s>m)return;
    for (int i=1;i<=n;i++)
      if (!p[i]){p[i]=1;a[x+1]=i;dfs(x+1,s+yh[x+1]*i);p[i]=0;}
}
int main()
{
    cin >>n>>m;
    yh[1]=1;
    for (int i=2;i<=n;i++)
    {
        yh[i]=1;
        for (int j=i-1;j>=2;j--)
          yh[j]+=yh[j-1];
    }
    //for (int i=1;i<=n;i++)cout <<yh[i]<<' ';
    dfs(0,0);
    return 0;
}

