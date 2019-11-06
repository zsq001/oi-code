#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
const int INF = 1 << 30;
const int MAXN = 1050;
const int MAXM = 100050;
using namespace std;
int n, m, u, v, w, num, head[MAXN], o[MAXN], val[MAXN];
double ans = -INF;
bool s[MAXN], vis[MAXN];
struct node {
	int to, val, nextt;
}edge[MAXM];
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
void dfs(int goal, int x, int step, int cost) {
	if(x == goal && cost) {
		if(step <= 2)
			return ;
		int res1 = 0;
		memset(s, false, sizeof(s));
		for(int i = 1; i < step; i++)
			s[o[i]] = true;
		for(int i = 1; i <= n; i++) {
			if(s[i])
				res1 += val[i];
		}
		ans = max(ans, 1.0 * res1 / cost);
		return ;
	}
	for(int i = head[x]; i; i = edge[i].nextt) {
		int to = edge[i].to, val = edge[i].val;
		if(vis[to])
			continue;
		vis[to] = true;
		o[step] = to;
		dfs(goal, to, step + 1, cost + val);
		o[step] = 0;
		vis[to] = false;
	}
}
void init() {
	memset(o, 0, sizeof(o));
	ans = -1.0 * INF;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	n = read();
	m = read();
	for(int i = 1; i <= n; i++)
		val[i] = read();
	for(int i = 1; i <= m; i++) {
		u = read();
		v = read();
		w = read();
		addedge(u, v, w);
	}
	for(int i = 1; i <= n; i++) {
		init();
		dfs(i, i, 1, 0);
	}
	printf("%.2lf\n", ans);
	return 0;
}
