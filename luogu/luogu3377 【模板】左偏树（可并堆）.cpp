#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 100050;
struct Item
{
    int val, id;
    bool operator <(const Item &b)const{ return val < b.val || val == b.val && id < b.id; }\
    Item(){}
    Item(int _val, int _id):val(_val), id(_id){}
};
struct Node
{
    Item data;
    int ls, rs, dis;
    Node(){ls = rs = dis = 0; data = Item(0, 0);}
    Node(int val, int id):ls(0), rs(0), dis(0){ data = Item(val, id); }
}node[MAXN];
int fa[MAXN];
bool die[MAXN];
int merge(int x, int y)
{
    if (!x) return y;
    if (!y) return x;
    if (node[y].data < node[x].data) swap(x, y);
    node[x].rs = merge(node[x].rs, y);
    if (node[node[x].ls].dis < node[node[x].rs].dis)
        swap(node[x].ls, node[x].rs);
    node[x].dis = node[node[x].rs].dis + 1;
    return x;
}
int find(int x)
{
    if (fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}
int main()
{
    node[0].dis = -1;
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int val;
        scanf("%d", &val);
        node[i] = Node(val, i);
        fa[i] = i;
    }
    while (m--)
    {
        int opt;
        scanf("%d", &opt);
        if (opt == 1)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if (die[x] || die[y]) continue;
            int rx = find(x), ry = find(y);
            if (rx == ry) continue;
            fa[rx] = fa[ry] = merge(rx, ry);
        }
        else
        {
            int x;
            scanf("%d", &x);
            if (die[x]) puts("-1");
            else
            {
                int root = find(x);
                die[root] = true;
                printf("%d\n", node[root].data.val);
                fa[root] = merge(node[root].ls, node[root].rs);
                fa[fa[root]] = fa[root];
            }
        }
    }
    return 0;
}

