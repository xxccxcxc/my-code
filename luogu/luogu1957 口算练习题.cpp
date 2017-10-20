#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
using namespace std;
int main()
{
    int n,p=0,a,b,s;
    char c[10],t1[10],t2[10],t3[10];
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        cin >>c;
        if (c[0]=='a'||c[0]=='b'||c[0]=='c')
        {
            p=c[0]-'a'+1;
            cin >>a>>b;
        }
        else
        {
            sscanf (c,"%d",&a);
            cin >>b;
        }
        cout <<a;
        if (p==1)cout <<'+';
        if (p==2)cout <<'-';
        if (p==3)cout <<'*';
        cout <<b<<'=';
        if (p==1)s=a+b;
        if (p==2)s=a-b;
        if (p==3)s=a*b;
        cout <<s<<endl;
        sprintf (t1,"%d",a);
        sprintf (t2,"%d",b);
        sprintf (t3,"%d",s);
        cout <<strlen (t1)+strlen (t2)+strlen (t3)+2<<endl;
    }
    return 0;
}

