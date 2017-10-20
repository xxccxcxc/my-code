#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int N = 150, M = 10050;
struct Edge
{
    int to, w, next;
}edge[M];
int e, head[N];
int n, a[N], in[N], out[N];
void add1(int u, int v, int w)
{
    edge[e].to = v;
    edge[e].w = w;
    edge[e].next = head[u];
    head[u] = e++;
}
void topo()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!in[i]) q.push(i);
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (int i = head[u]; ~i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (a[u] > 0)
                a[v] += a[u] * edge[i].w;
            if (--in[v] == 0)
                q.push(v);
        }
    }
}
int main()
{
    memset(head, -1, sizeof(head));
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int b;
        cin >> a[i] >> b;
        if (!a[i]) a[i] -= b;
    }
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add1(u, v, w);
        ++in[v]; ++out[u];
    }
    topo();
    bool have_ans = false; 
    for (int i = 1; i <= n; i++)
        if (!out[i] && a[i] > 0)
        {
            cout << i << ' ' << a[i] << endl;
            have_ans = true;
        }
    if (!have_ans) cout << "NULL" << endl;
    return 0;
}

