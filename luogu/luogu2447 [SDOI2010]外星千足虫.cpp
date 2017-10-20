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
int n,m;
bitset<1005> a[2005];
int goushi()
{
    int maxx=-1;
    for (int i=1,j=1;j<=n;i++,j++)
    {
        int tt=i;
        if (!a[i][j])
        {
            for (int k=i+1;k<=m;k++)
              if (a[k][j])
              {
                    maxx=max(maxx,k);
                    tt=k;
                    break;
              }
            if (tt==i)return -1;
            swap (a[i],a[tt]);
        }
        else maxx=max(maxx,i);
        for (int k=1;k<=m;k++)
          if (a[k][j]&&k!=i)
            a[k]^=a[i];
    }
    return maxx;
}
int main()
{
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        char r1[2001];
        bool r2;
        scanf ("%s %d",r1,&r2);
        for (int j=1;j<=n;j++)
          a[i][j]=r1[j-1]-'0';
        a[i][n+1]=r2;
    }
    /*for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n+1;j++)
          cout <<a[i][j]<<' ';
        cout <<endl;
    }*/
    int t=goushi();
    if (t==-1)printf("Cannot Determine\n");
    else
    {
        printf ("%d\n",t);
        for(int i=1;i<=n;i++)
          if(a[i][n+1])printf("?y7M#\n"); 
          else printf("Earth\n");
    }
    return 0;
}

