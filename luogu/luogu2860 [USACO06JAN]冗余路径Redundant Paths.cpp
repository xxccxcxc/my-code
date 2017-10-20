#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack> 
using namespace std;
const int N = 5050;
vector<int> e[N];
bool vis[N];
int dfsCnt, dfn[N], low[N];
vector<int> bridge;
int kCnt, belong[N];
stack<int> st;
void tarjan(int u, int fa)
{
    if (vis[u]) return;
    vis[u] = true;
    dfn[u] = low[u] = ++dfsCnt;
    st.push(u);
    int edgeCnt = e[u].size();
    for (int i = 0; i < edgeCnt; i++)
    {
        int v = e[u][i];
        if (!vis[v])
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u])
            {
                bridge.push_back(u);
                bridge.push_back(v);
                ++kCnt;
                while (true)
                {
                    int tmp = st.top(); st.pop();
                    belong[tmp] = kCnt;
                    if (tmp == v) break;
                }
            }
        }
        else if (v != fa)
            low[u] = min(low[u], dfn[v]);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    tarjan(1, -1);
    if (!st.empty())
    {
        ++kCnt;
        while (!st.empty())
        {
            belong[st.top()] = kCnt;
            st.pop();
        }
    }
    int du[N] = {0}, bCnt = bridge.size();
    for (int i = 0; i < bCnt; i++)
        ++du[belong[bridge[i]]];
    int leaf = 0;
    for (int i = 1; i <= n; i++)
        leaf += (du[i] == 1);
    cout << (leaf+1) / 2 << endl;
    return 0;
}

