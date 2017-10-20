#include <iostream>
using namespace std;
int main()
{
    int n,sjj,jqq,sj[101],jq[101],f[201][201]={0};
    cin >>n>>sjj>>jqq;
    for (int i=1;i<=n;i++)cin >>sj[i]>>jq[i];
    for (int i=1;i<=n;i++)
      for (int j=sjj;j>=sj[i];j--)
        for (int k=jqq;k>=jq[i];k--)
          f[j][k]=max(f[j][k],f[j-sj[i]][k-jq[i]]+1);
    cout <<f[sjj][jqq];
    return 0;
}
