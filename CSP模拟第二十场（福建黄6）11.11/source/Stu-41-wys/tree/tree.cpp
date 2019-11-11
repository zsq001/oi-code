#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int T, n, k, anss[100007], last, tcnt = 1, ans, tans, cnt;

int head[100007];
struct node {
	int v, next;
}e[100007 << 1];

inline void add(int u, int v) {
	e[++cnt].v = v;
	e[cnt].next = head[u];
	head[u] = cnt;
}

int siz[100007], son[100007], top[100007], fa[100007];

inline void init() {
	cnt = 0, tcnt = 1, ans = tans = 0;
	for(register int i = 1; i <= n; i++) {
		siz[i] = 0; head[i] = 0; son[i] = 0;
		top[i] = 0; fa[i] = 0; anss[i] = 0;
	}
}

inline void dfs1(int x) {
	siz[x]++;
	int maxx = -1;
	for(register int i = head[x]; i; i = e[i].next) {
		int v = e[i].v;
		if(v == fa[x]) continue;
		fa[v] = x;
		dfs1(v);
		siz[x] += siz[v];
		if(siz[v] > maxx) {
			son[x] = v;
			maxx = siz[v];
		}
	}
}

inline void dfs2(int x, int tp, int len) {
	top[x] = tp;
	if(son[x]) {
		dfs2(son[x], tp, len + 1);
	}
	anss[tp] = max(anss[tp], len);
	for(register int i = head[x]; i; i = e[i].next) {
		int v = e[i].v;
		if(v == fa[x] || v == son[x]) continue;
		dfs2(v, v, 1);
	}
}

int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d%d", &n, &k);
		for(register int i = 1; i < n; i++) {
			int v;
			scanf("%d", &v);
			add(i + 1, v);
			add(v, i + 1);
		}
		fa[1] = 0;
		dfs1(1);
		last = 1;
		dfs2(1, 1, 1);
		int maxxn = 1e9 + 7, maxxnum;
		for(register int i = 2; i <= n; i++) {
			if(fa[i] == 1) {
				maxxn = anss[i];
				maxxnum = i;
			}
		}
		anss[1] += maxxn; anss[maxxnum] = 0;
		for(register int i = 1; i <= n; i++) {
			if(anss[i] % 2 != 0) {
				anss[i]--;
//				tans--;
			}
			ans += anss[i] / 2;
			tans += anss[i];
		}
		if(k > tans) {
			k -= tans;
			ans += k;
		}
		printf("%d\n", ans);
	}
	return 0;
}
