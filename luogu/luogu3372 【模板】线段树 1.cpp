#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <climits>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <deque>
#include <map>
using namespace std;
typedef long long ll;
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
};
void Node::build(int *a,int left,int right)
{    
    l=left;
    r=right;
    if (left==right)
        sum=a[left];
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
    sum+=(right-left+1)*value;
    if (l==left&&r==right)
    {
        lazy+=value;
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
    if (lson!=NULL)sum+=lson->sum;
    if (rson!=NULL)sum+=rson->sum;
    return;
}
void Node::pushdown()
{
    if (lson!=NULL)
    {
        lson->sum+=lazy*(lson->r-lson->l+1);
        lson->lazy+=lazy;
    }
    if (rson!=NULL)
    {
        rson->sum+=lazy*(rson->r-rson->l+1);
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
    return lson->query(left,mid)+rson->query(mid+1,right);
}
int main()
{
    int n,m,a[100050]={0};
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n;i++)scanf ("%d",&a[i]);
    Node *root=new Node;
    root->build(a,1,n);
    for (int i=1;i<=m;i++)
    {
        int r1;
        scanf ("%d",&r1);
        if (r1==1)
        {
            int r2,r3;
            ll r4;
            scanf ("%d%d%lld",&r2,&r3,&r4);
            root->update(r2,r3,r4);
        }
        else
        {
            int r2,r3;
            scanf ("%d%d",&r2,&r3);
            printf ("%lld\n",root->query(r2,r3)); 
        }
    }
    return 0;
}
/*
5 5
1 5 4 2 3
2 2 4
1 2 3 2
2 3 4
1 1 5 1
2 1 4
*/
