#include <iostream>
#include <cstring>
using namespace std;
int x,y;
void pd(char a)
{
    if (a=='E')++x;
    else if (a=='S')--y;
    else if (a=='W')--x;
    else ++y;
}
int main()
{
    string a;
    int t;
    cin >>a>>t;
    int w=a.size();
    for (int i=0;i<w;i++)pd(a[i]);
    x*=t/w;y*=t/w;
    for (int i=0;i<t%w;i++)pd(a[i]);
    cout <<x<<' '<<y;
    return 0;
}
