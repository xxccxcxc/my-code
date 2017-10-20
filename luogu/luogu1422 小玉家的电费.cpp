#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    double n,s,s1,s2;
    cin >>n;
    s1=150*0.4463;
    s2=250*0.4663;
    if (n<=150)
      s=n*0.4463;
    else if (n<=400)
      s=s1+(n-150)*0.4663;
    else
      s=s1+s2+(n-400)*0.5663;
    printf ("%0.1lf",s);
    return 0;
}
