#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a = n/m, b = n%m;
    for (int i = 0; i < m-b; i++)
        cout << a << ' ';
    for (int i = 0; i < b; i++)
        cout << a+1 << ' ';
    cout << endl;
    return 0;
}

