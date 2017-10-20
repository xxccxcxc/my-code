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
string a,b;
int k,f[2001][2001]={0},aa,bb;
int c[6][6]=
{{0},
{0,5,-1,-2,-1,3},
{0,-1,5,-3,-2,-4},
{0,-2,-3,5,-2,-2},
{0,-1,-2,-2,5,-1},
{0,-3,-4,-2,-1}};
int main()
{
    cin >>aa>>a>>bb>>b;
    for (int i=0;i<aa;i++)
    {
        if (a[i]=='A')a[i]=1;
        if (a[i]=='C')a[i]=2;
        if (a[i]=='G')a[i]=3;
        if (a[i]=='T')a[i]=4;
    }
    for (int i=0;i<bb;i++)
    {
        if (b[i]=='A')b[i]=1;
        if (b[i]=='C')b[i]=2;
        if (b[i]=='G')b[i]=3;
        if (b[i]=='T')b[i]=4;
    }
    for (int i=1;i<=aa;i++)f[i][0]=f[i-1][0]+c[5][a[i-1]];
    for (int i=1;i<=bb;i++)f[0][i]=f[0][i-1]+c[5][b[i-1]];
    for (int i=1;i<=aa;i++)
      for (int j=1;j<=bb;j++)
        f[i][j]=max(f[i-1][j]+c[5][a[i-1]],max(f[i][j-1]+c[5][b[j-1]],f[i-1][j-1]+c[a[i-1]][b[j-1]]));
    cout <<f[aa][bb];
    return 0;
}

