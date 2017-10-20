#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <utility>
#include <map>
#include <stack>
#include <set>
#include <vector>
#include <queue>
using namespace std;
vector <int> a[100500];
int n,zz=1,b[100500],s[100500]={0},ans=0;
int main()
{
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        int r;
        cin >>b[i]>>r;
        for (int j=1;j<=r;j++)
        {
            int t;
            cin >>t;
            a[i].push_back(t);
            if (!s[t])++ans;
            ++s[t];
        }
        while (b[zz]<=b[i]-86400)
        {
            for (int j=0;j<a[zz].size();j++)
            {
                int t=a[zz][j];
                if (s[t])
                {
                    --s[t];
                    if (!s[t])--ans;
                }
            }
            ++zz;
        }
        cout <<ans<<endl;
    }
    return 0;
}


