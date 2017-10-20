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
    string s[21];
    int m=1,n,la,lb;
    cin >>n;
    for (int i=1;i<=n;i++)
    {
        cin >>s[i];
        la=s[i].size();
        lb=s[m].size();
        if (la!=lb)
        {
            if (la>lb)
              m=i;
        }
        else if (s[i]>s[m])
          m=i;
    }
    cout <<m<<endl<<s[m];
    return 0;
}
