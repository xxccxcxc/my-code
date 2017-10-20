#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int N = 200050, M = 400050;

struct Input{
    int id;
    bool lr;
}inp[M];

int n, m;
int son[N][2], fa[N], tim[N];
bool p[N][2];

int find(int x)
{
    if (fa[x] == x) return x;
    int tmp = find(fa[x]);
    tim[x] = min(tim[x], tim[fa[x]]);
    return fa[x] = tmp; 
}

void unionn(int u, int v, int t)
{
    int fu = find(u), fv = find(v);
    if (fu == fv) return;
    if (fu == 1) swap(fu, fv);
    fa[fu] = fv;
    tim[fu] = t;
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> son[i][0] >> son[i][1];
        fa[i] = i;
        tim[i] = m;
    }
    for (int i = 0; i < m; i++){
        int tmp;
        cin >> inp[i].id >> tmp;
        inp[i].lr = tmp-1;
        p[inp[i].id][inp[i].lr] = true;
    }
    for (int i = 1; i <= n; i++)
        for (int lr = 0; lr < 2; lr++)
            if (!p[i][lr] && son[i][lr] != -1)
                unionn(i, son[i][lr], m);
    for (int i = m-1; i >= 0; i--)
        if (son[inp[i].id][inp[i].lr] != -1)
            unionn(inp[i].id, son[inp[i].id][inp[i].lr], i);
    for (int i = 1; i <= n; i++){
        find(i);
        cout << (tim[i] == m ? -1 : tim[i]) << endl;
    }
    return 0;
}

