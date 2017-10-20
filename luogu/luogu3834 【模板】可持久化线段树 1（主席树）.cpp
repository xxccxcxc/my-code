#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 200050, L = -1e9, R = 1e9;
struct Node
{
    int ls, rs, sum;
    Node(): ls(0), rs(0), sum(0){}
}node[MAXN * 40];
int top = 1, root[MAXN];

void insert(int x, int pre, int &cur, int l, int r)
{
    node[cur = top++] = node[pre];
    ++node[cur].sum;
    if (l == r) return;
    int mid = (l+r)>>1;
    if (x <= mid) insert(x, node[pre].ls, node[cur].ls, l, mid);
    else insert(x, node[pre].rs, node[cur].rs, mid+1, r);
}

int query(int lNode, int rNode, int l, int r, int k)
{
    if (l == r) return l;
    int lCnt = node[node[rNode].ls].sum - node[node[lNode].ls].sum, mid = (l+r)>>1;
    if (k <= lCnt) return query(node[lNode].ls, node[rNode].ls, l, mid, k);
    else return query(node[lNode].rs, node[rNode].rs, mid+1, r, k-lCnt);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int sr;
        scanf("%d", &sr);
        insert(sr, root[i-1], root[i], L, R);
    }
    while (m--)
    {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", query(root[l-1], root[r], L, R, k));
    }
    return 0;
}

