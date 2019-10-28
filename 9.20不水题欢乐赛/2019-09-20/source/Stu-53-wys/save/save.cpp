#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

const int INF = 1000000007;

using namespace std;

int n, K, head[1007], cnt, ans[17], anss = 100000007, f[20][20];
int mapp[7][7];

struct node {
	int v, next, val;
}e[1007];

void add(int u, int v, int val)
{
	e[++cnt].v = v;
	e[cnt].next = head[u];
	e[cnt].val = val;
	head[u] = cnt;
}

int dis[21], vis[21];

void spfa(int s)
{
	queue<int> q;
	for(int i = 1; i <= n + 1; i++) dis[i] = INF;
	dis[s] = 0;
	q.push(s);
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		vis[x] = 0;
		for(int i = head[x]; i; i = e[i].next) {
			int v = e[i].v, val = e[i].val;
			if(dis[v] > dis[x] + val) {
				dis[v] = dis[x] + val;
				if(vis[v] == 0) {
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
}

int viss[20], last;

int work(int now)
{
	last = now;
	int sum = 0;
	viss[now] = 1;
	for(int i = 1; i <= n; i++) {
		if(viss[i] == 1) continue;
		sum += f[now][i];
		viss[i] = 1;
		sum += work(i);
	}
	return sum + f[now][n + 1];
}

int main() {
	freopen("save.in", "r", stdin);
	freopen("save.out", "w", stdout);
	int t;
	scanf("%d%d", &n, &K);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &t);
		add(0, i, t);
		ans[i] += t;
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &t);
		add(i, n + 1, t);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			scanf("%d", &t);
			add(i, j, t);
			add(j, i, t);
		}
	}
	for(int l = 1; l <= n; l++) {
		for(int i = 1; i <= 5; i++) {
			for(int j = 1; j <= 5; j++) {
				scanf("%d", &mapp[i][j]);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		spfa(i);
		for(int j = 1; j <= n + 1; j++) {
			f[i][j] = dis[j];
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) viss[j] = 0;
		ans[i] += work(i);
		anss = min(ans[i], anss);
	}
	printf("%d", anss);
	return 0;
}
