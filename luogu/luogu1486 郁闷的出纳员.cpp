#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f, MAXN = 100050, HEAD = 1, TAIL = 2;

struct Node
{
    int fa, ch[2], size, num, cnt;
    Node(){ fa = ch[0] = ch[1] = size = num = cnt = 0; }
}tr[MAXN];
int top = 1, root;
int ans = 0;

int newNode(int num)
{
    tr[top].num = num;
    tr[top].size = tr[top].cnt = 1;
    return top++;
}

bool getlr(int x)
{
    return tr[tr[x].fa].ch[1] == x;
}

void connect(int fa, int lr, int c)
{
    if (fa) tr[fa].ch[lr] = c;
    if (c) tr[c].fa = fa;
}

void update(int x)
{
    tr[x].size = tr[tr[x].ch[0]].size + tr[tr[x].ch[1]].size + tr[x].cnt;
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
    for (; tr[x].fa != tofa; rotate(x))
        if (tr[tr[x].fa].fa != tofa)
            rotate(getlr(x) ^ getlr(tr[x].fa) ? x : tr[x].fa);
    if (!tofa) root = x;
    update(x);
}

void insert(int num)
{
    int x = root, y = 0;
    while (x && tr[x].num != num)
        y = x, x = tr[x].ch[num > tr[x].num];
    if (x) ++tr[x].cnt;
    else
    {
        x = newNode(num);
        if (num == INF || num == -INF)
            tr[x].cnt = 0;
        connect(y, num > tr[y].num, x);
    }
    splay(x, 0);
}

int findNext(int num, int tofa=0)
{
    int x = root, ret = 0;
    while (x)
        if (num <= tr[x].num)
            ret = x, x = tr[x].ch[0];
        else x = tr[x].ch[1];
    splay(ret, tofa);
    return ret;
}

int kth(int k)
{
    if (k < 1 || k > tr[root].size) return -1;
    k = tr[root].size - k + 1;
    int x = root;
    while (x)
    {
        int lsize = tr[tr[x].ch[0]].size;
        if (k <= lsize) x = tr[x].ch[0];
        else if (k > lsize + tr[x].cnt)
            k -= lsize + tr[x].cnt, x = tr[x].ch[1];
        else break;
    }
    splay(x, 0);
    return tr[x].num;
}

void del(int minn)
{
    splay(HEAD, 0);
    int x = findNext(minn, root);
    ans += tr[tr[x].ch[0]].size;
    tr[x].ch[0] = 0;
    splay(x, 0);
}

int main()
{
    int m, mi, change = 0; 
    insert(-INF);
    insert(INF);
    cin >> m >> mi;
    char opt;
    int x;
    while (m--)
    {
        cin >> opt >> x;
        switch (opt)
        {
            case 'I': if (x >= mi) insert(x-change); break;
            case 'A': change += x; break;
            case 'S': change -= x; del(mi-change); break;
            case 'F':
                int tmp = kth(x);
                if (~tmp) tmp += change;
                cout << tmp << endl;
                break;
        }
    }
    cout << ans << endl;
    return 0;
}

