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

const int N = 105, M = 2005, mod = 998244353;

inline void add(int &_, int __) {
    _ += __;
    if (_ >= mod)
        _ -= mod;
    if (_ < 0)
        _ += mod;
}

int n, m;
int a[N][M], pre[N][M];

int main() {
    //freopen("meal4.in", "r", stdin);
    freopen("meal.in", "r", stdin);
    freopen("meal.out", "w", stdout);
    n = in(), m = in();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            a[i][j] = in(), pre[i][j] = (pre[i - 1][j] + a[i][j]) % mod;
    if (m == 2) {
        int res = 1ll * pre[n][1] * pre[n][2] % mod;
        for (int i = 1; i <= n; ++i)
            add(res, -1ll * a[i][1] * a[i][2] % mod);
        printf("%d\n", res);
    } else if (m == 3) {
        int res = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                for (int k = 1; k <= n; ++k) {
                    if (i == j || j == k || i == k)
                        continue;
                    add(res, 1ll * a[i][1] * a[j][2] % mod * a[k][3] % mod);
                }
        add(res, 1ll * pre[n][1] * pre[n][2] % mod);
        for (int i = 1; i <= n; ++i)
            add(res, -1ll * a[i][1] * a[i][2] % mod);
        add(res, 1ll * pre[n][1] * pre[n][3] % mod);
        for (int i = 1; i <= n; ++i)
            add(res, -1ll * a[i][1] * a[i][3] % mod);
        add(res, 1ll * pre[n][3] * pre[n][2] % mod);
        for (int i = 1; i <= n; ++i)
            add(res, -1ll * a[i][3] * a[i][2] % mod);
        printf("%d\n", res);
    }
    return 0;
}
