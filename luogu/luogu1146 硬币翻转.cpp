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
int main()
{
    int n,a[105]={0};
    cin >>n;
    cout <<n<<endl;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (j!=i)a[j]=!a[j];
            cout <<a[j];
        }
        cout <<endl;
    }
    return 0;
}

