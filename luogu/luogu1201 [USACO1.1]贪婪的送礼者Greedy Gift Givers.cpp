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
    string mz[11];
    int a[11]={0},n,q,r,p;
    cin >>n;
    for (int i=1;i<=n;i++)cin >>mz[i];
    for (int k=1;k<=n;k++)
    {
        cin >>mz[0];
        for (int i=1;i<=n;i++)if (mz[0]==mz[i]){p=i;break;}
        cin >>q>>r;
        if (r)
        {
            a[p]=a[p]-q+q%r;
            q/=r;
            for (int i=1;i<=r;i++)
            {
                cin >>mz[0];
                for (int j=1;j<=n;j++)if (mz[0]==mz[j]){p=j;break;}
                a[p]+=q;
            }
        }
    }
    for (int i=1;i<=n;i++)cout <<mz[i]<<' '<<a[i]<<endl;
    return 0;
}
