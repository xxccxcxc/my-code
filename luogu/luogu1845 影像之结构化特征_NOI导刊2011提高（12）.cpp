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
struct dian
{
    int x,y;
    dian(int xxx,int yyy){x=xxx;y=yyy;}
};
int n,ans=0;
bool a[1005][1005];
int b[1005][1005],c[1000005];
int dx[]={0,-1,0,1,0},dy[]={0,0,1,0,-1};
bool yj(int px,int py)
{
    return px<1||px>n||py<1||py>n;
}
void bfs(int sx,int sy)
{
    ++ans;
    b[sx][sy]=1;
    int maxx=1;
    queue <dian> q;
    q.push(dian(sx,sy));
    while (!q.empty())
    {
        dian u=q.front();
        q.pop();
        for (int i=1;i<=4;i++)
        {
            int xx=u.x+dx[i],yy=u.y+dy[i];
            if (!yj(xx,yy)&&a[xx][yy]&&!b[xx][yy])
            {
                q.push(dian(xx,yy));
                b[xx][yy]=b[u.x][u.y]+1;
                maxx=max(maxx,b[xx][yy]);
            }
        }
    }
    c[++c[0]]=maxx;
}
int main()
{
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        string sr;
        cin >>sr;
        for (int j=1;j<=n;j++)
          a[i][j]=(sr[j-1]=='1');
    }
    /*for (int i=1;i<=n;i++){
      for (int j=1;j<=n;j++)
        cout <<a[i][j]<<' ';cout <<endl;}*/
    for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
        if (a[i][j]&&!b[i][j])
          bfs(i,j);
    /*for (int i=1;i<=n;i++){
      for (int j=1;j<=n;j++)
        printf ("%-3d",b[i][j]);cout <<endl;}*/
    sort (c+1,c+c[0]+1);
    cout <<ans<<endl;
    for (int i=1;i<=c[0];i++)
      cout <<c[i]<<endl;
    return 0;
}
/*
10
0000000000
0011110000
0000010000
0011111000
0010110100
0010010110
0011110010
0100010010
0100000110
0100000000
*/
