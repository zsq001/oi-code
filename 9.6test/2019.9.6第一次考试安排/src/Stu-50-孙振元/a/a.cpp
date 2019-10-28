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

const int N = 105;

int T, n, t[3];

int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	T = in();
	while (T--) {
		n = in();
		t[0] = t[1] = t[2] = 0;
		for (int i = 1; i <= n; ++i)
			++t[in() % 3];
		if (t[1] > t[2]) {
			printf("%d\n", t[0] + t[2] + (t[1] - t[2]) / 3);
		} else {
			printf("%d\n", t[0] + t[1] + (t[2] - t[1]) / 3);
		}
	}
	return 0;
}
