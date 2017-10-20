#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int N = 200050, INF = 0x3f3f3f3f;

struct Person{
    int l, r, val;
    bool vis;
    char sex;
}a[N];

struct Couple{
    int u, v, val;
    Couple(){u = v = 0; val = INF;}
    Couple(int _u, int _v){
        u = _u; v = _v;
        val = abs(a[u].val - a[v].val);
    }
    bool operator<(const Couple &tmp)const{
        return val > tmp.val || val == tmp.val && u > tmp.u;
    }
};

priority_queue<Couple> q;
vector<Couple> ans;

int main(){
    int n;
    string sr;
    cin >> n >> sr;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].val;
        a[i].l = i-1; a[i].r = i+1;
        a[i].vis = false;
        a[i].sex = sr[i-1];
        if (i > 1 && a[i-1].sex != a[i].sex)
            q.push(Couple(i-1, i));
    }
    while (!q.empty())
    {
        Couple cur = q.top(); q.pop();
        int u = cur.u, v = cur.v;
        if (a[u].vis || a[v].vis)
            continue;
        ans.push_back(cur);
        a[u].vis = a[v].vis = true;
        int uu = a[u].l, vv = a[v].r;
        if (uu >= 1) a[uu].r = vv;
        if (vv <= n) a[vv].l = uu;
        if (uu >= 1 && vv <= n && a[uu].sex != a[vv].sex)
            q.push(Couple(uu, vv));
    }
    int cnt = ans.size();
    cout << cnt << endl;
    for (int i = 0; i < cnt; ++i)
        cout << ans[i].u << ' ' << ans[i].v << endl;
    return 0;
}


