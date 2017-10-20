#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <deque>
#include <map>
using namespace std;
int main()
{
    int n,a[100005]={0};
    scanf ("%d",&n);
    for (int i=1;i<=n;i++)
      scanf ("%d",&a[i]);
    int s=1,p=2;
    for (int i=2;i<=n;i++)
      if (a[i]>a[i-1]&&p!=1)++s,p=1;
      else if (a[i]<a[i-1]&&p!=0)++s,p=0;
    printf ("%d",s);
    return 0;
}
