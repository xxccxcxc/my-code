#include <cstdio>
bool a[502][502];
int x,y,fx[5]={0,-1,0,1,0},fy[5]={0,0,1,0,-1},xxx[251002],yyy[251002],h=0,t=1,xx,yy,ans;
void bfs()
{
    a[1][1]=xxx[1]=yyy[1]=1;
    do
    {
        ++h;
        for (int i=1;i<=4;i++)
        {
            xx=xxx[h]+fx[i];
            yy=yyy[h]+fy[i];
            if (xx>0&&xx<=x+2&&yy>0&&yy<=y+2&&a[xx][yy]==0)
            {
                a[xx][yy]=1;
                ++t;
                xxx[t]=xx;
                yyy[t]=yy;
            }
        }
    }while (h<t);
}
int main()
{
    char s[500];
    scanf ("%d%d",&x,&y);
    for (int i=2;i<=x+1;i++)
    {
        scanf ("%s",s);
        for (int j=2;j<=y+1;j++)
          if (s[j-2]=='*')a[i][j]=1;
    }
    bfs ();
    for (int i=1;i<=x+2;i++)
      for (int j=1;j<=y+2;j++)
        if (!a[i][j])
          ++ans;
    printf ("%d",ans);
    return 0;
}
