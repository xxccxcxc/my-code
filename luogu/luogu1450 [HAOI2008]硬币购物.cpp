#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f, MAXS = 100050;
ll f[MAXS];
int c[4], d[4];
ll dfs(int u, int cnt, int s)
{
    if (s < 0) return 0;
    if (u == 4)
        if (cnt & 1) return -f[s];
        else return f[s];
    return dfs(u+1, cnt+1, s-(d[u]+1)*c[u]) + dfs(u+1, cnt, s);
}
int main()
{
    int m;
    for (int i = 0; i < 4; i++)
        scanf("%d", c+i);
    f[0] = 1;
    for (int i = 0; i < 4; i++)
        for (int j = c[i]; j < MAXS; j++)
            f[j] += f[j-c[i]];
    scanf("%d", &m);
    while (m--)
    {
        int s;
        for (int i = 0; i < 4; i++)
            scanf("%d", d+i);
        scanf("%d", &s);
        cout << dfs(0, 0, s) << endl;
    }
    return 0;
}

