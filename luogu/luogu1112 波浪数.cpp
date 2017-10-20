#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <deque>
#include <map>
using namespace std;
int p[10000005];
int main()
{
    int a,b,c,d,e;
    cin >>a>>b>>c>>d>>e;
    for (int i=a;i<=b;i++)
      for (int j=1;j<i;j++)
        for (int k=0;k<i;k++)
        {
            if (k==j)continue; 
            int t=0;
            while (t<=d)
            {
                t=t*i+j;
                if (t>d)break;
                ++p[t];
                t=t*i+k;
                if (t>d)break;
                ++p[t];
            }
        }
    for (int i=c;i<=d;i++)
      if (p[i]==e)cout <<i<<endl;
    return 0;
}

