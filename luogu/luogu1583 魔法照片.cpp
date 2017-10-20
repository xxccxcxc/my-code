#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
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
using namespace std;
struct ren
{
    int bh,w;
}a[20005];
bool cmp(ren t1,ren t2)
{
    if (t1.w!=t2.w)return t1.w>t2.w;
    return t1.bh<t2.bh;
}
int main()
{
    int n,m,e[11];
    cin >>n>>m;
    for (int i=1;i<=10;i++)cin >>e[i];
    for (int i=1;i<=n;i++)
    {
        a[i].bh=i;
        cin >>a[i].w;
    }
    sort (a+1,a+n+1,cmp);
    for (int i=1;i<=n;i++)a[i].w+=e[(i-1)%10+1];
    sort (a+1,a+n+1,cmp);
    for (int i=1;i<=m;i++)cout <<a[i].bh<<' ';
    return 0;
}
/*
10 10
2 4 6 8 10 12 14 16 18 20
1 2 3 4 5 6 7 8 9 10
*/
