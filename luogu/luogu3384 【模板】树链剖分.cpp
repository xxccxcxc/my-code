#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAXN = 200050;
int mo;
class Node
{
    private:
        int l,r;
        ll sum,lazy;
        Node *lson,*rson;
    public:
        Node():l(0),r(0),sum(0),lazy(0),lson(NULL),rson(NULL){}
        
        void build(int *a,int left,int right);
        void update(int left,int right,ll value);
        void pushup();
        void pushdown();
        ll query(int left,int right);
        void del();
}*root = new Node;
void Node::build(int *a,int left,int right)
{    
    l=left;
    r=right;
    if (left==right)
        sum=a[left]%mo;
    else
    {
        int mid=(left+right)>>1;
        lson=new Node;
        rson=new Node;
        lson->build(a,left,mid);
        rson->build(a,mid+1,right);
        pushup();
    }
    return;
}
void Node::update(int left,int right,ll value)
{
    sum=(sum+(right-left+1)*value)%mo;
    if (l==left&&r==right)
    {
        lazy=(lazy+value)%mo;
        return;
    }
    if (lazy)pushdown();
    int mid=(l+r)>>1;
    if (right<=mid)lson->update(left,right,value);
    else if (left>mid)rson->update(left,right,value);
    else
    {
        lson->update(left,mid,value);
        rson->update(mid+1,right,value);
    }
    return;
}
void Node::pushup()
{
    if (lson!=NULL)sum=(sum+lson->sum)%mo;
    if (rson!=NULL)sum=(sum+rson->sum)%mo;
    return;
}
void Node::pushdown()
{
    if (lson!=NULL)
    {
        lson->sum+=lazy*(lson->r-lson->l+1);
        lson->sum%=mo;
        lson->lazy+=lazy;
    }
    if (rson!=NULL)
    {
        rson->sum+=lazy*(rson->r-rson->l+1);
        rson->sum%=mo;
        rson->lazy+=lazy;
    }
    lazy=0;
}
ll Node::query(int left,int right)
{
    if (l==left&&r==right)return sum;
    if (lazy)pushdown();
    int mid=(l+r)>>1;
    if (right<=mid)return lson->query(left,right);
    if (left>mid)return rson->query(left,right);
    return (lson->query(left,mid)+rson->query(mid+1,right))%mo;
}
void Node::del()
{
    if (lson) lson->del();
    if (rson) rson->del();
    delete this;
}

struct Edge
{
    int to, next;
}edge[MAXN*2];
int e, head[MAXN];

struct SpNode
{
    int fa, size, son, deep, id, top;
}sp[MAXN];

int n, m, rt;
int dfsCnt = 1, a[MAXN], b[MAXN];

void add1(int u, int v)
{
    edge[e].to = v;
    edge[e].next = head[u];
    head[u] = e++;
}

void add(int u, int v){add1(u, v); add1(v, u);}

void dfs1(int u, int fa)
{
    sp[u].fa = fa;
    sp[u].size = 1;
    sp[u].deep = sp[fa].deep+1;
    sp[u].son = 0;
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fa) continue;
        dfs1(v, u);
        sp[u].size += sp[v].size;
        if (sp[u].son == 0 || sp[v].size > sp[sp[u].son].size)
            sp[u].son = v;
    }
}

void dfs2(int u, int curHead)
{
    sp[u].top = curHead;
    sp[u].id = dfsCnt++;
    b[sp[u].id] = a[u];
    if (!sp[u].son) return;
    dfs2(sp[u].son, curHead);
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v != sp[u].fa && v != sp[u].son)
            dfs2(v, v);
    }
}

void pathModify(int u, int v, int add)
{
    int tu = sp[u].top, tv = sp[v].top;
    while (tu != tv)
    {
        if (sp[tu].deep < sp[tv].deep)
        {
            swap(u, v);
            swap(tu, tv);
        }
        root->update(sp[tu].id, sp[u].id, add);
        u = sp[tu].fa;
        tu = sp[u].top;
    }
    if (sp[u].deep < sp[v].deep) swap(u, v);
    root->update(sp[v].id, sp[u].id, add);
}

int pathSum(int u, int v)
{
    ll ret = 0;
    int tu = sp[u].top, tv = sp[v].top;
    while (tu != tv)
    {
        if (sp[tu].deep < sp[tv].deep)
        {
            swap(u, v);
            swap(tu, tv);
        }
        ret += root->query(sp[tu].id, sp[u].id);
        ret %= mo;
        u = sp[tu].fa;
        tu = sp[u].top;
    }
    if (sp[u].deep < sp[v].deep) swap(u, v);
    ret += root->query(sp[v].id, sp[u].id);
    return ret % mo;
}

void treeModify(int u, int add)
{
    root->update(sp[u].id, sp[u].id + sp[u].size - 1, add);
}

int treeSum(int u)
{
    return root->query(sp[u].id, sp[u].id + sp[u].size - 1);
}

int main()
{
    memset(head, -1, sizeof(head));
    int n, m, rt;
    scanf("%d%d%d%d", &n, &m, &rt, &mo);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
    }
    sp[0].deep = 0;
    dfs1(rt, 0);
    dfs2(rt, rt);
    root->build(b, 1, n);
    while (m--)
    {
        int sr;
        scanf("%d", &sr);
        if (sr == 1)
        {
            int u, v, add;
            scanf("%d%d%d", &u, &v, &add);
            pathModify(u, v, add);
        }
        else if (sr == 2)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            printf("%d\n", pathSum(u, v));
        }
        else if (sr == 3)
        {
            int u, add;
            scanf("%d%d", &u, &add);
            treeModify(u, add);
        }
        else
        {
            int u;
            scanf("%d", &u);
            printf("%d\n", treeSum(u));
        }
    }
    root->del();
    return 0;
}

