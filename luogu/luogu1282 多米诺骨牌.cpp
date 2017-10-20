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
using namespace std;
int n,a[1005],f[1005][12500],sr,s,ss;
const int PY=6000;
int main()
{
    memset (f,127,sizeof(f));
    scanf ("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf ("%d%d",&a[i],&sr);
        a[i]-=sr;ss+=a[i];s+=abs(a[i]);
    }
    //for (int i=1;i<=n;i++)cout <<a[i]<<' ';
    //cout <<endl<<s<<' '<<ss<<endl;
    if (ss==0){cout <<0;return 0;}
    f[0][PY+ss]=0;
    for (int i=1;i<=n;i++)
      for (int j=-5*n;j<=5*n;j++)
        f[i][j+PY]=min(f[i-1][j+PY],f[i-1][j+a[i]*2+PY]+1);
    //for (int i=-10;i<=10;i++)cout <<i<<' '<<f[n][PY+i]<<endl;
    for (int i=0;i<=5*n;i++)
    {
        int t=min(f[n][PY+i],f[n][PY-i]);
        if (t<10000000){cout <<t;return 0;}
    }
    cout <<"error";
    return 0;
}
