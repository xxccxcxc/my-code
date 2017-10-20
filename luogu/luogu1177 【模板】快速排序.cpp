#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

struct Trie
{
    int exist;
    int num;
    Trie *node[10];
    Trie(){ exist = num = 0; memset(node, 0, sizeof(node)); }
}*root = new(Trie);

void Trie_insert(string s)
{
    Trie *u = root;
    for (int i = 0; i < s.size(); i++)
    {
        int v = s[i] - '0', t = u->num;
        if (!u->node[v])
            u->node[v] = new(Trie);
        u = u->node[v];
        u->num = t * 10 + s[i] - '0';
    }
    u->exist++;
}

void Trie_bfs()
{
    queue<Trie*> q;
    q.push(root);
    while (!q.empty())
    {
        Trie *u = q.front(); q.pop();
        if (u->exist)
            for (int i = 1; i <= u->exist; i++)
                cout << u->num << ' ';
        for (int i = 0; i < 10; i++)
            if (u->node[i])
                q.push(u->node[i]);
    }
}

int main()
{
    int n;
    scanf ("%d", &n);
    string s;
    while (n--)
    {
        cin >> s;
        Trie_insert(s);
    }
    Trie_bfs();
    return 0;
}

