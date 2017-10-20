#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
#include <ctime>
int a[1000001];
using namespace std;
int main()
{
    int n,s=0,d;
    cin >>n>>d;
    for (int i=1;i<=n;i++)cin >>a[i];
    sort (a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        for (int j=i+1;j<=n;j++)
        {
            if (a[i]+d<a[j])break;
            ++s;
        }
    }
    cout <<s;
    return 0;
}
