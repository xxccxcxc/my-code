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
    int s[3],p[10],k,p2=1;
    double a,b,c;
    cin >>a>>b>>c;
    for (int i=1;i<=999;i++)
    {
        if (i*c>=1000||i*a<100)
          continue;
        memset(p,0,sizeof(p));
        s[0]=a*i;
        s[1]=b*i;
        s[2]=c*i;
        for (int j=0;j<3;j++)
        {
            ++p[s[j]%10];
            ++p[s[j]/10%10];
            ++p[s[j]/100];
        }
        for (k=1;k<10;k++)
          if (!p[k])
            break;
        if (k==10)
        {
            cout <<s[0]<<' '<<s[1]<<' '<<s[2]<<endl;
            p2=0;
        }
    }
    if (p2)
      cout <<"No!!!";
    return 0;
}
