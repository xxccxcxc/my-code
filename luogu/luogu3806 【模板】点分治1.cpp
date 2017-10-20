#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 10050, MAXD = 10000001;
struct Edge
{
    int to, w, next;
}edge[MAXN*2];
int e = 0, head[MAXN];
bool vis[MAXN];
int dis[MAXN], dTop, dCnt[MAXD];
int son[MAXN], mx[MAXN];

void add1(int u, int v, int w)
{
    edge[e].to = v;
    edge[e].w = w;
    edge[e].next = head[u];
    head[u] = e++;
}

void add(int u, int v, int w)
{
    add1(u, v, w);
    add1(v, u, w);
}

void getDis(int u, int curDis, int fa)
{
    dis[dTop++] = curDis;
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (!vis[v] && v != fa)
            getDis(v, curDis+edge[i].w, u);
    }
}

void work(int u, int t, int add)
{
    dTop = 0;
    getDis(u, 0, 0);
    for (int i = 0; i < dTop-1; i++)
        for (int j = i+1; j < dTop; j++)
            if (dis[i] + dis[j] + t < MAXD)
                dCnt[dis[i]+dis[j]+t] += add;
}

int getRoot(int u, int fa, int sums)
{
    son[u] = 1;
    mx[u] = 0;
    int ret = 0;
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (!vis[v] && v != fa)
        {
            int tmp = getRoot(v, u, sums);
            mx[u] = max(mx[u], son[v]);
            if (!ret || mx[tmp] < mx[ret])
                ret = tmp;
            son[u] += son[v];
        }
    }
    mx[u] = max(mx[u], sums-son[u]);
    if (!ret || mx[u] < mx[ret]) ret = u;
    return ret;
}

void dfs(int u, int n)
{
    work(u, 0, 1);
    vis[u] = true;
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (!vis[v])
        {
            work(v, edge[i].w*2, -1);
            int sums = son[v];
            if (sums > son[u]) sums = n-son[u];
            dfs(getRoot(v, 0, sums), sums);
        }
    }
}

int main()
{
    memset(head, -1, sizeof(head));
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
    }
    int root = getRoot(1, 0, n);
    dfs(root, n);
    while (m--)
    {
        int k;
        scanf("%d", &k);
        if (dCnt[k]) puts("AYE");
        else puts("NAY");
    }
    return 0;
}
