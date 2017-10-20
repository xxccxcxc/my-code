#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <vector>
using namespace std;
int T,n,ans;
int dao[105],ss[105],shu[105][6],st[105][6],kg[105][1005];
int zt[105][1005],dd[105];  //-2还没到，-1等待，>=0看书 
int us[1005];
int px[105];
bool cmp(int t1,int t2)
{
    if (dd[t1]!=dd[t2])return dd[t1]<dd[t2];
    return t1<t2;
}
int main()
{
    //freopen ("reading.in","r",stdin);
    //freopen ("reading.out","w",stdout);
    while (cin >>T>>n)
    {
        for (int i=1;i<=n;i++)dd[i]=T+1;
        memset (zt,255,sizeof(zt));
        memset (kg,0,sizeof(kg));
        memset (us,0,sizeof(us));
        ans=0;
        for (int i=1;i<=n;i++)
        {
            cin >>dao[i]>>ss[i];
            for (int j=1;j<=ss[i];j++)
              cin >>shu[i][j]>>st[i][j];
            for (int j=0;j<dao[i];j++)zt[i][j]=-2;
        }
        for (int j=0;j<T;j++)
        {
            for (int i=1;i<=n;i++)
            {
                if (zt[i][j]==-2)continue;
                if (dao[i]==j){dd[i]=j;continue;}
                if (j==0)continue;
                if (zt[i][j-1]>=0&&zt[i][j]==-1)
                {
                    us[zt[i][j-1]]=0;
                    dd[i]=j;
                }
            }
            memset (px,0,sizeof(px));
            for (int i=1;i<=n;i++)
            {
                if (zt[i][j]==-1)
                  px[++px[0]]=i;
            }
            sort (px+1,px+px[0]+1,cmp);
            for (int k=1;k<=px[0];k++)
            {
                int t=px[k];
                for (int i=1;i<=ss[t];i++)
                {
                    if (!us[shu[t][i]]&&!kg[t][shu[t][i]])
                    {
                        ++ans;
                        us[shu[t][i]]=1;
                        kg[t][shu[t][i]]=1;
                        for (int h=j;h<T&&h<j+st[t][i];h++)
                          zt[t][h]=shu[t][i];
                        dd[t]=T+1;
                        break;
                    }
                }
            }
        }
        cout <<ans<<endl;
    }
    return 0;
}
/*
10 4
1
2 1 4 2 5
3
1 2 4
7
3 2 2 1 3 3 2
9
1 4 2
*/
