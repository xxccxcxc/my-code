#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
int a[7][4][4];  // 1前2后3左4右5上6下
// 此题上面是由下往上看的，所以旋转方向是反的 

void rotate(int face, bool clock) {  // clock=true顺时针，false逆时针
    int b[4][4];
    for (int j = 1; j <= 3; ++j)
        for (int k = 1; k <= 3; ++k)
            b[j][k] = (clock ? a[face][4-k][j] : a[face][k][4-j]);
    for (int j = 1; j <= 3; ++j)
         for (int k = 1; k <= 3; ++k)
             a[face][j][k] = b[j][k];
    
}

void change(int opt) {
    switch(opt) {
        case 1: {  // R
            for (int j = 1; j <= 3; ++j) {
                int tmp = a[1][j][3];
                a[1][j][3] = a[6][j][3];
                a[6][j][3] = a[2][j][3];
                a[2][j][3] = a[5][j][3];
                a[5][j][3] = tmp;
            }
            rotate(4, true);
            break;
        }
        case 2: {  // R'
            for (int j = 1; j <= 3; ++j) {
                int tmp = a[1][j][3];
                a[1][j][3] = a[5][j][3];
                a[5][j][3] = a[2][j][3];
                a[2][j][3] = a[6][j][3];
                a[6][j][3] = tmp;
            }
            rotate(4, false);
            break;
        }
        case 3: {  // U
            for (int k = 1; k <= 3; ++k) {
                int tmp = a[1][1][k];
                a[1][1][k] = a[3][1][k];
                a[3][1][k] = a[2][1][k];
                a[2][1][k] = a[4][1][k];
                a[4][1][k] = tmp;
            }
            rotate(5, true);
            break;
        }
        case 4: {  // U'
            for (int k = 1; k <= 3; ++k) {
                int tmp = a[1][1][k];
                a[1][1][k] = a[4][1][k];
                a[4][1][k] = a[2][1][k];
                a[2][1][k] = a[3][1][k];
                a[3][1][k] = tmp;
            }
            rotate(5, false);
            break;
        }
    }
}

int main() {
    string opt;
    cin >> opt;
    for (int i = 1; i <= 6; ++i)
        for (int j = 1; j <= 3; ++j)
            for (int k = 1; k <= 3; ++k)
                scanf("%1d", &a[i][j][k]);
    for (int i = 0; i < opt.size(); ++i)
        change(opt[i]-'0');
    for (int i = 1; i <= 6; ++i)
        for (int j = 1; j <= 3; ++j) {
            for (int k = 1; k <= 3; ++k)
                cout << a[i][j][k];
            cout << endl;
        }
    return 0;
}

