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

const int N = 1e5 + 5;

int n, k, max, tmp, fa[N];
int vis[21];

int main() {
    freopen("in", "r", stdin);
    freopen("bf.out", "w", stdout);
    int T = in();
    while (T--) {
        n = in(), k = in();
        for (int i = 2; i <= n; ++i)
            fa[i] = in();
        max = 0;
        for (int s = 1, i; s < (1 << (n - 1)); ++s) {
            memset(vis, 0, sizeof(vis));
            tmp = 0;
            for (i = 2; i <= n; ++i) {
                if ((1 << (i - 2)) & s) {
                    if (vis[i] || vis[fa[i]]) {
                        break;
                    }
                    vis[i] = vis[fa[i]] = 1;
                    ++tmp;
                }
            }
            if (i > n) {
                chk_max(max, tmp);
            }
        }
        if (max + max >= k) {
            printf("%d\n", (k + 1) >> 1);
        } else {
            printf("%d\n", k - max);
        }
    }
    return 0;
}
