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
    int n,a[101],s=0,p;
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        cin >>a[i];
        p+=a[i];
    }
    p/=n;
    for (int i=1;i<=n;i++)
      a[i]-=p;
    for (int i=1;i<=n;i++)
    {
        if (a[i])
        {
            a[i+1]+=a[i];
            ++s;
        }
    }
    cout <<s;
    return 0;
}
