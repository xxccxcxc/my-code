#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
using namespace std;
int n,ans;
int sr;
int t=0,a[500005];
int main()
{
    scanf ("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf ("%d",&sr);
        if (!t)a[++t]=sr;
        else if (sr<a[t]){a[++t]=sr;++ans;}
        else
        {
            while (t&&sr>a[t])
            {
                --t;
                ++ans;
            }
            int tt=t;
            while (tt&&sr==a[tt])
            {
                --tt;
                ++ans;
            }
            if (tt)++ans;
            a[++t]=sr;
        }
    }
    printf ("%d",ans);
    return 0;
}


