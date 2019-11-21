#include <cstdio>
#include <cctype>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
const int MAXN = 2050;
using namespace std;
struct node {
	int u, v;
}edge[MAXN];
int x, u, v, t, n, tonum[MAXN], numto[MAXN], now[MAXN], ans[MAXN];
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
namespace p1 {
	void dfs(int step) {
		if(step == n - 1) {
			for(int i = 1; i <= n; i++)
				now[i] = numto[i];
			for(int i = 1; i <= n; i++) {
				if(ans[i] < now[i])
					return ;
				else if(now[i] < ans[i]) {
					for(int j = 1; j <= n; j++)
						ans[j] = now[j];
					return ;
				}
			}
		}
		for(int i = 1; i <= n - 1; i++) {
			if(vis[i])
				continue;
			vis[i] = true;
			int u = edge[i].u, v = edge[i].v;
			//swap(edge[i].u, edge[i].v);
			//swap(tonum[u], tonum[v]);
			//swap(numto[u], numto[v]);
			for(int j = 1; j <= n - 1; j++) {
				if(edge[j].u == u) {
					edge[j].u = v;
				}
				if(edge[j].v == u) {
					edge[j].v = v;
				}
			}
			for(int j = 1; j <= n - 1; j++) {
				if(edge[j].u == v) {
					edge[j].u = u;
				}
				if(edge[j].v == v) {
					edge[j].v = u;
				}
			}
			dfs(step + 1);
			vis[i] = false;
			//swap(edge[i].u, edge[i].v);
			//swap(tonum[u], tonum[v]);
			//swap(numto[u], numto[v]);
			for(int j = 1; j <= n - 1; j++) {
				if(edge[j].u == v) {
					edge[j].u = u;
				}
				if(edge[j].v == v) {
					edge[j].v = u;
				}
			}
			for(int j = 1; j <= n - 1; j++) {
				if(edge[j].u == u) {
					edge[j].u = v;
				}
				if(edge[j].v == u) {
					edge[j].v = v;
				}
			}
		}
	}
	void solve() {
		for(int i = 1; i <= n; i++) {
			x = read();
			tonum[x] = i;
			numto[i] = x;
		}
		for(int i = 1; i <= n - 1; i++) {
			u = read();
			v = read();
			edge[i].u = u;
			edge[i].v = v;
		}
		for(int i = 1; i <= n - 1; i++) {
			vis[i] = true;
			int u = edge[i].u, v = edge[i].v;
			for(int j = 1; j <= n - 1; j++) {
				if(edge[j].u == u) {
					edge[j].u = v;
				}
				if(edge[j].v == u) {
					edge[j].v = v;
				}
			}
			for(int j = 1; j <= n - 1; j++) {
				if(edge[j].u == v) {
					edge[j].u = u;
				}
				if(edge[j].v == v) {
					edge[j].v = u;
				}
			}
			//swap(tonum[u], tonum[v]);
			//swap(numto[u], numto[v]);
			dfs(1);
			//swap(tonum[u], tonum[v]);
			//swap(numto[u], numto[v]);
			for(int j = 1; j <= n - 1; j++) {
				if(edge[j].u == v) {
					edge[j].u = u;
				}
				if(edge[j].v == v) {
					edge[j].v = u;
				}
			}
			for(int j = 1; j <= n - 1; j++) {
				if(edge[j].u == u) {
					edge[j].u = v;
				}
				if(edge[j].v == u) {
					edge[j].v = v;
				}
			}
			vis[i] = false;
		}
	}
}
void init() {
	memset(tonum, 0, sizeof(tonum));
	memset(numto, 0, sizeof(numto));
	memset(vis, false, sizeof(vis));
	memset(ans, 127 / 3, sizeof(ans));
}

int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	t = read();
	while(t--) {
		init();
		n = read();
		//p1::solve();
		for(int i = 1; i <= n; i++)
			printf("%d ", i);
		cout << endl;
	}
	return 0;
}
