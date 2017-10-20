#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int N = 200, M = 5050;
struct Edge{
    int u, v;
}e[M];
int n, m; 
int a[N][N];
bool vis[N];

bool cmp(Edge t1, Edge t2){
    return t1.u < t2.u || t1.u == t2.u && t1.v < t2.v;
}

void dfs(int u){
    vis[u] = true;
    for (int v = 1; v <= n; v++)
        if (a[u][v] && !vis[v])
            dfs(v);
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        cin >> e[i].u >> e[i].v;
        if (e[i].u > e[i].v)
            swap(e[i].u, e[i].v);
        a[e[i].u][e[i].v] = a[e[i].v][e[i].u] = true;
    }
    sort(e+1, e+m+1, cmp);
    for (int i = 1; i <= m; i++){
        a[e[i].u][e[i].v] = a[e[i].v][e[i].u] = false;
        memset(vis, 0, sizeof(vis));
        dfs(1);
        for (int j = 1; j <= n; j++)
            if (!vis[j]){
                cout << e[i].u << ' ' << e[i].v << endl;
                break;
            }
        a[e[i].u][e[i].v] = a[e[i].v][e[i].u] = true;
    }
    return 0;
}

