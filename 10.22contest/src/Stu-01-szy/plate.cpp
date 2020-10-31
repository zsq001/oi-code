#include <cstdio>
#include <cstring>
#include <algorithm>
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

const int N = 505;

int n, m, p;
int a[N][N << 1], pre[N], res;

void get_min(int *s) {
	for (int i = 1; i <= m; ++i)
		s[m + i] = s[i];
	int i = 1, j = 2, k = 0, p = 1;
	for (; i <= m && j <= m && k <= m; ) {
		if (i == j) {
			++j, k = 0;
			continue;
		}
		if (s[i + k] < s[j + k]) {
			p = i, j += k + 1, k = 0;
		} else if (s[i + k] > s[j + k]) {
			p = j, i += k + 1, k = 0;
		} else {
			++k;
		}
	}
	for (int i = 1; i <= m; ++i)
		s[i] = s[p + i - 1];
}
	
int main() {
	freopen("plate.in", "r", stdin);
	freopen("plate.out", "w", stdout);
	n = in(), m = in(), p = in();
	if (p == 1) {
		printf("%d\n", n * (n - 1) / 2);
		return 0;
	}
	for (int i = 1, tmp; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			a[i][j] = in();
		std::sort(a[i] + 1, a[i] + 1 + m);
		tmp = p - a[i][m] + a[i][1];
		for (int j = 2; j <= n; ++j)
			a[i][j] = a[i][j] - a[i][j - 1];
		a[i][1] = tmp;
	}
	for (int i = 1, j, k; i <= n; ++i) {
		get_min(a[i]);
		for (j = i - 1; j; --j) {
			for (k = 1; k <= m; ++k)
				if (a[i][k] != a[j][k])
					break;
			if (k > m)
				break;
		}
		pre[i] = pre[j] + 1;
		res += pre[j];
	}
	printf("%d\n", res);
	return 0;
}
