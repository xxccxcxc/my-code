#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    char a[100001];
    int w=0,l=0,i=1;
    while (cin >>a[i]&&a[i]!='E')
    {
        if (a[i]=='W')
          ++w;
        if (a[i]=='L')
          ++l;
        if ((w>=11||l>=11)&&abs(w-l)>=2)
        {
            cout <<w<<':'<<l<<endl;
            w=l=0;
        }
        i++;
    }
    cout <<w<<':'<<l<<endl<<endl;
    w=l=0;
    for (int j=1;j<i;j++)
    {
        if (a[j]=='W')
          ++w;
        if (a[j]=='L')
          ++l;
        if ((w>=21||l>=21)&&abs(w-l)>=2)
        {
            cout <<w<<':'<<l<<endl;
            w=l=0;
        }
    }
    cout <<w<<':'<<l<<endl;
    return 0;
}
