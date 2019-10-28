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

const int N = 305;

int n, nn, s[N * N];

int main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	n = in(), nn = n * (n - 1) / 2;
	for (int i = 1; i <= nn; ++i)
		s[i] = in();
	std::sort(s + 1, s + 1 + nn);
	return 0;
} 
