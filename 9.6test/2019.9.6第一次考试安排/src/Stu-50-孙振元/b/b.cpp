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
template<typename T>inline void chk_max(T &_, T __) { _ = _ < __ ? _ : __; }

const int N = 5e4 + 5, mod = 1e9 + 7;

int n, f[2][N], res;

int main() {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	n = in();
	f[0][0] = 1;
	for (int i = 1, cur = 1; i * (i + 1) / 2 <= n; ++i, cur ^= 1) {
		memset(f[cur], 0, sizeof(f[cur]));
		for (int j = i * (i + 1) / 2; j <= n; ++j) {
			f[cur][j] = f[cur][j - i] + f[cur ^ 1][j - i];
			if (f[cur][j] >= mod)
				f[cur][j] -= mod;
		}
		res += f[cur][n];
		if (res >= mod)
			res -= mod;
	}
	printf("%d\n", res);
	return 0;
}
