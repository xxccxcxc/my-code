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
int main()  
{  
    int n,m,f[10002]={0},ks[10001],cx[10001],t;  
    cin >>n>>m;t=m;  
    for (int i=1;i<=m;i++)cin >>ks[i]>>cx[i];  
    for (int i=1;i<=m;i++)
      for (int j=1;j<=m-i;j++)
        if (ks[j]>ks[j+1]||(ks[j]==ks[j+1]&&cx[j]>cx[j+1]))
          {swap(ks[j],ks[j+1]);swap(cx[j],cx[j+1]);}
    for (int i=n;i>=1;i--)  
      if (ks[t]<i)f[i]=f[i+1]+1;  
      else while (ks[t]==i)f[i]=max(f[i],f[ks[t]+cx[t--]]);  
    cout <<f[1];  
    return 0;  
}  

