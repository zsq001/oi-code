#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

const double INF = 1000000009.0;
const double eps = 1e-6;

using namespace std;

int n, m;

int head[207], cnt;
struct node {
	int v, next;
	double val;
}e[2007];

void add(int u, int v, double val) {
	e[++cnt].v = v;
	e[cnt].val = val;
	e[cnt].next = head[u];
	head[u] = cnt;
}

double dis[207];
int vis[207];

bool check(double mid) {
	queue<int> q;
	for(register int i = 1; i <= n; i++) dis[i] = INF,vis[i] = 0;
	dis[1] = 0;
	q.push(1);
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		vis[x] = 0;
		for(register int i = head[x]; i; i = e[i].next) {
			int v = e[i].v;
			double val = e[i].val - mid;
			if(dis[v] >= dis[x] + val) {
				dis[v] = dis[x] + val;
				if(!vis[v]) {
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
	return dis[n] >= mid;
}

int main() {
	freopen("calabash.in", "r", stdin);
	freopen("calabash.out", "w", stdout);
	double nval = 0.0;
	scanf("%d%d", &n, &m);
	for(register int i = 1; i <= m; i++) {
		int u, v;
		double val;
		scanf("%d%d%lf", &u, &v, &val);
		add(u, v, val);
		nval += val;
	}
	double l = 1, r = nval, mid;
	while(r - l >= eps) {
		mid = (l + r) / 2;
		if(check(mid) == false) {
			r = mid;
		}
		else l = mid;
	}
	printf("%.3lf", l);
	return 0;
}
