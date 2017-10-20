#include <iostream>
using namespace std;
int n,a[21],l[21],zy[41],yz[41],s;
void search(int h)
{
    for (int i=1;i<=n;i++)
    {
        if (l[i]==0&&zy[h-i+n]==0&&yz[h+i]==0)
        {
            a[h]=i;
            l[i]=zy[h-i+n]=yz[h+i]=1;
            if (h==n)
            {
                ++s;
                if (s<=3){for (int j=1;j<=n;j++)cout <<a[j]<<' ';cout <<endl;}
            }
            else search (h+1);
            l[i]=zy[h-i+n]=yz[h+i]=0;
        }
    }
}
int main()
{
    cin >>n;
    search (1);
    cout <<s;
    return 0;
}
