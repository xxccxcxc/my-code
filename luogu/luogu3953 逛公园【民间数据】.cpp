#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>

using namespace std;

const int N = 201000;
int read(){
	int x = 0;char ch = getchar();
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0',ch = getchar();
	return x;
}
struct Node{
	int x,y;
	Node(){}
	Node(int x,int y):x(x),y(y){}
}nod[N];
int num[N];
bool operator < (const Node &a,const Node &b){
	return a.y < b.y || (a.y == b.y && num[a.x] > num[b.x]);
}
struct Heap{
	int x,y;
	Heap(){}
	Heap(int x,int y):x(x),y(y){}
};
bool operator < (const Heap &a,const Heap &b){
	return a.y > b.y;
}
priority_queue <Heap> q;

int rfirst[N],rnex[N],rend[N],refn;
int degree[N],sta[N];
bool vist[101000][52],used[N];
int cnt[101000][52];
int now[N],d[N];
int first[N],nex[N],end[N],dis[N],efn;
int T,n,m,k,p,er;
void addedge(int,int,int);
void dij();
void check();
void dfs(int p){
	static int sta[N];int len = 1;
	sta[1] = p;
	used[p] = 1;
	for (int i = 1;i <= len;i++){
		int u = sta[i];
		for (int h = rfirst[u];h;h = rnex[h])
			if (used[rend[h]] == 0){
				used[rend[h]] = 1;
				sta[++len] = rend[h];
			}
	}
}
int add(int x,int y){
	x += y;while (x >= p) x -= p;return x;
}
int main(){
	T = read();
	while (T--){
		n = read();m = read();k = read();p = read();er = 0;
		for (int i = 1;i <= n;i++) first[i] = 0,rfirst[i] = 0;
		for (int i = 1;i <= n;i++) degree[i] = 0;
		for (int i = 1;i <= n;i++) for (int j = 0;j <= k;j++) {vist[i][j] = 0;cnt[i][j] = 0;}
		for (int i = 1;i <= n;i++) used[i] = 0,now[i] = 0;
		efn = 0;refn = 0;
		for (int i = 1;i <= m;i++) {
			int a = read();int b = read();int c = read();
			addedge(a,b,c);
		}
		dfs(n);
		dij();
		for (int i = 1;i <= n;i++) nod[i] = Node(i,d[i]);
		sort(nod+1,nod+1+n);
		check();
		if (er == 1) {printf("-1\n");continue;}
		sort(nod+1,nod+1+n);
		cnt[1][0] = 1;
		vist[1][0] = 1;
		for (int i = 1;i <= n;i++){
			int u = nod[i].x;
			if (!used[u]) break;
			for (int j = now[i];j <= k;j++){
				int last = i;
				for (int l = i;l <= n && d[u]+j >= d[nod[l].x];l++) last = l;
				for (int l = last;l >= i;l--){
					if (vist[nod[l].x][now[l]])
					{
						int tt = nod[l].x;
						if (!used[tt]) break;
						for (int h = first[tt];h;h = nex[h]){
							int v = end[h],w = d[u]+j+dis[h]-d[v];
							if (!used[tt]) continue;
								if (w >= 0 && w <= k){
									vist[v][w] = 1;
									cnt[v][w] = add(cnt[v][w],cnt[tt][now[l]]);
								}
						}
					}
					now[l]++;
				}
			}
		}
//		cout<<cntt<<endl;
		int ans = 0;
		for (int i = 0;i <= k;i++) ans = add(ans,cnt[n][i]);
		printf("%d\n",ans);
	}
	return 0;
}
void addedge(int x,int y,int z){
	end[++efn] = y;
	dis[  efn] = z;
	nex[  efn] = first[x];
	first[x] = efn;
	
	rend[++refn] = x;
	rnex[  refn] = rfirst[y];
	rfirst[y] = refn;
}
void dij(){
	memset(d,0x3f,sizeof(d));
	d[1] = 0;
	q.push(Heap(1,0));
	while (!q.empty()){	
		Heap x = q.top();q.pop();
		while (d[x.x] != x.y){
			if (q.empty()) break;
			x = q.top();q.pop();
		}
		if (d[x.x] != x.y) break;
		for (int h = first[x.x];h;h = nex[h]){
			int v = end[h];
			if (!used[v]) continue;
			if (d[v] > d[x.x] + dis[h]) {
				d[v] = d[x.x] + dis[h];
				q.push(Heap(v,d[v]));
			}
		}
	}
}
void check(){
	int len = 0,cntt;
	int t = 1,w = 2;
	while (t <= n){
		w = t+1;cntt = 0;
		while (w <= n && nod[t].y == nod[w].y)
			w++;
		for (int i = t;i < w;i++){
			int u = nod[i].x;
			if (used[u]) cntt++; 
			for (int h = first[u];h;h = nex[h]){
				int v = end[h];
				if (d[v] == d[u] && dis[h] == 0){
					degree[v]++;
				}
			}
		}
		len = 0;
		for (int i = t;i < w;i++) 
			if (degree[nod[i].x] == 0 && used[nod[i].x]) sta[++len] = nod[i].x;
		
		for (int i = 1;i <= len;i++){
			int u = sta[i];
			for (int h = first[u];h;h = nex[h]){
				int v = end[h];
				if (d[v] == d[u] && dis[h] == 0 && degree[v] > 0) {
					degree[v]--;
					if (degree[v] == 0 && used[v]) sta[++len] = v;
				}
				
			}
		}
		if (len != cntt) {er = 1;return;}
		else {
			for (int i = 1;i <= len;i++) num[sta[i]] = i;
		}
		t = w;
	}
}

