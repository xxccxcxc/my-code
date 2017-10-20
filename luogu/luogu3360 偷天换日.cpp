#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <algorithm>
#define ss system ("pause");
using namespace std;
vector <int> a[1005];
int n,sj[1005],jz[1005],f[1005][605],m;
void dfs(int x)
{
    int r1,r2;
    cin >>r1>>r2;
    sj[++m]=r1*2;
    a[x].push_back(m);
    if (r2>0)
    {
        int t=m;
        for (int i=1;i<=r2;i++)
        {
            int r3,r4;
            cin >>r3>>r4;
            ++m;
            jz[m]=r3;
            sj[m]=r4;
            a[t].push_back(m);
        }
    }
    else dfs(m);
    if (x!=0)
    {
        cin >>r1>>r2;
        sj[++m]=r1*2;
        a[x].push_back(m);
        if (r2>0)
        {
            int t=m;
            for (int i=1;i<=r2;i++)
            {
                int r3,r4;
                cin >>r3>>r4;
                ++m;
                jz[m]=r3;
                sj[m]=r4;
                a[t].push_back(m);
            }
        }
        else dfs(m);
    }
}
void dfs1(int x)
{
    for (int i=0;i<a[x].size();i++)
    {
        int t=a[x][i];
        dfs1(t);
        for (int j=n;j>=sj[t];j--)
        {
            if (!a[t].size())
            {
                f[x][j]=max(f[x][j],f[x][j-sj[t]]+jz[t]);
            }
            else
            {
                for (int k=1;k<=j-sj[t];k++)
                  f[x][j]=max(f[x][j],f[x][j-k-sj[t]]+f[t][k]);
            }
        }
    }
}
int main()
{
    cin >>n;
    --n;
    dfs(0);
    //for (int i=1;i<=m;i++)cout <<sj[i]<<' '<<jz[i]<<endl;
    dfs1(0);
    cout <<f[0][n];
}
/*
50
5 0 10 1 10 1 5 0 10 2 500 1 1000 2 18 1 1000000 4
*/

