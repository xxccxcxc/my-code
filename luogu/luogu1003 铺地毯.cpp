#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;
int main()
{
    int n,x,y,x1[10001],y1[10001],x2[10001],y2[10001],as=-1;
    cin >>n;
    for (int i=1;i<=n;i++)cin >>x1[i]>>y1[i]>>x2[i]>>y2[i];
    cin >>x>>y;
    for (int i=1;i<=n;i++)
      if (x>=x1[i]&&x<=x1[i]+x2[i]&&y>=y1[i]&&y<=y1[i]+y2[i])as=i;
    cout <<as;

    return 0;
}
