#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
const int N = 100050;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n, m;
        cin >> n >> m;
        vector<int> e[N];
        int in[N] = {0};
        while (m--){
            int u, v;
            cin >> u >> v;
            e[v].push_back(u);
            ++in[u];
        }
        priority_queue<int> q;
        for (int i = 1; i <= n; i++)
            if (!in[i])
                q.push(i);
        stack<int> ans;
        while (!q.empty()){
            int u = q.top(); q.pop();
            ans.push(u);
            for (int i = 0, ecnt = e[u].size(); i < ecnt; i++){
                int v = e[u][i];
                if (--in[v] == 0)
                    q.push(v);
            }
        }
        int cnt = ans.size();
        if (cnt < n) cout << "Impossible!" << endl;
        else{
            while (!ans.empty()){
                cout << ans.top() << ' ';
                ans.pop();
            }
            cout << endl;
        }
    }
    return 0;
}

