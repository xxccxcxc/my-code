#include <iostream>
using namespace std;
int main()
{
    int n,t,s=0,as[101];
    bool a[1001]={0};
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        cin >>t;
        a[t]=true;
    }
    for (int i=0;i<=1000;i++)if (a[i])as[++s]=i;
    cout <<s<<endl;
    for (int i=1;i<=s;i++)cout <<as[i]<<' ';
    return 0;
}
