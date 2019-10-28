#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
typedef long double db;
int in() {
	int x = 0; char c = getchar(); bool f = 0;
	while (c < '0' || c > '9')
		f |= c == '-', c = getchar();
	while (c >= '0' && c <= '9')
		x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return f ? -x : x;
}
template<typename T>inline void chk_min(T &_, T __) { _ = _ < __ ? _ : __; }
template<typename T>inline void chk_max(T &_, T __) { _ = _ > __ ? _ : __; }

const db eps = 1e-8;

struct circle {
	db x, y, r;
} b[11];
int n, k, a[11];
bool vis[11];
db x[11], y[11];
db res, tmp;

int main() {
	freopen("protect.in", "r", stdin);
	freopen("protect.out", "w", stdin);
	n = in();
	for (int i = 1; i <= n; ++i)
		x[i] = in(), y[i] = in(), a[i] = i;
	do {
		tmp = 0;
		for (int i = 1; i <= n; ++i) {
			db min = 1e10, dis;
			for (int j = 1; j < i; ++j) {
				dis = (db)sqrt((x[a[i]] - b[j].x) * (x[a[i]] - b[j].x) + (y[a[i]] - b[j].y) * (y[a[i]] - b[j].y)) - b[j].r;
				if (dis - min < eps)
					min = dis;
			}
			for (int j = i + 1; j <= n; ++j) {
				dis = (db)sqrt((x[a[i]] - x[a[j]]) * (x[a[i]] - x[a[j]]) + (y[a[i]] - y[a[j]]) * (y[a[i]] - y[a[j]]));
				if (dis - min < eps)
					min = dis;
			}
			b[i] = (circle){x[a[i]], y[a[i]], min};
			tmp += min * min;
		}
		if (tmp - res > eps)
			res = tmp;
	} while (std::next_permutation(a + 1, a + 1 + n));
	printf("%.2Lf\n", res);
	return 0;
}	
