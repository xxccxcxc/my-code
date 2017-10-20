#include<iostream>    
#include<algorithm>    
using namespace std;    
int a[501], b[501], f1[501][501], sum1[501];   
int main()    
{        
    int n, k;    
    cin >> n >> k;    
    for (int i = 1; i <= n; i++)    
    {    
        cin >> a[i];    
        sum1[i] = sum1[i - 1] + a[i];    
    }    
    for (int i = 1; i <= n; i++)    
    {    
        f1[i][0] = 0;    
        for (int j = 1; j <= k; j++)    
        {    
            f1[i][j] = f1[i - 1][j];    
            for (int l = 0; l < i; l++)    
            {    
                f1[i][j] = max(f1[i][j], f1[l][j - 1] + sum1[i] - sum1[l]);    
            }    
        }    
    }    
    cout << f1[n][k];   
    return 0;    
}

