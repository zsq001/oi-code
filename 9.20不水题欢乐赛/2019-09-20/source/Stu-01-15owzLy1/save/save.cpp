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
template<typename T>inline void chk_min(T &_, T __) { _ = (_ == -1 || _ > __) ? __ : _; }

const int N = 21;

int a[N][N], s[7][7];
int n, k, f[1 << 16 | 1][N];

int main() {
	freopen("save.in", "r", stdin);
	freopen("save.out", "w", stdout);
	n = in(), k = in();
	for (int i = 1; i <= n; ++i)
		a[0][i] = in();
	for (int i = 1; i <= n; ++i)
		a[i][0] = in();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			a[i][j] = in();
	int res = 0, tmp;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 5; ++j)
			for (int k = 1; k <= 5; ++k)
				s[j][k] = in();
		tmp = 0;
		for (int j = 2; j <= 5; ++j)
			for (int k = 1; k <= 5; ++k) {
				if (s[j - 1][k]) {
					++tmp;
					s[j][k] ^= 1;
					s[j - 1][k] ^= 1;
					s[j + 1][k] ^= 1;
					s[j][k - 1] ^= 1;
					s[j][k + 1] ^= 1;
				}
			}
		for (int j = 1; j <= 5; ++j)
			if (s[5][j]) {
				puts("NO");
				return 0;
			}
		res += tmp;
	}
	
	memset(f, -1, sizeof(f));
	f[0][0] = 0;
	for (int i = 1; i <= n; ++i)
		f[1 << (i - 1)][i] = a[0][i];
	
	for (int i = 2; i < (1 << n); ++i)
		for (int j = 1; j <= n; ++j)
			if ((1 << j - 1) & i)
				for (int k = 1; k <= n; ++k)
					if ((1 << k - 1) & (i ^ (1 << j - 1)))
						chk_min(f[i][j], f[i ^ (1 << (j - 1))][k] + a[k][j]);
	puts("YES");
	tmp = -1;
	for (int i = 1; i <= n; ++i)
		chk_min(tmp, f[(1 << n) - 1][i] + a[i][0]);
	printf("%d\n", res * k + tmp);
	return 0;
}
