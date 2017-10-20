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
int main()
{
    int n,a[100005]={0},s=0,f[200005],p1=0,p2=0;
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        bool r;
        cin >>r;
        if (r){a[i]=a[i-1]+1;p1=1;}
        else{a[i]=a[i-1]-1;p2=1;}
    }
    if (!p1&&!p2){cout <<0;return 0;}
    memset (f,-1,sizeof(f));f[n]=0;
    for (int i=1;i<=n;i++)
      if (f[a[i]+n]==-1)f[a[i]+n]=i;
      else s=max(s,i-f[a[i]+n]);
    cout <<s;
    return 0;
}

