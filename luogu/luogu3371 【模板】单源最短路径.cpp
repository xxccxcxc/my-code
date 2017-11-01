#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int N = 10050, M = 500050, INF = 0x3f3f3f3f;
struct Edge {
    int to, w, next;
    Edge() {}
    Edge(int _to, int _w, int _next): to(_to), w(_w), next(_next) {}
}e[M];

struct Node {
    int u, w;
    Node() {}
    Node(int _u, int _w): u(_u), w(_w) {}
    bool operator<(const Node &t) const { return w > t.w; }  // �Ѵ���ѵ�С�����ã����԰�С�����سɴ��� 
};

int ecnt, head[N];  // �ǵø���ֵ 
int dis[N];
bool vis[N];

void add(int u, int v, int w) {
    e[ecnt] = Edge(v, w, head[u]);
    head[u] = ecnt++;
}

void dij(int n, int s) {  // ���Ż�dijkstra 
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<Node> q;
    dis[s] = 0;
    q.push(Node(s, 0));
    for (int _ = 1; _ <= n; _++) {
        while (!q.empty() && vis[q.top().u]) q.pop();
        if (q.empty()) break; 
        int u = q.top().u; q.pop();
        vis[u] = true;  // ����visҪ��1 
        for (int i = head[u]; ~i; i = e[i].next) {
            int v = e[i].to;
            if (!vis[v] && dis[u] + e[i].w < dis[v]) {  // ����Ҫ!vis[v]������ӵ�ֻ����δ���ʹ��ĵ� 
                dis[v] = dis[u] + e[i].w;
                q.push(Node(v, dis[v]));
            }
        }
    }
}

int main() {
    memset(head, -1, sizeof(head));
    int n, m, s;
    scanf("%d%d%d", &n, &m, &s);
    for (int u, v, w; m--; ) {
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
    }
    dij(n, s);
    for (int i = 1; i <= n; i++) {
        if (dis[i] == INF) dis[i] = 2147483647;
        printf("%d ", dis[i]);
    }
    return 0;
}

