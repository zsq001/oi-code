#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int T;
int n, cnt, head[2050], ans, rt;
struct node {
	int u, v, next;
}e[2050];

void add(int u, int v) {
	e[++cnt].v = v;
	e[cnt].u = u;
	e[cnt].next = head[u];
	head[u] = cnt;
}

int siz[2050];

void dfs(int s) {
	siz[s] = 1;
	for(int i = head[s]; i; i = e[i].next) {
		int v = e[i].v;
		dfs(v);
		siz[s] += siz[v];
	}
	return ;
}

int col[2050], siz2[2050];

void dfs2(int s, int su, int sv) {
	col[s] = 1, siz2[s] = 1;
	for(int i = head[s]; i; i = e[i].next) {
		int v = e[i].v;
		if(s == su && v == sv) continue;
		dfs2(v, su, sv);
		siz2[s] += siz2[v]; 
	}
	return ;
}

void work1(int u, int v, int t1, int t2) {
	dfs2(rt, u, v);
	for(int i = 1; i <= n; i++) {
		int flag = 0;
		if(col[i] == 1) {
			int sizz = t1 - siz2[i];
			if(sizz > t1 / 2) flag = 1;
			for(int j = 1; j <= cnt; j++) {
				if(e[j].u == i) {
					if(siz2[e[j].v] > t1 / 2) flag = 1;
				}
			}
			if(flag == 1) continue;
			ans += i;
//			printf("%d ", i);
		}
		if(col[i] == 0) {
			int sizz = t2 - siz[i];
			if(sizz > t2 / 2) flag = 1;
			for(int j = 1; j <= cnt; j++) {
				if(e[j].u == i) {
					if(siz[e[j].v] > t2 / 2) flag = 1;
				}
			}
			if(flag == 1) continue;
			ans += i;
//			printf("%d ", i);
		}
	}
}

int main() {
	freopen("centroid.in", "r", stdin);
	freopen("centroid.out", "w", stdout);
	scanf("%d", &T);
	while(T--) {
		ans = 0, cnt = 0;
		for(int i = 1; i <= n; i++) {
			siz[i] = 0, head[i] = 0;
			if(i > 1) {
				e[i - 1].next = e[i].u = e[i].v = 0;
			}
		}
		scanf("%d", &n);
		for(int i = 1; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			if(i == 1) rt = u;
			add(u, v);
		}
		dfs(rt);
		for(int i = 1; i <= cnt; i++) {
			for(int j = 1; j <= n; j++) {
				siz2[j] = 0;
				col[j] = 0;
			}
			int u = e[i].u, v = e[i].v;
			int t1 = (siz[rt] - siz[v]);
			int t2 = siz[v];
			work1(u, v, t1, t2);
		}
		printf("%d\n", ans);
	}
}
