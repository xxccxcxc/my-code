#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    int a[100],i;
    for (i=0;;i++)
    {
      cin >>a[i];
      if (a[i]==0)
      {
        --i;
        break;
      }
    }
    for (int j=i;j>=0;j--)
      cout <<a[j]<<" ";
    return 0;
}

