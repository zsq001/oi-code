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

const int N = 5e3 + 5;

char s[N];
int n, f[N], g[N];

void work() {
	for (int i = 1; i <= n; ++i)
		for (int j = 0; i - j > 0 && i + 1 + j <= n && s[i - j] == s[i + 1 + j]; ++j)
			++f[i + 1 + j], ++g[i - j];
	for (int i = 1; i <= n; ++i)
		for (int j = 0; i - j > 0 && i + j <= n && s[i - j] == s[i + j]; ++j)
			++f[i + j], ++g[i - j];
	for (int i = 1; i <= n; ++i)
		f[i] += f[i - 1];
}

long long calc() {
    long long ret = 0;
    for (int i = 1; i < n; ++i)
    	ret += 1ll * f[i] * g[i + 1];
    return ret;
}

int main() {
//    freopen("in", "r", stdin);
//    freopen("calc.in", "r", stdin);
//    freopen("calc.out", "w", stdin);
    scanf(" %s", s + 1);
    n = strlen(s + 1);
    work();
    printf("%lld\n", calc());
    return 0;
}
