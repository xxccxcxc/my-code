#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#define L(u)(u<<1)
#define R(u)(u<<1|1)
using namespace std;
struct tree{
    int l,r;
    bool sum;
}node[40005];
int n,m,ll,rr;
int query(int u)
{
    if (node[u].sum)return node[u].r-node[u].l+1;
    if (node[u].l==node[u].r)return 0;
    return query(L(u))+query(R(u));
}
void update(int u,int left,int right)
{
    if (left<=node[u].l&&node[u].r<=right)
    {
        node[u].sum=1;
        return;
    }
    int mid=(node[u].l+node[u].r)>>1;
    if (right<=mid)update(L(u),left,right);
    else if (left>mid)update(R(u),left,right);
    else
    {
        update(L(u),left,mid);
        update(R(u),mid+1,right);
    }
    return;
}
void build(int u,int left,int right)
{
    node[u].l=left;
    node[u].r=right;
    node[u].sum=0;
    if (node[u].l==node[u].r)return;
    int mid=(left+right)>>1;
    build(L(u),left,mid);
    build(R(u),mid+1,right);
    return;
}
int main()
{
    cin >>n>>m;
    build(1,0,n);
    for (int i=1;i<=m;i++)
    {
        cin >>ll>>rr;
        update(1,ll,rr);
    }
    cout <<n+1-query(1);
    return 0;
}

