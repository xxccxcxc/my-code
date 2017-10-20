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
using namespace std;
int main()
{
    int n,m,x[2005],y[2005],xx[2005],yy[2005];
    cin >>m>>n;
    for (int i=1;i<=m;i++)cin >>x[i]>>y[i]>>xx[i]>>yy[i];
    for (int i=1;i<=n;i++)
    {
        int tx,ty;
        cin >>tx>>ty;
        int lzx=0,s=0,l=0;
        for (int j=1;j<=m;j++)
        {
            if (tx>=x[j]&&tx<=xx[j]&&ty>=y[j]&&ty<=yy[j])
            {
                lzx=1;
                ++s;
                l=j;
            }
        }
        if (!lzx)cout <<"NO"<<endl;
        else cout <<"YES"<<' '<<s<<' '<<l<<endl;
    }
    return 0;
}

