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
#include <map>
using namespace std;
struct jx{
    int x1,x2,y1,y2;
}a[1005];
int n;
long long xx[1005],yy[1005],x[1005],y[1005],nn=1,mm=1,ans;
bool b[1005][1005];
map<long long,long long> cx,cy;
int main()
{
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        cin >>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2;
        swap(a[i].y1,a[i].y2);
        xx[i*2-1]=a[i].x1;yy[i*2-1]=a[i].y1;
        xx[i*2]=a[i].x2;yy[i*2]=a[i].y2;
    }
    sort (xx+1,xx+2*n+1);
    sort (yy+1,yy+2*n+1);
    
    //cout <<2*n<<' ';for (int i=1;i<=2*n;i++)cout <<xx[i]<<' ';cout <<endl;
    //cout <<2*n<<' ';for (int i=1;i<=2*n;i++)cout <<yy[i]<<' ';cout <<endl;
    
    x[1]=xx[1];y[1]=yy[1];
    for (int i=2;i<=n*2;i++)
    {
        if (xx[i]!=xx[i-1])x[++nn]=xx[i];
        if (yy[i]!=yy[i-1])y[++mm]=yy[i];
    }
    
    //cout <<nn<<' ';for (int i=1;i<=nn;i++)cout <<x[i]<<' ';cout <<endl;
    //cout <<mm<<' ';for (int i=1;i<=mm;i++)cout <<y[i]<<' ';cout <<endl;
    
    for (int i=1;i<=nn;i++)cx[x[i]]=i;
    for (int i=1;i<=mm;i++)cy[y[i]]=i;
    for (int i=1;i<=n;i++)
      for (int j=cx[a[i].x1];j<cx[a[i].x2];j++)
        for (int k=cy[a[i].y1];k<cy[a[i].y2];k++)
          b[j][k]=1;
    
    /*for (int i=1;i<=nn;i++)
    {
        for (int j=1;j<=mm;j++)
          cout <<b[i][j]<<' ';
        cout <<endl;
    }*/
    
    for (int i=1;i<nn;i++)
      for (int j=1;j<mm;j++)
        if (b[i][j])
          ans+=(x[i+1]-x[i])*(y[j+1]-y[j]);
    cout <<ans;
    return 0;
}
