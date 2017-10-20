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
    int n,a[51],l,r,s=0,s1=0,s2=0;
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        cin >>a[i];
        s+=a[i];
    }
    cin >>l>>r;
    if (s<l*n||s>r*n){cout <<-1;return 0;}
    {
        for (int i=1;i<=n;i++)
          if (a[i]>r)s1+=a[i]-r;
          else if (a[i]<l)s2+=l-a[i];
    }
    if (s1>s2)cout <<s1;
    else cout <<s2;
    return 0;
}

