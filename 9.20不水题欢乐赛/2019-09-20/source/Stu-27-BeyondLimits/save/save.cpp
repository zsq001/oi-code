#include <cstdio>
#include <cctype>
#include <iostream>
#include <cstring>
#include <algorithm>
const int MAXM = 100050;
const int MAXN = 20;
using namespace std;
struct node {
	int u, v, w;
}edge[MAXM];
int n, p, s, x, num, ans, cnt, res, wyc, a[MAXN][MAXN][MAXN], b[MAXN][MAXN];
bool flag2, vis[MAXN][MAXN];
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
	int a[MAXN][MAXN], ans;
	bool flagg;
	void solve() {
		for(int j = 1; j <= 5; j++) {
			for(int k = 1; k <= 5; k++) {
				a[j][k] = read();
				if(a[j][k] == 1)
					flagg = true;
			}
		}
		if(!flagg)
			cout << edge[1].w + edge[2].w << endl;
		else cout << "NO" << endl;
	}
}
namespace p2 {
	int cnt, cntt, fa[MAXN];
	bool cmp(node a, node b) { return a.w < b.w; }
	int findd(int x) {
		int t = x, pre;
		while(x != fa[x])
			x = fa[x];
		while(t != x) {
			pre = fa[t];
			fa[t] = x;
			t = pre;
		}
		return x;
	}
	void kruscal() {
		for(int i = 0; i <= n + 1; i++)
			fa[i] = i;
		for(int i = 1; i <= num; i++) {
			int fx = findd(edge[i].u), fy = findd(edge[i].v), z = edge[i].w;
			if(fx == fy)
				continue;
			fa[fx] = fy;
			cnt += z;
			cntt ++;
			if(cntt == n + 1)
				break;
		}
	}
	void solve() {
		sort(edge + 1, edge + num + 1, cmp);
		kruscal();
		cout << cnt << endl;
	}
}
void input() {
	n = read();
	p = read();
	for(int i = 1; i <= n; i++) {
		x = read();
		edge[++num] = (node){0, i, x};
	}
	for(int i = 1; i <= n; i++) {
		x = read();
		edge[++num] = (node){i, n + 1, x};
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			x = read();
			if(i >= j)
				continue;
			edge[++num] = (node){i, j, x};
		}
	}
}
int main() {
	freopen("save.in", "r", stdin);
	freopen("save.out", "w", stdout);
	input();
	if(n == 1) {
		p1::solve();
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= 5; j++) {
			for(int k = 1; k <= 5; k++) {
				a[i][j][k] = read();
				wyc += a[i][j][k];
			}
		}
	}
	if(wyc == 0) {
		p2::solve();
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}
/*
2 4
2 3
1 1
0 6
6 0
0 0 0 0 0
1 0 0 0 0
1 1 0 0 0
1 0 0 0 0
0 0 0 0 0
0 0 1 0 0
0 1 1 1 0
1 0 1 0 0
1 1 0 0 0
1 0 0 0 0


3 1
1 2 3
4 1 5
0 1 3
1 0 2
3 2 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
*/
