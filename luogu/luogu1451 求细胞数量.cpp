#include <cstdio>
bool a[101][101];
int xx[6]={0,-1,0,1,0},yy[6]={0,0,1,0,-1},ans,n,m;
void bfs(int p,int q)
{
    int h[1000][3],t=0,w=1,x=0,y=0;
    ++ans;
    a[p][q]=0;h[1][1]=p;h[1][2]=q;
    do
    {
        ++t;
        for (int i=1;i<=4;i++)
        {
            x=h[t][1]+xx[i];y=h[t][2]+yy[i];
            if (x>0&&x<=n&&y>0&&y<=m&&a[x][y])
            {
                ++w;
                h[w][1]=x;h[w][2]=y;
                a[x][y]=0;
            }
        }
    }while (t<w);
}
int main()
{
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
      {
          scanf ("%1d",&a[i][j]);
          if (a[i][j])a[i][j]=1;
      }
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
        if (a[i][j])bfs (i,j);
    printf ("%d",ans);
    return 0;
}
