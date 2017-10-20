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
struct node{
    int a[4][4];
    node (int aa[4][4]){for (int i=1;i<=3;i++)for (int j=1;j<=3;j++)a[i][j]=aa[i][j];}
    node (){for (int i=1;i<=3;i++)for (int j=1;j<=3;j++)a[i][j]=0;}
    int kt()
    {
        int jc[]={1,1,2,6,24,120,720,5040,40320};
        int tt[10];
        for (int i=1;i<=3;i++)
          for (int j=1;j<=3;j++)
            tt[(i-1)*3+j]=a[i][j];
        int s=0,ttt;
        for (int i=1;i<=9;i++)
        {
            ttt=0;
            for (int j=i+1;j<=9;j++)
              if (tt[i]>tt[j])
                ++ttt;
            s+=ttt*jc[9-i];
        }
        return s;
    }
};
int st[4][4];
int ed[4][4]={
{0},
{0,1,2,3},
{0,8,0,4},
{0,7,6,5}};
int dx[]={0,-1,0,1,0},dy[]={0,0,1,0,-1};
int p[1000000]={0},b[1000000]={0};
void init()
{
    char chr;
    for (int i=1;i<=3;i++)
      for (int j=1;j<=3;j++)
      {
            cin >>chr;
            st[i][j]=chr-'0';
      }
}
bool yj(int t1,int t2)
{
    return t1<1||t1>3||t2<1||t2>3;
}
node swapp(int ta[4][4],int x1,int y1,int x2,int y2)
{
    node res;
    for (int i=1;i<=3;i++)
      for (int j=1;j<=3;j++)
        res.a[i][j]=ta[i][j];
    swap(res.a[x1][y1],res.a[x2][y2]);
    return res;
}
void bfs()
{
    queue <node> q1,q2;
    node stt=node(st);node edd=node(ed);
    q1.push(stt);q2.push(edd);
    p[stt.kt()]=1;p[edd.kt()]=2;
    while (!q1.empty()&&!q2.empty())
    {
        int ok=0;
        if (!q1.empty())
        {
            node u=q1.front();
            q1.pop();
            for (int x=1;x<=3;x++)
              for (int y=1;y<=3;y++)
                if (!u.a[x][y])
                {
                    for (int i=1;i<=4;i++)
                    {
                        int xx=x+dx[i],yy=y+dy[i];
                        if (yj(xx,yy))continue;
                        node v=swapp(u.a,x,y,xx,yy);
                        int t1=u.kt(),t2=v.kt();
                        if (!p[t2])
                        {
                            p[t2]=1;
                            b[t2]=b[t1]+1;
                            q1.push(v);
                        }
                        else if (p[t2]==2)
                        {
                            cout <<b[t1]+b[t2]+1;
                            ok=1;
                            break;
                        }
                    }
                }
        }
        if (!q2.empty())
        {
            node u=q2.front();
            q2.pop();
            for (int x=1;x<=3;x++)
              for (int y=1;y<=3;y++)
                if (!u.a[x][y])
                {
                    for (int i=1;i<=4;i++)
                    {
                        int xx=x+dx[i],yy=y+dy[i];
                        if (yj(xx,yy))continue;
                        node v=swapp(u.a,x,y,xx,yy);
                        int t1=u.kt(),t2=v.kt();
                        if (!p[t2])
                        {
                            p[t2]=2;
                            b[t2]=b[t1]+1;
                            q2.push(v);
                        }
                        else if (p[t2]==1)
                        {
                            cout <<b[t1]+b[t2]+1;
                            ok=1;
                            break;
                        }
                    }
                }
        }
        if (ok)break;
    }
}
int main()
{
    init();
    bfs();
    return 0;
}

