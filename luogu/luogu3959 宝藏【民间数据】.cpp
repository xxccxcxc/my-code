#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int N = 14,M = 4096+10,inf = 600000;


int mp[N][N],lg2[M];
int cost[N][M],f[N][M];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) 
		for (int j = 1;j <= n;j++) 
			mp[i][j] = inf;
			
	for (int i = 1;i <= m;i++) {
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		mp[x][y] = min(mp[x][y],z);
		mp[y][x] = mp[x][y];
	}
	m = 1<<n;
	lg2[0] = -1;
	for (int i = 1;i <= m;i++) 
		lg2[i] = lg2[i/2]+1;
		
	for (int i = 1;i < m;i++){
		for (int j = 1;j <= n;j++) {
			cost[j][i] = inf;
			if ((1<<j>>1)&i);
			else{	
				for (int k = 1;k <= n;k++) 
					if ((1<<k>>1)&i){
						cost[j][i] = min(cost[j][i],mp[j][k]);
					}
			}
		}
	}
	for (int i = 0;i < m;i++) 
		for (int j = 1;j <= n;j++) 
			f[j][i] = inf*n*n;
	for (int i = 1;i <= n;i++) 
		f[1][1<<i>>1] = 0;
	for (int i = 2;i <= n;i++){
		for (int j = 3;j < m;j++){
			for (int k = j&(j-1);k;k = j&(k-1)){
				int delta = 0;
				int u = j-k;
				while (u){
					delta += (i-1)*cost[lg2[u&(-u)]+1][k];
					u -= u&(-u);
				}
				f[i][j] = min(f[i][j],f[i-1][k]+delta);
			}
		}
	}
	int ans = inf*n*n;
	for (int i = 2;i <= n;i++) 
		ans = min(ans,f[i][m-1]);
	printf("%d\n",ans);
	return 0;
}


