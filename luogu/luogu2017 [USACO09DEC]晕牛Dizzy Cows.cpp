#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int N = 100050;
vector<int> e[N];
queue<int> q;
int in[N], rk[N], cnt;
int main(){
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    while (m1--){
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        ++in[v];
    }
    for (int i = 1; i <= n; i++)
        if (!in[i])
            q.push(i);
    while (!q.empty()){
        int u = q.front(); q.pop();
        rk[u] = ++cnt;
        for (int i = 0, ecnt = e[u].size(); i < ecnt; i++){
            int v = e[u][i];
            if (--in[v] == 0)
                q.push(v);
        }
    }
    while (m2--){
        int u, v;
        cin >> u >> v;
        if (rk[u] > rk[v]) swap(u, v);
        cout << u << ' ' << v << endl;
    }
    return 0;
}

