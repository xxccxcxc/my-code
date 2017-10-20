#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f, MAXN = 500050;

struct Edge
{
    int to, next;
}edge[MAXN*2];
int e, head[MAXN];

struct SpNode
{
    int fa, son, size, deep, top;
}sp[MAXN];

void add1(int u, int v)
{
    edge[e].to = v;
    edge[e].next = head[u];
    head[u] = e++;
}

void add(int u, int v)
{
    add1(u, v);
    add1(v, u);
}

void dfs1(int u, int fa)
{
    sp[u].fa = fa;
    sp[u].son = 0;
    sp[u].size = 1;
    sp[u].deep = sp[fa].deep + 1;
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fa) continue;
        dfs1(v, u);
        if (!sp[u].son || sp[v].size > sp[sp[u].son].size)
            sp[u].son = v;
        sp[u].size += sp[v].size;
    }
}

void dfs2(int u)
{
    if (!sp[u].son) return;
    sp[sp[u].son].top = sp[u].top;
    dfs2(sp[u].son);
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v != sp[u].fa && v != sp[u].son)
        {
            sp[v].top = v;
            dfs2(v);
        }
    }
}

int lca(int x, int y)
{
    int tx = sp[x].top, ty = sp[y].top;
    while (tx != ty)
    {
        if (sp[tx].deep < sp[ty].deep)
            swap(tx, ty), swap(x, y);
        x = sp[tx].fa;
        tx = sp[x].top;
    }
    return sp[x].deep < sp[y].deep ? x : y;
} 

int main()
{
    memset(head, -1, sizeof(head));
    int n, m, root;
    scanf("%d%d%d", &n, &m, &root);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
    }
    sp[0].deep = 0;
    dfs1(root, 0);
    sp[root].top = root;
    dfs2(root);
    while (m--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", lca(x, y));
    }
    return 0;
}

