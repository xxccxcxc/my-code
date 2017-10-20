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
int a[200001];
int main()
{
    int n,p,s=1;
    cin >>n;
    for (int i=1;i<=n;i++)
      cin >>a[i];
    sort (a+1,a+n+1);
    p=a[1];
    for (int i=2;i<=n;i++)
    {
        if (a[i]==p)++s;
        else
        {
            cout <<p<<' '<<s<<endl;
            p=a[i];s=1;
        }
    }
    cout <<p<<' '<<s;
    return 0;
}
