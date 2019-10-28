#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

//const int INF = 1e9 + 7;

using namespace std;

int n, cnt, bnt, ans[50007], flag;

int head[100007];
struct node {
	int v, next, val;
}e[100007];

void add(int u, int v, int val) {
	e[++cnt].v = v;
	e[cnt].next = head[u];
	e[cnt].val = val;
	head[u] = cnt;
}

int dis[50007], vis[50007], fa[50007];

void spfa(int s) {
	queue<int> q;
	for(int i = 0; i < n; i++) dis[i] = vis[i] = 0, fa[i] = -1;
	dis[s] = 0;
	vis[s] = 1;
	q.push(s);
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		if(!vis[x]) continue;
		vis[x] = 0;
		for(int i = head[x]; i; i = e[i].next) {
			int v = e[i].v, val = e[i].val;
			if(dis[v] <= dis[x] + val && v != fa[x]) {
				dis[v] = dis[x] + val;
				fa[v] = x;
				q.push(v);
				vis[v] = 1;
			}
		}
	}
}

void dfs(int s, int end, int step) {
	if(step == dis[end] && s == end) {
		flag = 1;
		return ;
	}
	for(int i = head[s]; i; i = e[i].next) {
		int v = e[i].v;
		if(fa[s] != v) {
			dfs(v, end, step + e[i].val);
		}
		if(flag == 1) {
			e[i].val = 0;
			if(i % 2 == 1) {
				e[i + 1].val = 0;
			}
			else e[i - 1].val = 0;
			break;
		}
	}
	return ;
}

void dbug() {
	printf("\n");
	for(int i = 1; i <= cnt; i++) {
		printf("%d : %d\n", e[i].v, e[i].val);
	}
}

int main(){
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	int s;
	scanf("%d%d", &n, &s);
	for(int i = 1, v; i < n ; i++) {
		scanf("%d", &v);
		if(v != 2) {
			add(i, v, 1);
			add(v, i, 1);
		}
		else add(i, v, 0), add(v, i, 1);
	}
	ans[++bnt] = s;
	int num = n - 1;
	while(num > 0) {
		spfa(s);
		int end, temp = 0;
		for(int i = 0; i < n; i++) {
			if(temp < dis[i]) {
				end = i;
				temp = dis[i];
			}
		}
		num -= dis[end];
		flag = 0;
		dfs(s, end, 0);
		s = end;
		ans[++bnt] = end;
//		dbug();
	}
	
	for(int i = 1; i <= bnt; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
