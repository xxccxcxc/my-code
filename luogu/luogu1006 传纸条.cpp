#include <algorithm>
#include <iostream>
#include <iomanip>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
using namespace std;  
int n,m,a[101][101],f[101][101][101]={0},s,ans=-1,t;  
int main()  
{  
    cin >>n>>m;  
    for (int i=1;i<=n;i++)  
      for (int j=1;j<=m;j++)  
        cin >>a[i][j];  
    for (int i=1;i<=n+m-2;i++)
      for (int j=1;j<=n;j++)
        for (int k=1;k<=n;k++)
        {
            if (j>=i+2||k>=i+2)continue;
            f[i][j][k]=max(f[i-1][j-1][k],max(f[i-1][j][k-1],max(f[i-1][j-1][k-1],f[i-1][j][k])));
            f[i][j][k]+=a[j][i-j+2];
            if (j!=k)f[i][j][k]+=a[k][i-k+2];
        }
    cout <<f[n+m-2][n][n];
    return 0;  
}  

