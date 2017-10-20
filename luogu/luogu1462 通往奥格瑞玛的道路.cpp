#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue> 
using namespace std;
typedef long long ll;
const int N = 10050, M = 50050;
struct Edge
{
    ll w;
    int to, next;
}edge[M*2];
int e, head[N];
int n, m, hp, c[N], bin[N];
void add1(int u, int v, int w)
{
    edge[e].w = w;
    edge[e].to = v;
    edge[e].next = head[u];
    head[u] = e++;
}
void add(int u, int v, int w)
{
    add1(u, v, w);
    add1(v, u, w);
}
bool SPFA(ll lim)
{
    if (c[1] > lim) return false;
    bool vis[N] = {0};
    vis[1] = true;
    queue<int> q;
    q.push(1);
    ll f[N];
    memset(f, 0x3f, sizeof(f));
    f[1] = 0;
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (int i = head[u]; ~i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (c[v] > lim) continue;
            if (f[u] + edge[i].w < f[v])
            {
                f[v] = f[u] + edge[i].w;
                vis[v] = true;
                q.push(v);
            }
        }
        vis[u] = false;
    }
    return f[n] <= hp;
}
int main()
{
    memset(head, -1, sizeof(head));
    cin >> n >> m >> hp;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        bin[i] = c[i];
    }
    sort(bin+1, bin+n+1);
    int u, v, w;
    while (m--)
    {
        cin >> u >> v >> w;
        add(u, v, w);
    }
    int l = 1, r = n, mid;
    while (l < r)
    {
        int mid = (l+r)/2;
        if (SPFA(bin[mid])) r = mid;
        else l = mid+1;
    }
    if (SPFA(bin[l])) cout << bin[l] << endl;
    else cout << "AFK" << endl;
    return 0;
}

