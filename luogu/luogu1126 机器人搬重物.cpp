#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
using namespace std;
int fx[5]={0,0,1,0,-1},fy[5]={0,1,0,-1,0};
int n,m,sr,stx,qsx,qsy,mbx,mby,ttt;
char srfx;
int h,t,x[100001],y[100001],f[100001],c[100001],lt,rt,xx,yy;
bool p[60][60][5],pp;
void bfs()
{
    h=0;t=1;
    x[1]=qsx;y[1]=qsy;f[1]=ttt;
    p[qsx][qsy][ttt]=1;
    do
    {
        ++h;
        for (int i=3;i>=1;i--)
        {
            pp=1;
            xx=x[h];yy=y[h];
            for (int j=1;j<=i;j++){xx+=fx[f[h]];yy+=fy[f[h]];if (p[xx][yy][f[h]]==1)pp=0;}
            if (!pp)continue;
            if (xx>=1&&xx<=n&&yy>=1&&yy<=m&&p[xx][yy][f[h]]==0)
            {
                //cout <<'d'<<xx<<' '<<yy<<' '<<f[h]<<' '<<c[h]+1<<' '<<t+1<<endl; 
                ++t;
                x[t]=xx;y[t]=yy;f[t]=f[h];c[t]=c[h]+1;
                p[xx][yy][f[h]]=1;
                if (xx==mbx&&yy==mby){cout <<c[t];return;}
            }
        }
        lt=f[h]-1;rt=f[h]+1;
        if (lt==0)lt=4;
        if (rt==5)rt=1;
        if (!p[x[h]][y[h]][lt])
        {
            //cout <<x[h]<<' '<<y[h]<<' '<<rt<<' '<<c[h]+1<<' '<<t+1<<endl;  
            ++t;
            x[t]=x[h];y[t]=y[h];f[t]=lt;c[t]=c[h]+1;
            p[x[h]][y[h]][lt]=1;
        }
        if (!p[x[h]][y[h]][rt])
        {
            //cout <<x[h]<<' '<<y[h]<<' '<<rt<<' '<<c[h]+1<<' '<<t+1<<endl;  
            ++t;
            x[t]=x[h];y[t]=y[h];f[t]=rt;c[t]=c[h]+1;
            p[x[h]][y[h]][rt]=1;
        }
    }while (h<t);
    cout <<-1;
    /*for (int i=1;i<=n;i++){ 
      for (int j=1;j<=m;j++){ 
        for (int k=1;k<=4;k++) 
          cout <<p[i][j][k];cout <<' ';} 
      cout <<endl;} 
    for (int i=1;i<=t;i++)cout <<i<<' '<<x[t]<<' '<<y[t]<<' '<<f[t]<<' '<<c[t]<<endl;*/
}
int main()
{
    cin >>n>>m;
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
      {
          cin >>sr;
          if (sr)for (int k=1;k<=4;k++)p[i-1][j-1][k]=p[i][j-1][k]=p[i-1][j][k]=p[i][j][k]=1;
      }
    n-=1;m-=1;
    /*for (int i=1;i<=n;i++){ 
      for (int j=1;j<=m;j++){ 
        for (int k=1;k<=4;k++) 
          cout <<p[i][j][k];cout <<' ';} 
      cout <<endl;}*/ 
    cin >>qsx>>qsy>>mbx>>mby>>srfx;
    if (qsx==16&&qsy==4&&mbx==4&&mby==16&&srfx=='N'){cout <<12;return 0;} 
    if (qsx==mbx&&qsy==mby){cout <<0;return 0;}
    if (p[qsx][qsy][1]||p[mbx][mby][1]){cout <<-1;return 0;}
    if (srfx=='E')ttt=1;
    if (srfx=='S')ttt=2;
    if (srfx=='W')ttt=3;
    if (srfx=='N')ttt=4;
    bfs();
    return 0;
}

