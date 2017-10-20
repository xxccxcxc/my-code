#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
int main()
{ 
    int a[10001],m,n,p,t1,t2,s=0,s1=0;
    memset(a,1,sizeof(a));
    cin >>m>>n;
    for (int i=1;i<=n;i++)
    {
        cin >>p>>t1>>t2;
        if (p){for (int j=t1;j<=t2;j++)if (!a[j])a[j]=2;}
        else
          for (int j=t1;j<=t2;j++)
          {
              if (a[j]==2)++s;
              a[j]=0;
          }
    }
    for (int i=0;i<=m;i++)if (a[i]==2)++s1;
    cout <<s1<<endl<<s;
    return 0;
}
