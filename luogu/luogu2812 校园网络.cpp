#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
const int N = 10050;
int n;
vector<int> e[N];
int dfscnt, dfn[N], low[N];
bool vis[N];
stack<int> st;
int bcnt, belong[N];
int in[N], out[N];

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
            vis[tmp] = false;
            if (tmp == u) break;
        }
    }
}

int main(){
    cin >> n;
    for (int u = 1, v; u <= n; ++u)
        while (cin >> v && v)
            e[u].push_back(v);
    for (int i = 1; i <= n; ++i)
        if (!dfn[i]) tarjan(i);
    for (int u = 1; u <= n; ++u)
        for (int i = 0, ecnt = e[u].size(); i < ecnt; ++i){
            int v = e[u][i];
            if (belong[u] != belong[v])
                ++in[belong[v]], ++out[belong[u]];
        }
    int nin = 0, nout = 0;
    for (int i = 1; i <= bcnt; i++)
        nin += (!in[i]), nout += (!out[i]);
    cout << nin << endl << max(nin, nout) << endl;
    return 0;
}

