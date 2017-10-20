#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
using namespace std;
string a[21];
char start;
int n,maxx=-1,p[21],t;
void dfs(string s)
{
    t=s.size();
    maxx=max(maxx,t);
    for (int i=1;i<=n;i++)
    {
        if (p[i])
        {
            for (int j=1;j<min(s.size(),a[i].size());j++)
            {
                if (s.substr(s.size()-j,j)==a[i].substr(0,j))
                {
                    --p[i];
                    dfs(s.substr(0,s.size()-j)+a[i]);
                    ++p[i];
                }
            }
        }
    }
}
int main()
{
    cin >>n;
    for (int i=1;i<=n;i++){cin >>a[i];p[i]=2;}
    cin >>start;
    for (int i=1;i<=n;i++)if (a[i][0]==start){--p[i];dfs(a[i]);++p[i];}
    cout <<maxx;
    return 0;
}

