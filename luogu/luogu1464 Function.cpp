#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
using namespace std;
int a[10001],b[10001],c[10001],f[21][21][21],ans[10001],t;
int dg(int x,int y,int z)
{
    if (x<=0||y<=0||z<=0)return 1;
    if (x>20||y>20||z>20)return dg(20,20,20);
    if (f[x][y][z])return f[x][y][z];
    if (x<y&&y<z)f[x][y][z]=dg(x,y,z-1)+dg(x,y-1,z-1)-dg(x,y-1,z);
    else f[x][y][z]=dg(x-1,y,z)+dg(x-1,y-1,z)+dg(x-1,y,z-1)-dg(x-1,y-1,z-1);
    return f[x][y][z];
}
int main()
{
    while (1)
    {
        cin >>a[++t]>>b[t]>>c[t];
        if (a[t]==-1&&b[t]==-1&&c[t]==-1){--t;break;}
        ans[t]=dg(a[t],b[t],c[t]);
    }
    for (int i=1;i<=t;i++)printf("w(%d, %d, %d) = %d\n",a[i],b[i],c[i],ans[i]);
    return 0;
}

