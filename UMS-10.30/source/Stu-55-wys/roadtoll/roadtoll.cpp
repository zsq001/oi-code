#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int n, m, k, cnt;

int poi[100], head[107];
struct node {
	int v, next, val;
}e[10007];

void add(int u, int v, int val) {
	e[++cnt].v = v;
	e[cnt].val = val;
	e[cnt].next = head[u];
	head[u] = cnt;
}

int ans = 1e9 + 7, vis[107], sum;

void dfs(int s, int maxx, int t, int fa) {
	if(sum > ans) return ;
	if(s == t)
	{
		ans = min(ans, sum + maxx);
		return ;
	}
	for(int i = head[s]; i; i = e[i].next) {
		int v = e[i].v, val = e[i].val;
		if(v != fa) {
			int nmax = max(maxx, poi[v]);
			sum = sum + val;
			dfs(v, nmax, t, s);
			sum = sum - val;
		}
	}
	return ;
}

int query(int s, int t) {
	sum = 0;
	ans = 1e9 + 7;
	dfs(s, poi[s], t, 0);
	return ans;
}

int main() {
	freopen("roadtoll.in", "r", stdin);
	freopen("roadtoll.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &poi[i]);
	}
	for(int i = 1; i <= m; i++) {
		int u, v, val;
		scanf("%d%d%d", &u, &v, &val);
		add(u, v, val);
		add(v, u, val);
	}
	for(int i = 1; i <= k; i++) {
		int s, t;
		scanf("%d%d", &s, &t);
		printf("%d\n", query(s, t));
	}
	return 0;
}
