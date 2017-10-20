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
    int k,p=0;
    cin >>k;
    for (int i=10000;i<=30000;i++)
      if (!((i%1000)%k)&&!((i/10)%1000%k)&&!((i/100)%k))
      {cout <<i<<endl;p=1;}
    if (!p)
      cout <<"No";
    return 0;
}
