#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAXN = 21050, L = 0, R = 1e9;
struct NodeS
{
    int l, r, root;
    NodeS():l(0), r(0), root(0){}
}s[MAXN*40];  //���λ���߶��� 
struct NodeT
{
    int l, r, cnt;
    NodeT():l(0), r(0), cnt(0){}
}t[MAXN*400];  //�ڲ�Ȩֵ�߶��� 
int n, m, root, sTop = 1, tTop = 1;
int a[MAXN], b[MAXN], bTop;

void addT(int &cur, int x, int add, int l, int r)  //�ڲ�Ȩֵ�߶�������x�ĳ��ִ�����add
{
    if (!cur) cur = tTop++;
    t[cur].cnt += add;
    if (l == r) return;
    int mid = (l+r)>>1;
    if (x <= mid) addT(t[cur].l, x, add, l, mid);
    else addT(t[cur].r, x, add, mid+1, r);
}

void addS(int &cur, int pos, int x, int add, int l, int r)  //���λ���߶�����posλx�ĳ��ִ�����add 
{
    if (!cur) cur = sTop++;
    addT(s[cur].root, x, add, L, R);
    if (l == r) return;
    int mid = (l+r)>>1;
    if (pos <= mid) addS(s[cur].l, pos, x, add, l, mid);
    else addS(s[cur].r, pos, x, add, mid+1, r);
}

void dfs(int cur, int l, int r, int curL, int curR)  //�ҳ�λ���߶�������ϳ�[l,r]���������� 
{
    if (!cur) return;
    if (l == curL && r == curR)
    {
        b[bTop++] = s[cur].root;
        return;
    }
    int mid = (curL+curR)>>1;
    if (l <= mid) dfs(s[cur].l, l, min(r, mid), curL, mid);
    if (r > mid) dfs(s[cur].r, max(l, mid+1), r, mid+1, curR);
}

int query1(int l, int r, int k)  //��l��r�������������ҵ�k�� 
{
    if (l == r) return l;
    int mid = (l+r)>>1, lCnt = 0;
    for (int i = 0; i < bTop; i++)
        lCnt += t[t[b[i]].l].cnt; 
    if (k <= lCnt)
    {
        for (int i = 0; i < bTop; i++)
            b[i] = t[b[i]].l;
        return query1(l, mid, k);
    }
    else
    {
        for (int i = 0; i < bTop; i++)
            b[i] = t[b[i]].r;
        return query1(mid+1, r, k-lCnt);
    }
}

int query(int l, int r, int k)  //��l��r��λ���������ҵ�k�� 
{
    bTop = 0;
    dfs(root, l, r, 1, n);
    return query1(L, R, k);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a+i);
        addS(root, i, a[i], 1, 1, n);
    }
    while (m--)
    {
        char ch;
        cin >> ch;
        if (ch == 'Q')  //ѯ�ʵ�k��  
        {
            int l, r, k;
            scanf("%d%d%d", &l, &r, &k);
            printf("%d\n", query(l, r, k));
        }
        else //�޸��� 
        {
            int pos, num;
            scanf("%d%d", &pos, &num);
            addS(root, pos, a[pos], -1, 1, n);
            addS(root, pos, (a[pos] = num), 1, 1, n);
        }
    }
    return 0;
}

