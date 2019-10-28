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

const int N = 2e3 + 5;

char s[N];
int n, f[N][N], g[N][N];

void dp() {
    for (int i = 1; i <= n; ++i) {
        f[i][i] = g[i][i] = 1;
        g[i][i + 1] = (s[i] == s[i + 1]);
        f[i][i + 1] = 2 + g[i][i + 1];
    }
    for (int len = 3; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            g[i][j] = g[i + 1][j - 1] && s[i] == s[j];
            f[i][j] = f[i + 1][j] + f[i][j - 1] + g[i][j] - f[i + 1][j - 1];
        }
    }
}

long long calc() {
    long long ret = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j)
            if (g[i][j])
                ret += f[1][i - 1];
    return ret;
}

int main() {
    //freopen("in", "r", stdin);
    freopen("calc.in", "r", stdin);
    freopen("calc.out", "w", stdin);
    scanf(" %s", s + 1);
    n = strlen(s + 1);
    dp();
    printf("%lld\n", calc());
    return 0;
}
