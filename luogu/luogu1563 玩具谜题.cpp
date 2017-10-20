#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstring>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
using namespace std;
int main()
{
    int n,m;
    bool cx[100500]={0};
    string mz[100500];
    cin >>n>>m;
    for (int i=1;i<=n;i++)
      cin >>cx[i]>>mz[i];
    int t=1;
    for (int i=1;i<=m;i++)
    {
        bool zy;
        int gs;
        cin >>zy>>gs;
        if (zy==cx[t])
        {
            t-=gs;
            if (t<=0)t+=n;
        }
        else
        {
            t+=gs;
            if (t>n)t-=n;
        }
        //cout <<t<<' '<<mz[t]<<endl;
    }
    cout <<mz[t]<<endl;
    return 0;
}
//0朝内1朝外
//0左数1右数 
