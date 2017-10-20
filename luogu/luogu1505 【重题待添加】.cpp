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
    int s,p,t,ttt,pg[2001],tt[301]={0};
    cin >>p>>t;
    s=t;
    for (int i=1;i<=p;i++)cin>>pg[i];
    for (int i=1;i<=t;i++){cin>>ttt;++tt[ttt];}
    for (int i=1;i<=p;i++)
      for (int j=pg[i]-1;j>=1;j--)
        if (tt[j]){--s;--tt[j];break;}
    cout <<s;
    return 0;
}  

