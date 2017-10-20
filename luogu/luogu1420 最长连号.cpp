#include <iostream>
using namespace std;
int main()
{
    int m=0,a,b,s=1,n;
    cin >>n>>a;
    for (int i=1;i<n;i++)
    {
        cin >>b;
        if (b==a+1)
          ++s;
        else
        {
            if (s>m)
              m=s;
            s=1;
        }
        a=b;
    }
    if (s>m)
      m=s;
    cout <<m;
    return 0;
}
