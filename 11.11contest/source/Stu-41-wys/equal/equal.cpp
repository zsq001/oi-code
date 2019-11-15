#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

const int INF = 1e9 + 7;

using namespace std;

int n, m, ans;

int head[100007], cnt;
struct node {
	int v, next;
}e[200007];

void add(int u, int v) {
	e[++cnt].v = v;
	e[cnt].next = head[u];
	head[u] = cnt;
}

int dis1[100007], dis2[100007], vis1[100007], vis2[100007], f1[100007], f2[100007];

void spfa1(int s) {
	queue<int> q;
	for(int i = 1; i <= n; i++) 
		dis1[i] = INF, vis1[i] = 0, f1[i] = 0;
	q.push(s);
	dis1[s] = 0;
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		vis1[x] = 0;
		for(int i = head[x]; i; i = e[i].next) {
			int v = e[i].v;
			if(v == f1[x]) continue;
			f1[v] = x;
			if(dis1[v] > dis1[x] + 1) {
				dis1[v] = dis1[x] + 1;
				if(!vis1[v]) {
					q.push(v);
					vis1[v] = 1;
				}
			}
		}
	}
}

void spfa2(int s) {
	queue<int> q;
	for(int i = 1; i <= n; i++) 
		dis2[i] = INF, vis2[i] = 0, f2[i] = 0;
	q.push(s);
	dis2[s] = 0;
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		vis2[x] = 0;
		for(int i = head[x]; i; i = e[i].next) {
			int v = e[i].v;
			if(v == f2[x]) continue;
			f2[v] = x;
			if(dis2[v] > dis2[x] + 1) {
				dis2[v] = dis2[x] + 1;
				if(!vis2[v]) {
					q.push(v);
					vis2[v] = 1;
				}
			}
		}
	}
}

int main() {
	freopen("equal.in", "r", stdin);
	freopen("equal.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
	}
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) {
		ans = 0;
		int x, y;
		scanf("%d%d", &x, &y);
		if(x == y) {
			printf("%d\n", n - 1);
			continue;
		}
		spfa1(x);
		spfa2(y);
		for(int i = 1; i <= n; i++) {
			if(i == x || i == y) continue;
			if(dis1[i] == dis2[i]) ans++; 
		}
		printf("%d\n", ans);
	}
	return 0;
}
