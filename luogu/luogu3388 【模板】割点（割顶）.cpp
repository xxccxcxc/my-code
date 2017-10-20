#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;
const int N = 100050;
vector<int> e[N];

int dfscnt, dfn[N], low[N];
bool iscut[N];
void tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++dfscnt;
    int son = 0;
    for (int i = 0, ecnt = e[u].size(); i < ecnt; i++){
        int v = e[u][i];
        if (!dfn[v]){
            ++son;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (fa == -1 && son > 1 || fa != -1 && low[v] >= dfn[u])
                iscut[u] = true;
        }
        else if (v != fa)
            low[u] = min(low[u], dfn[v]);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    while (m--){
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i, -1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += iscut[i];
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        if (iscut[i])
            cout << i << ' ';
    cout << endl;
    return 0;
}

