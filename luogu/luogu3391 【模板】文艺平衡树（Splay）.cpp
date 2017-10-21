#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int INF = 0x3f3f3f3f, MAXN = 100050;

struct Node
{
    int fa, ch[2], size, num;
    bool rev;
    Node(){ fa = ch[0] = ch[1] = size = num = 0; rev = false; }
}tr[MAXN];
int top = 1;
int root;

int newNode(int num)
{
    tr[top].num = num;
    tr[top].size = 1;
    return top++;
}

bool getlr(int x)
{
    return tr[tr[x].fa].ch[1] == x;
}

void connect(int f, bool lr, int c)
{
    if (f) tr[f].ch[lr] = c;
    if (c) tr[c].fa = f;
}

void update(int x)
{
    tr[x].size = tr[tr[x].ch[0]].size + tr[tr[x].ch[1]].size + 1;
}

void putrev(int x)
{
    if (!x) return;
    tr[x].rev ^= 1;
    swap(tr[x].ch[0], tr[x].ch[1]);
}

void pushdown(int x)
{
    if (tr[x].rev)
    {
        tr[x].rev = false;
        putrev(tr[x].ch[0]);
        putrev(tr[x].ch[1]);
    }
}

void rotate(int x)
{
    bool lr = !getlr(x);
    int y = tr[x].fa, z = tr[y].fa;
    connect(z, getlr(y), x);
    connect(y, !lr, tr[x].ch[lr]);
    connect(x, lr, y);
    update(y);
}

void splay(int x, int tofa)
{
    for (pushdown(x); tr[x].fa != tofa; rotate(x))
        if (tr[tr[x].fa].fa != tofa)
            rotate(getlr(x) ^ getlr(tr[x].fa) ? x : tr[x].fa);
    if (!tofa) root = x;
    update(x);
}

void insert(int num)
{
    int x = root, y = 0;
    while (x) y = x, x = tr[x].ch[1];
    connect(y, 1, (x = newNode(num)));
    splay(x, 0);
}

int get(int k, int to)  // 把第k个节点提到to的位置
{
    ++k;
    int x = root;
    while (x)
    {
        pushdown(x);
        int lsize = tr[tr[x].ch[0]].size;
        if (k == lsize + 1)
        {
            splay(x, tr[to].fa);
            return tr[x].num;
        }
        if (k <= lsize) x = tr[x].ch[0];
        else k -= lsize+1, x = tr[x].ch[1];
    }
}

void rev(int l, int r)
{
    get(l-1, root);
    get(r+1, tr[root].ch[1]);
    putrev(tr[tr[root].ch[1]].ch[0]);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    insert(0);
    for (int i = 1; i <= n; i++)
        insert(i);
    insert(0);
    for (;m--;)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        rev(l, r);
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", get(i, root));
    return 0;
}
/*
5 3
1 3
1 3
1 4
*/
