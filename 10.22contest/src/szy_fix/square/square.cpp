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

const int N = 2e5 + 5;

int n, qwq[N + 1], *pre = qwq + 1, suf[N], res;

int main() {
	freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);
	n = in();
	for (int i = 1; i <= n; ++i)
		pre[i] = pre[i - 2] + in();
	for (int i = n; i; --i)
		suf[i] = suf[i + 2] + pre[i] - pre[i - 2];
	for (int i = 1; i <= n; ++i)
		res += (pre[i - 2] + suf[i + 1] == pre[i - 1] + suf[i + 2]);
	printf("%d\n", res);
	return 0;
}
