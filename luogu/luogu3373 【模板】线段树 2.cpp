#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <utility>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#define L(u) (u<<1)
#define R(u) (u<<1|1)
#define MAXN 105000
#define sys system("pause")
using namespace std;
typedef long long ll;
struct node
{
    int l,r,ch;
    ll c,j,s;
    node(){l=r=ch=j=s=0;c=1;}
}a[MAXN*4];
int n,m;
ll mo;
ll shu[MAXN];
void build(int l,int r,int u)
{
    a[u].l=l;a[u].r=r;a[u].ch=a[u].r-a[u].l+1;a[u].c=1;a[u].s=a[u].j=0;
    if (l==r){a[u].s=shu[l];return;}
    int mid=(l+r)>>1;
    build(l,mid,L(u));
    build(mid+1,r,R(u));
    a[u].s=(a[L(u)].s+a[R(u)].s)%mo;
}
void pushdown(int u)
{
    a[L(u)].s=(a[L(u)].s*a[u].c+a[u].j*a[L(u)].ch)%mo;
    a[R(u)].s=(a[R(u)].s*a[u].c+a[u].j*a[R(u)].ch)%mo;
    a[L(u)].c*=a[u].c;a[L(u)].j*=a[u].c;a[L(u)].j+=a[u].j;
    a[L(u)].c%=mo;a[L(u)].j%=mo;
    a[R(u)].c*=a[u].c;a[R(u)].j*=a[u].c;a[R(u)].j+=a[u].j;
    a[R(u)].c%=mo;a[R(u)].j%=mo;
    a[u].c=1;a[u].j=0;
}
void cheng(int u,int l,int r,ll w)
{
    if (l==a[u].l&&r==a[u].r)
    {
        a[u].s=a[u].s*w%mo;
        a[u].c=a[u].c*w%mo;
        a[u].j=a[u].j*w%mo;
        return;
    }
    pushdown(u);
    int mid=(a[u].l+a[u].r)>>1;
    if (r<=mid)cheng(L(u),l,r,w);
    else if (l>mid)cheng(R(u),l,r,w);
    else
    {
        cheng(L(u),l,mid,w);
        cheng(R(u),mid+1,r,w);
    }
    a[u].s=(a[L(u)].s+a[R(u)].s)%mo;
}
void jia(int u,int l,int r,ll w)
{
    if (l==a[u].l&&r==a[u].r)
    {
        a[u].s=(a[u].s+w*a[u].ch)%mo;
        a[u].j=(a[u].j+w)%mo;
        return;
    }
    pushdown(u);
    int mid=(a[u].l+a[u].r)>>1;
    if (r<=mid)jia(L(u),l,r,w);
    else if (l>mid)jia(R(u),l,r,w);
    else
    {
        jia(L(u),l,mid,w);
        jia(R(u),mid+1,r,w);
    }
    a[u].s=a[L(u)].s+a[R(u)].s;
}
ll cx(int u,int l,int r)
{
    if (a[u].l==l&&a[u].r==r)return a[u].s;
    pushdown(u);
    int mid=(a[u].l+a[u].r)>>1;
    if (r<=mid)return cx(L(u),l,r)%mo;
    if (l>mid)return cx(R(u),l,r)%mo;
    return (cx(L(u),l,mid)+cx(R(u),mid+1,r))%mo;
}
int main()
{
    scanf ("%d%d%d",&n,&m,&mo);
    for (int i=1;i<=n;i++)scanf ("%lld",&shu[i]);
    build(1,n,1);
    for (int i=1;i<=m;i++)
    {
        int r,r1,r2;
        ll r3;
        cin >>r;
        if (r==1)
        {
            cin >>r1>>r2>>r3;
            cheng(1,r1,r2,r3);
        }
        if (r==2)
        {
            cin >>r1>>r2>>r3;
            jia(1,r1,r2,r3);
        }
        if (r==3)
        {
            cin >>r1>>r2;
            cout <<(long long)((cx(1,r1,r2)%mo+mo)%mo)<<endl;
        }
    }
    return 0;
}
