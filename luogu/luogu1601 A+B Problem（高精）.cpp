#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
#include <ctime>
using namespace std; 
int main() 
{
    string s1,s2; 
    int a[505],b[505],he,i; 
    memset(a,0,sizeof(a)); 
    memset(b,0,sizeof(b)); 
    cin>>s1>>s2; 
    a[0]=s1.length(); 
    for(i=1;i<=a[0];i++) 
      a[i]=s1[a[0]-i]-'0';
    b[0]=s2.length(); 
    for(i=1;i<=b[0];i++) 
      b[i]=s2[b[0]-i]-'0';
    he=(a[0]>b[0]?a[0]:b[0]);  
    for(i=1;i<=he;i++) 
    { 
        a[i]+=b[i]; 
        a[i+1]+=a[i]/10;
        a[i]%=10; 
    } 
    ++he; 
    while((a[he]==0)&&(he>1)) --he; 
    for(i=he;i>=1;i--) 
      cout<<a[i];
    return 0;
}
