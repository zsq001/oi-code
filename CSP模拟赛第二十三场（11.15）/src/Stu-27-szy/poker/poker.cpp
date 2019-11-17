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

const int N = 55;

int n, m, res;
int c[N];

bool chk(int lim) {
	long long now = 0;
	for (int i = 1; i <= n; ++i)
		if (c[i] < lim)
			now += lim - c[i];
	return now <= lim;
}

int binary_search(int l, int r) {
	int mid;
	while (l < r) {
		mid = (l + r + 1) >> 1;
		if (chk(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	return l;
}

int main() {
	//freopen("in", "r", stdin);
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	n = in(), m = in();
	for (int i = 1; i <= n; ++i)
		c[i] = in();
	printf("%d\n", binary_search(0, m));
	return 0;
}
