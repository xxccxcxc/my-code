#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
const int MAXN = 2000, INF = 987654321;
class Network
{
private:
    int n, s, t;
    struct Edge{ int v, f, next; };
    vector<Edge> edge;
    int head[MAXN];
    int h[MAXN], gap[MAXN], cur[MAXN];
public:
    Network(){ memset (head, -1, sizeof(head)); }
    void addEdge(int u, int v, int f);
    int SAP(int _n, int _s, int _t);
    void SAP_bfs();
    int SAP_dfs(int u, int surplus);
};

void Network::addEdge(int u, int v, int f)
{
    edge.push_back((Edge){ v,f,head[u] });
    head[u] = edge.size() - 1;
    edge.push_back((Edge){ u,0,head[v] });
    head[v] = edge.size() - 1;
}

int Network::SAP(int _n, int _s, int _t)
{
    n = _n; s = _s; t = _t;
    SAP_bfs();
    for (int i = 0; i <= n; i++)
        cur[i] = head[i];
    int maxFlow = 0;
    while (h[s] < n) 
        maxFlow += SAP_dfs(s, INF);
    return maxFlow;
}

void Network::SAP_bfs()  //反向bfs预处理高度 
{
    memset (h, -1, sizeof(h));
    memset (gap, 0, sizeof(gap));
    h[t] = 0;
    gap[0] = 1;
    queue<int> q;
    q.push(t);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; ~i; i = edge[i].next)
        {
            int v = edge[i].v;
            if (!(~h[v]))
            {
                ++gap[h[v] = h[u] + 1];
                q.push(v);
            }
        }
    }
}

int Network::SAP_dfs(int u, int surplus)  //surplus为结点u的盈余 
{
    if (u == t)return surplus;
    int flow = 0;  //成功流走的流量 
    for (int i = cur[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].v;
        if (edge[i].f && h[u] == h[v] + 1)
        {
            int nowFlow = SAP_dfs(v, min(surplus - flow, edge[i].f));
            edge[i].f -= nowFlow;
            edge[i ^ 1].f += nowFlow;
            flow += nowFlow;
            if (edge[i].f)cur[u] = i;  //当前弧优化 
            if (flow == surplus)return flow;
        }
    }
    if (!(--gap[h[u]]))h[s] = n;  //间隙优化 
    ++gap[++h[u]];  //重标号 
    cur[u] = head[u];
    return flow;
}

int read() //fast io
{
    char ch = getchar();
    int x = 0, f = 1;
    while(ch < '0' || ch > '9') {if (ch == '-')f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}

int normal_source, island, special_source;
int island_dis[MAXN][MAXN];

inline int getNum(int num, int t)
{
    return normal_source + special_source + island * (t - 1) + num;
}

int main()
{
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    Network st_net;
    int edge_cnt, out_limit[MAXN] = {0}, total_cargo = 0;
    normal_source = read(); island = read(); special_source = read(); edge_cnt = read();
    int n = normal_source + special_source + island * 3 + 1, s = 0, t = n;
    for (int i = 1; i <= normal_source + special_source; i++)
    {
        int cargo;
        cargo = read(); 
        total_cargo += cargo;
        st_net.addEdge(s, i, cargo);
    }
    for (int i = 1; i <= island; i++)
    {
        int in_limit;
        in_limit = read();
        st_net.addEdge(getNum(i, 1), getNum(i, 2), in_limit);
    }
    for (int i = 1; i <= island; i++)
        out_limit[i] = read();
    for (int i = 1; i <= island; i++)
    {
        int source_cnt;
        source_cnt = read();
        while (source_cnt--)
        {
            int from_source;
            from_source = read();
            if (from_source <= normal_source)
                st_net.addEdge(from_source, getNum(i, 1), INF);
            else
                st_net.addEdge(from_source, getNum(i, 3), INF);
        }
        int p;
        p = read();
        if (p)
        {
            st_net.addEdge(getNum(i, 2), t, out_limit[i]);
            st_net.addEdge(getNum(i, 3), t, INF);
        }
    }
    for (int i = 1; i <= island; i++)
        for (int j = 1; j <= island; j++)
            island_dis[i][j] = INF;
    while (edge_cnt--)
    {
        int u, v, w;
        u = read(); v = read(); w = read();
        island_dis[u][v] = island_dis[v][u] = w;
    }
    for (int k = 1; k <= island; k++)
        for (int i = 1; i <= island; i++)
            for (int j = 1; j <= island; j++)
                if (i != j && j != k && i != k)
                    island_dis[i][j] = min(island_dis[i][j], island_dis[i][k] + island_dis[k][j]);
    int l = 0, r = 0, mid;
    for (int i = 1; i <= island; i++)
        for (int j = 1; j <= island; j++)
            if (island_dis[i][j] < INF)
                r = max(r, island_dis[i][j]);
    int failed = ++r;
    while (l < r)
    {
        mid = (l + r) >> 1;
        Network cur_net = st_net;
        for (int i = 1; i <= island; i++)
            for (int j = 1; j <= island; j++)
                if (island_dis[i][j] <= mid)
                {
                    cur_net.addEdge(getNum(i, 2), getNum(j, 1), out_limit[i]);
                    cur_net.addEdge(getNum(i, 3), getNum(j, 3), INF);
                }
        int max_flow = cur_net.SAP(n, s, t);
        if (max_flow == total_cargo)r = mid;
        else l = mid + 1;
    }
    if (l == failed)printf("-1\n");
    else printf("%d\n", l);
    return 0;
}

