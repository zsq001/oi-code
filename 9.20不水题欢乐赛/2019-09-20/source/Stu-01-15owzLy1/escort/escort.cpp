#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
int in() {
	int x = 0; char c = getchar(); bool f = 0;
	while (c < '0' || c > '9')
		f |= c == '-', c = getchar();
	while (c >= '0' && c <= '9')
		x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return f ? -x : x;
}
template<typename T>inline void chk_min(T &_, T __) { _ = (!~_ || _ > __) ? __ : _; }
template<typename T>inline void chk_max(T &_, T __) { _ = _ > __ ? _ : __; }

const int N = 1e4 + 5;

struct edge {
	int next, to, w;
} e[N << 1];
int ecnt = 1, head[N];
int n, m, t, s, X, x[11], y[11], dis[13][N], f[245][15];
bool vis[N];

inline void add_edge(const int u, const int v, const int w) {
	e[++ecnt] = (edge){head[u], v, w};
	head[u] = ecnt;
}

void dijkstra(int *d, const int S) {
	std::priority_queue<std::pair<int, int> > q;
	std::fill(d + 1, d + 1 + n, -1);
	memset(vis, 0, sizeof(vis));
	d[S] = 0, q.push(std::make_pair(0, S));
	while (!q.empty()) {
		int u = q.top().second; q.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (int i = head[u]; i; i = e[i].next) {
			int v = e[i].to;
			if (!~d[v] || d[u] + e[i].w < d[v]) {
				d[v] = d[u] + e[i].w;
				q.push(std::make_pair(-d[v], v));
			}
		}
	}
}

inline int count_1(int x) {
	int ret = 0;
	while (x)
		ret += (x % 3 == 1), x /= 3;
	return ret;
}

int l[15];
void dp() {
	int res = -1;
	l[0] = 1;
	for (int i = 1; i <= t; ++i)
		l[i] = l[i - 1] * 3;
	memset(f, -1, sizeof(f));
	for (int i = 1; i <= t; ++i) {
		f[l[i - 1]][i] = dis[0][x[i]];
	}
	for (int i = 1; i < l[t] - 1; ++i) {
		for (int j = 1; j <= t + t; ++j) {
			if (!~f[i][j])
				continue;
			if (count_1(i) < X)
				for (int k = 1; k <= t; ++k)
					if (i / l[k - 1] % 3 == 0)
						chk_min(f[i + l[k - 1]][k], f[i][j] + dis[j][x[k]]);
			if (count_1(i) > 0)
				for (int k = 1; k <= t; ++k)
					if (i / l[k - 1] % 3 == 1)
						chk_min(f[i + l[k - 1]][k + t], f[i][j] + dis[j][y[k]]);
		}
	}
	
	for (int i = 1; i <= 2 * t; ++i)
		if (~f[l[t] - 1][i])
			chk_min(res, f[l[t] - 1][i]);
	printf("%d\n", res);
}

int main() {
	freopen("escort.in", "r", stdin);
	freopen("escort.out", "w", stdout);
	n = in(), m = in(), t = in(), s = in(), X = in();
	for (int i = 1; i <= t; ++i)
		x[i] = in(), y[i] = in();
	for (int i = 1; i <= m; ++i) {
		int u = in(), v = in();
		add_edge(u, v, in());
		add_edge(v, u, in());
	}
	
	dijkstra(dis[0], s);
	for (int i = 1; i <= t; ++i)
		dijkstra(dis[i], x[i]), dijkstra(dis[i + t], y[i]);
	dp();
	return 0;
}
