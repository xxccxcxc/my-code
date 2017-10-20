#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    int n,x[10001]={0},y[10001]={0},xx,yy,s=0;
    cin >>n;
    for (int i=1;i<=n;i++)cin >>x[i]>>y[i];
    sort(x+1,x+n+1);
    sort(y+1,y+n+1);
    for (int i=1;i<=n;i++)x[i]=x[i]-i+1;
    sort(x+1,x+n+1);
    if (n%2){xx=x[n/2+1];yy=y[n/2+1];}
    else {xx=(x[n/2]+x[n/2+1])/2;yy=(y[n/2]+y[n/2+1])/2;}
    for (int i=1;i<=n;i++)s+=abs(xx-x[i])+abs(yy-y[i]);
    cout <<s;
    return 0;
}

