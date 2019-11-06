#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, cnt;
int fu[1007];

int head[1007];
struct node {
	int v, next, val;
}e[5007];

void add(int u, int v, int val) {
	e[++cnt].v = v;
	e[cnt].val = val;
	e[cnt].next = head[u];
	head[u] = cnt;
}

int vis[1007], t;
double sum;

void dfs(int s, int um, int tme) {
	
	if(s == t && vis[s] == -1) {
		sum = max(sum, (double)um / tme);
		return ;
	}
	else if(vis[s] == -1) return ;
	vis[s] = 1;
	for(int i = head[s]; i; i = e[i].next) {
		int v = e[i].v, val = e[i].val;
		if(vis[v] == 0) {
			vis[v] = 1;
			dfs(v, um + fu[v], tme + val);
			vis[v] = 0;
		}
		else {
			vis[v] = -1;
			dfs(v, um, tme + val);
		}
	}
}

double ans;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d%d", &n, &m);
	if(n > 20 && m >= 100) return 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &fu[i]);
	}
	for(int i = 1; i <= m; i++) {
		int u, v, val;
		scanf("%d%d%d", &u, &v, &val);
		add(u, v, val);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) vis[j] = 0;
		sum = 0;
		t = i;
		dfs(i, fu[i], 0);
		ans = max(ans, sum);
	}
	printf("%.2lf", ans);
	return 0;
} 
