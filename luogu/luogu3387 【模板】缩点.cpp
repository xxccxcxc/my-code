#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
const int N = 500050;
int n, m;
int a[N], from[N], to[N];
vector<int> e[N], e2[N];
int dfscnt, dfn[N], low[N];
bool vis[N];
stack<int> st;
int bcnt, belong[N], val[N];
int f[N];

void tarjan(int u){
    dfn[u] = low[u] = ++dfscnt;
    vis[u] = true;
    st.push(u);
    for (int i = 0, ecnt = e[u].size(); i < ecnt; ++i){
        int v = e[u][i];
        if (!dfn[v]){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (vis[v]) low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]){
        ++bcnt;
        vis[u] = false;
        while (true){
            int tmp = st.top(); st.pop();
            belong[tmp] = bcnt;
            val[bcnt] += a[tmp];
            vis[tmp] = false;
            if (tmp == u) break;
        }
    }
}

void dfs(int u){
    f[u] = val[u];
    for (int i = 0, ecnt = e2[u].size(); i < ecnt; ++i){
        int v = e2[u][i];
        if (!f[v]) dfs(v);
        f[u] = max(f[u], f[v] + val[u]);
    }
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i){
        cin >> from[i] >> to[i];
        e[from[i]].push_back(to[i]);
    }
    for (int i = 1; i <= n; ++i)
        if (!dfn[i]) tarjan(i);
    for (int i = 1; i <= m; ++i)
        if (belong[from[i]] != belong[to[i]])
            e2[belong[from[i]]].push_back(belong[to[i]]);
    int ans = 0;
    for (int i = 1; i <= bcnt; ++i)
        if (!f[i]){
            dfs(i);
            ans = max(ans, f[i]);
        }
    cout << ans << endl;
    return 0;
}

