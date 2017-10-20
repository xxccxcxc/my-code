#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 500050;
struct Trie
{
    int num;
    Trie *next[26];
    Trie(){ num = 0; memset(next, 0, sizeof(next)); }
}*root = new Trie;

int n;
int fa[N];
int du[N];

int insert(const string &s)
{
    Trie *u = root;
    for (int i = 0; i < s.size(); i++)
    {
        int v = s[i] - 'a';
        if (!u->next[v])
            u->next[v] = new Trie;
        u = u->next[v];
    }
    if (!u->num) u->num = ++n;
    return u->num;
}

int find(int x)
{
    if (fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}

void unionn(int x, int y)
{
    fa[find(x)] = find(y);
}

int main()
{
    string r1, r2;
    for (int i = 1; i <= N; i++)
        fa[i] = i;
    while (cin >> r1 >> r2)
    {
        int t1 = insert(r1), t2 = insert(r2);
        ++du[t1]; ++du[t2];
        unionn(t1, t2);
    }
    bool ok = true;
    int rt = find(1);
    for (int i = 2; i <= n && ok; i++)
        if (find(i) != rt) ok = false;
    if (ok)
    {
        int ds = 0;
        for (int i = 1; i <= n; i++)
            ds += du[i] % 2;
        if (ds && ds != 2) ok = false;
    }
    if (ok) puts("Possible");
    else puts("Impossible");
    return 0;
}

