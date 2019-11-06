#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long

using namespace std;

int n, m;
ll sum[100007];
struct node {
	ll num, val;
	int tagg, fa;
}tr[100007];

struct edge {
	int v, next;
}e[100007];

int head[100007], cnt;

void add(int u, int v) {
	e[++cnt].v = v;
	e[cnt].next = head[u];
	head[u] = cnt;
}

void update1(int x, ll y) {
	sum[x] += y;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].v;
		update1(v, y);
	}
	return ;
}

void update2(int x, ll y, int step) {
	sum[x] += step * y;
	tr[x].val += y;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].v;
		update2(v, y, step + 1);
	}
	return ;
}

ll query(int x) {
	return sum[x] - sum[0];
}

int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	scanf("%d%d", &n, &m);
//	if(m * n > 100000000) return 0;
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &tr[i].val);
	}
	sum[1] = tr[1].val;
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
		sum[v] = sum[u] + tr[v].val;
		tr[v].fa = u;
	}
	for(int i = 1; i <= m; i++) {
		int op, x;
		ll y;
		scanf("%d", &op);
		if(op == 1) {
			scanf("%d%lld", &x, &y);
			tr[x].val += y;
			update1(x, y);
		}
		else if(op == 2) {
			scanf("%d%lld", &x, &y);
			update2(x, y, 1);
		}
		else if(op == 3) {
			scanf("%d", &x);
			printf("%lld\n", query(x));
		}
	}
	return 0;
}
