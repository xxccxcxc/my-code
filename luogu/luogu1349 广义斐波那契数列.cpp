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
#define ll long long
using namespace std;
ll p,q,a1,a2,t,mo;
class Matrix{
    private:
        ll data[3][3];
    public:
        Matrix()
        {
            for (int i=1;i<=2;i++)
              for (int j=1;j<=2;j++)
                data[i][j]=0;
        }
        void print(ll x,ll y){cout <<data[x][y]%mo;} 
        ll shuchu(){return (a1*data[1][2]+a2*data[2][2])%mo;}
        void init(){for (int i=1;i<=2;i++)data[i][i]=1;}
        void fz1(){data[1][1]=a1;data[1][2]=a2;}
        void fz2(){data[1][1]=0;data[1][2]=q;data[2][1]=1;data[2][2]=p;}
        friend ostream& operator<<(ostream& cout,const Matrix &a);
        friend istream& operator>>(istream& cin,Matrix &a);
        friend Matrix operator*(const Matrix &a,const Matrix &b);
};
Matrix operator*(const Matrix &a,const Matrix &b)
{
        Matrix c;
        for (int i=1;i<=2;i++)
          for (int j=1;j<=2;j++)
            for (int k=1;k<=2;k++)
            {
                c.data[i][j]+=(a.data[i][k]*b.data[k][j])%mo;
                c.data[i][j]%=mo;
            }
        return c;
}
void ksm(Matrix &a,ll x)
{
    Matrix b=a;
    --x;
    while (x)
    {
        if (x&1)a=a*b;
        b=b*b;
        x>>=1;
    }
}
ostream& operator<<(ostream& cout,const Matrix &a)
{
    for (int i=1;i<=2;i++)
    {
        for (int j=1;j<=2;j++)
          cout <<a.data[i][j]<<' ';
        cout <<endl;
    }
    return cout;
}
int main()
{
    cin >>p>>q>>a1>>a2>>t>>mo;
    if (t==1){cout <<a1%mo;return 0;}
    if (t==2){cout <<a2%mo;return 0;}
    Matrix b;b.fz2();
    ksm(b,t-2);
    cout <<b.shuchu()<<endl;
    return 0;
}
/*
3 3
9 8 7
6 5 4
3 2 1
3 3
1 2 3
4 5 6
7 8 9
*/
