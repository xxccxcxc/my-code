#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue> 
using namespace std;
const int N = 100050, M = 200050;
struct Edge
{
    int to, next;
}edge[M];
int e, head[N];
void add1(int u, int v)
{
    edge[e].to = v;
    edge[e].next = head[u];
    head[u] = e++;
}
int main()
{
    memset(head, -1, sizeof(head));
    int n, m;
    cin >> n >> m;
    int in[N] = {0};
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        add1(u, v);
        ++in[v];
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!in[i]) q.push(i);
    int tp[N], top = 0;
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        tp[top++] = u;
        for (int i = head[u]; ~i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (--in[v] == 0)
                q.push(v);
        }
    }
    int f[N] = {0};
    for (int i = 0; i < top; i++)
    {
        int u = tp[i];
        if (!f[u]) f[u] = 1;
        for (int j = head[u]; ~j; j = edge[j].next)
        {
            int v = edge[j].to;
            f[v] = max(f[v], f[u]+1);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << f[i] << endl;
    return 0;
}

