#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int n,v,f[1000001][2],x,y;
vector <int> a[1000001];
int dfs(int x,int y)
{
    int u;
    for (int i=0;i<a[x].size();i++)
    {
        u=a[x][i];
        if (u!=y)
        {
            dfs(u,x);
            f[x][1]+=f[u][0];
            f[x][0]+=max(f[u][1],f[u][0]);
        }
    }
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>f[i][1];
        f[i][0]=0;
    }
    for (int i=1;i<=n-1;i++)
    {
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1,-1);
    cout<<max(f[1][0],f[1][1])<<endl;
    return 0;
}
/*
5
1 2 3 4 5
1 2
1 3
2 4
2 5

12
*/
