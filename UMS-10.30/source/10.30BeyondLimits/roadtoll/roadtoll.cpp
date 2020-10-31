#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
const int INF = 1 << 30;
const int MAXN = 500;
const int MAXM = 50050;
typedef int intt;
#define int long long
using namespace std;
struct node {
	int to, val, nextt;
}edge[MAXM];
int n, m, k, u, v, w, s, t, num, ans = INF, val[MAXN], head[MAXN]; 
bool vis[MAXN];
int read() {
	int x = 0;
	bool sign = false;
	char alpha = 0;
	while(!isdigit(alpha)) {
		sign |= alpha == '-';
		alpha = getchar();
	}
	while(isdigit(alpha)) {
		x = (x << 1) + (x << 3) + (alpha ^ 48);
		alpha = getchar();
	}
	return sign ? -x : x;
}
void addedge(int u, int v, int w) {
	edge[++num].to = v;
	edge[num].val = w;
	edge[num].nextt = head[u];
	head[u] = num;
}
void dfs(int x, int y, int Max, int res1) {
	if(x == y) {
		ans = min(ans, res1 + Max);
		return ;
	}
	for(int i = head[x]; i; i = edge[i].nextt) {
		int to = edge[i].to, vall = edge[i].val;
		Max = max(Max, val[to]);
		if(vis[to])
			continue;
		vis[to] = true;
		dfs(to, y, Max, res1 + vall);
		vis[to] = false;
	}
}
void init() {
	memset(vis, false, sizeof(vis));
	ans = INF;
}
intt main() {
	freopen("roadtoll.in", "r", stdin);
	freopen("roadtoll.out", "w", stdout);
	n = read();
	m = read();
	k = read();
	for(int i = 1; i <= n; i++)
		val[i] = read();
	for(int i = 1; i <= m; i++) {
		u = read();
		v = read();
		w = read();
		addedge(u, v, w);
		addedge(v, u, w);
	}
	for(int i = 1; i <= k; i++) {
		s = read();
		t = read();
		vis[s] = true;
		dfs(s, t, val[s], 0);
		cout << ans << endl;
		init();
	}
	return 0;
}
