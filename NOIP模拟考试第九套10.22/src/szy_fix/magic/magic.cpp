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

const int mod = 1e9 + 7;

int qpow(int base, int b, int ret = 1) {
	for (; b; b >>= 1, base = 1ll * base * base % mod)
		if (b & 1)
			ret = 1ll * ret * base % mod;
	return ret;
}

int n;

int main() {
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
	n = in();
	printf("%lld\n", 1ll * (qpow(3, n + 1) - 1 + mod) % mod * 500000004ll % mod);
	return 0;
}
