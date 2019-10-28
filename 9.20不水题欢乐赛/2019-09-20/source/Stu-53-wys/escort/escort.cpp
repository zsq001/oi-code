#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

const int INF = 1000000009;

using namespace std;

int cnt, head[10010], n, m, s, X, t;
int loc[10010], hom[10010];

struct node {
	int v, next, val;
}e[10010];

void add(int u, int v, int val)
{
	e[++cnt].v = v;
	e[cnt].val = val;
	e[cnt].next = head[u];
	head[u] = cnt;
}

int dis[10010], vis[10010];
void spfa(int s)
{
	queue<int> q;
	for(int i = 1; i <= n; i++) dis[i] = INF;
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

int main() {
	freopen("escort.in", "r", stdin);
	freopen("escort.out", "w", stdout);
	int ans = 0, u, v, k1, k2;
	scanf("%d%d%d%d%d", &n, &m, &t, &s, &X);
	for(int i = 1; i <= t; i++)
		scanf("%d", &loc[i]);
	for(int i = 1; i <= t; i++)
		scanf("%d", &hom[i]);
	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d%d", &u, &v, &k1, &k2);
		add(u, v, k1);
		add(v, u, k2);
	}
	spfa(s);
	ans += dis[loc[1]];
	spfa(hom[1]);
	ans += dis[loc[1]];
	printf("%d", ans);
}
