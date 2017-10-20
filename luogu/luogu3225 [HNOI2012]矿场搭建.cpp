#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
const int MAXN = 100000+50, MAXM = 200000+50, INF = 0x3f3f3f3f;
struct Edge
{
    int to, next;
    Edge(){}
    Edge(int _to, int _next):to(_to), next(_next){}
}edge[MAXM];

int e, head[MAXN];
bool vis[MAXN], isCut[MAXN], haveCut;
int dfn[MAXN], low[MAXN];
bool vis1[MAXN], flag;
int cnt, cut;

void clear()
{
    e = 0;
    memset(head, -1, sizeof(head));
    haveCut = false;
    memset(vis, 0, sizeof(vis));
    memset(isCut, 0, sizeof(isCut));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(vis1, 0, sizeof(vis1));
}

void add(int u, int v)
{
    edge[e] = Edge(v, head[u]);
    head[u] = e++;
}

void add2(int u, int v)
{
    add(u, v);
    add(v, u);
}

void tarjan(int u, int fa)
{
    low[u] = dfn[u] = ++cnt;
    vis[u] = true;
    int son = 0;
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (!vis[v])
        {
            ++son;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (fa == -1 && son > 1 || fa != -1 && low[v] >= dfn[u])
            {
                isCut[u] = true;
                haveCut = true;
            }
        }
        else if (dfn[v] < dfn[u] && v != fa)
            low[u] = min(low[u], dfn[v]);
    }
}

void dfs(int u)
{
    if (vis1[u]) return;
    ++cnt;
    vis1[u] = true;
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (isCut[v])
        {
            if (!cut) cut = v;
            else if (v != cut) flag = false;
        }
        else dfs(v);
    }
}

int main()
{
    int m, T = 0;
    while (cin >> m && m)
    {
        clear();
        int n = 0, ans = 0;
        long long ways = 1;
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            add2(u, v);
            n = max(n, max(u, v));
        }
        tarjan(1, -1);
        printf("Case %d: ", ++T);
        if (!haveCut)
        {
            cout << "2 " << (long long)n*(n-1)/2 << endl;
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            if (isCut[i] || vis1[i]) continue;
            cnt = cut = 0;
            flag = true;
            dfs(i);
            if (flag)
            {
                ++ans;
                ways *= cnt;
            }
        }
        cout << ans << ' ' << ways << endl;
    }
    return 0;
}


