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
int gcd(int a,int b)
{
    if (!b)return a;
    return gcd(b,a%b);
}
int main()
{
    int T;
    scanf ("%d",&T);
    while (T--)
    {
        int a0,a1,b0,b1,ans=0;
        scanf ("%d%d%d%d",&a0,&a1,&b0,&b1);
        for (int i=1;i*i<=b1;i++)
          if (b1%i==0)
          {
                int x=i;
                if (x%a1==0&&gcd(b1/b0,b1/x)==1&&gcd(x/a1,a0/a1)==1)++ans;
                if (i*i==b1)continue;
                x=b1/i;
                if (x%a1==0&&gcd(b1/b0,b1/x)==1&&gcd(x/a1,a0/a1)==1)++ans;
          }
        printf ("%d\n",ans);
    }
     return 0;
}

