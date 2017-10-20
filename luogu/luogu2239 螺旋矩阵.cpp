#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstring>
using namespace std;
int minn(int a,int b)
{
    if (a<b)return a;
    return b;
}
int main()
{
    ios::sync_with_stdio(false);
    int n,x,y,z,bg=0,tx,ty,p=0,tt;
    cin >>n>>x>>y;
    z=minn(minn(x,y),minn(n-x+1,n-y+1));
    tt=n;
    for (int i=1;i<z;i++){bg+=4*tt-4;tt-=2;}
    tx=ty=z;
    bg+=1;
    while (ty+1<=n-z+1&&p!=1){if (tx==x&&ty==y){p=1;break;}++ty;++bg;}
    while (tx+1<=n-z+1&&p!=1){if (tx==x&&ty==y){p=1;break;}++tx;++bg;}
    while (ty-1>=z&&p!=1){if (tx==x&&ty==y){p=1;break;}--ty;++bg;}
    while (tx-1>1&&p!=1){if (tx==x&&ty==y){p=1;break;}--tx;++bg;}
    cout <<bg<<endl;
    return 0;
}

