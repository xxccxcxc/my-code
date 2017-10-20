#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
using namespace std;
int n,m,sr,sr2[1001],sr3,rd[1001]={0},cd[1001]={0},c[1001][1001]={0},p[1001][1001]={0};
int main()
{
    ios::sync_with_stdio(false);
    cin >>n>>m;
    for (int i=1;i<=m;i++)
    {
        cin >>sr;
        for (int j=1;j<=sr;j++)
          cin >>sr2[j];
        for (int j=2;j<=sr;j++)
          for (int k=sr2[j-1]+1;k<sr2[j];k++)
            for (int l=1;l<=sr;l++)
            {
                if (!p[k][sr2[l]]){++rd[sr2[l]];c[k][++cd[k]]=sr2[l];p[k][sr2[l]]=1;}
            }
    }
    /*for (int i=1;i<=n;i++){
      for (int j=1;j<=cd[i];j++)
        cout <<c[i][j]<<' ';
      cout <<cd[i]<<endl;
    }cout <<endl;*/
    //for (int i=1;i<=n;i++)cout <<rd[i]<<endl;cout <<endl;
    int h=0,t=0,d[10001]={0},ans=0;
    for (int i=1;i<=n;i++)
      if (rd[i]==0)
        {d[++t]=i;rd[i]=-1;}
    while(h<t)
    {
        ++ans;
        ++h;
        //for (int i=h;i<=t;i++)cout <<d[i]<<' ';
        for (int i=h;i<=t;i++)
          for (int j=1;j<=cd[d[i]];j++)
            --rd[c[d[i]][j]];
        h=t;
        //for (int i=1;i<=n;i++)cout <<rd[i]<<endl;cout <<endl;
        for (int i=1;i<=n;i++)
          if (rd[i]==0)
            {d[++t]=i;rd[i]=-1;}
    }
    cout <<ans;
    return 0;
}

