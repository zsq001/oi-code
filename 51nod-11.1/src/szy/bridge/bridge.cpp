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

char s[N];
int n, d;
int f[N][N];

int main() {
    //freopen("in", "r", stdin);
    freopen("bridge.in", "r", stdin);
    freopen("bridge.out", "w", stdout);
    int T = in();
    while (T--) {
        n = in(), d = in();
        for (int i = 1; i <= n; ++i) {
            scanf(" %s", s + 1);
            for (int j = 1; j <= n; ++j)
                f[i][j] = (s[j] == 'Y') ? d : -1;
        }
        for (int k = 1; k <= n; ++k)
            for (int i = 1; i < n; ++i)
                if (~f[i][k])
                    for (int j = i + 1; j <= n; ++j)
                        if (~f[k][j]) {
                            if (!~f[i][j])
                                f[i][j] = f[j][i] = f[i][k] + f[k][j];
                            else
                                chk_min(f[i][j], f[i][k] + f[k][j]), f[j][i] = f[i][j];
                        }
        int res = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j)
                if (~f[i][j]) {
                    chk_max(res, f[i][j]);
                } else {
                    res = -1;
                    break;
                }
            if (!~res)
                break;
        }
        printf("%d\n", res);
    }
    return 0;
}
