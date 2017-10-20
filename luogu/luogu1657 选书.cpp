#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
int a[21][3],p[21],ans,n;
void dfs(int t)
{
    for (int i=1;i<=2;i++)
    {
        if (!p[a[t][i]])
        {
            p[a[t][i]]=1;
            if (t==n)++ans;
            else dfs (t+1);
            p[a[t][i]]=0;
        }
    }
}
int main()
{
    cin >>n;
    for (int i=1;i<=n;i++)
      cin >>a[i][1]>>a[i][2];
    dfs (1);
    cout <<ans;
    return 0;
}

