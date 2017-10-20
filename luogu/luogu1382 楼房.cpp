#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1000050;
struct Rect {
    int h, l, r;
    bool operator<(const Rect &t)const {
        return h < t.h;
    }
}rect[N];
struct Ans {
    int x, y;
    Ans(int _x=0, int _y=0):x(_x), y(_y){}
};
int lsh[N*2];
priority_queue<Rect> q;
vector<Ans> ans;
bool cmp(Rect t1, Rect t2) {
    return t1.l < t2.l;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &rect[i].h, &rect[i].l, &rect[i].r);
        lsh[i*2-1] = rect[i].l; lsh[i*2] = rect[i].r;
    }
    sort(lsh+1, lsh+n*2+1);
    int cnt = unique(lsh+1, lsh+n*2+1) - (lsh+1);
    for (int i = 1; i <= n; i++) {
        rect[i].l = lower_bound(lsh+1, lsh+cnt+1, rect[i].l) - lsh;
        rect[i].r = lower_bound(lsh+1, lsh+cnt+1, rect[i].r) - lsh;
    }
    sort(rect+1, rect+n+1, cmp);
    int pre = 0, cur, tmp = 1;
    for (int i = 1; i <= cnt; i++) {
        while (tmp <= n && rect[tmp].l == i) q.push(rect[tmp++]);
        while (!q.empty() && q.top().r <= i) q.pop();
        cur = q.empty() ? 0 : q.top().h;
        if (cur != pre) {
            ans.push_back(Ans(lsh[i], pre));
            ans.push_back(Ans(lsh[i], cur));
            pre = cur;
        }
    }
    int size = ans.size();
    printf("%d\n", size);
    for (int i = 0; i < size; i++)
        printf("%d %d\n", ans[i].x, ans[i].y);
    return 0;
}

