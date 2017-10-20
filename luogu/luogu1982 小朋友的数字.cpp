#include <cstdio>    
#include <iostream>    
#include <algorithm>    
using namespace std;    
long long s,n,mo,t,a[1000001],ans,tt,p=0,ttt=0;    
int main()    
{    
    cin >>n>>mo>>a[1];    
    tt=s=a[1];if (s<0)s=0;    
    for (int i=2;i<=n;i++)    
    {    
        scanf ("%lld",&t);  
        s+=t;    
        if (s>tt)tt=s;    
        if (s<0)s=0;     
        a[i]=tt;    
    }    
    ans=2*a[1];    
    if (a[1]>=0)p=1;  
    for (int i=2;i<n;i++)    
      if (a[i]>0)    
      {  
          ans=(ans+a[i])%mo;  
          if (p==0)  
          {  
              ttt+=a[i];  
              if (ttt>=-a[1])  
                p=1;  
          }  
      }  
    if (p==0)ans=a[1]%mo;  
    cout <<ans;    
    return 0;    
}   
