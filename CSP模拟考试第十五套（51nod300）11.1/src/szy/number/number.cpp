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

const int N = 1e6 + 5, mod = 1e9 + 7;

int n;

int dp() {
    static int f[N], bi[25];
    bi[0] = 1;
    for (int i = 1; i < 25; ++i)
        bi[i] = bi[i - 1] << 1;
    f[0] = 1;
    for (int i = 0; bi[i] <= n; ++i) {
        for (int j = bi[i]; j <= n; ++j) {
            f[j] += f[j - bi[i]];
            if (f[j] >= mod)
                f[j] -= mod;
        }
    }
    return f[n];
}

int main() {
    //freopen("in", "r", stdin);
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    n = in();
    printf("%d\n", dp());
    return 0;
}
