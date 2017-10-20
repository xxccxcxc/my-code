#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <utility>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#define L(n) (n<<1)
#define R(n) ((n<<1)|1)
#define MIN_INT -0x7fffffff
#define MAXN 200000
using namespace std;
int m,mo,a[4*MAXN+5];
void build(int l,int r,int t)
{
    //cout <<l<<' '<<r<<' '<<t<<endl; 
    a[t]=MIN_INT;
    if (l==r)return;
    int mid=(l+r)>>1;
    build(l,mid,L(t));
    build(mid+1,r,R(t)); 
}
void update(int l,int r,int t,int x,int y)
{
    if (l==r){a[t]=y;return;}
    int mid=(l+r)>>1;
    if (x<=mid)update(l,mid,L(t),x,y);
    else update(mid+1,r,R(t),x,y);
    a[t]=max(a[L(t)],a[R(t)]);
}
int query(int l,int r,int t,int x,int y)
{
    if (x<=l&&r<=y)return a[t];
    int mid=(l+r)>>1;
    if (y<=mid)return query(l,mid,L(t),x,y);
    if (x>mid)return query(mid+1,r,R(t),x,y);
    return max(query(l,mid,L(t),x,mid),query(mid+1,r,R(t),mid+1,y));
}
int main()
{
    cin >>m>>mo;
    int t=0,tt=0;
    build(1,MAXN,1);
    for (int i=1;i<=m;i++)
    {
        char ch;int r;
        cin >>ch>>r;
        if (ch=='A'){++t;update(1,MAXN,1,t,(r+tt)%mo);}
        else {tt=query(1,MAXN,1,t-r+1,t);cout <<tt<<endl;} 
    }
     return 0;
}

