#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
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
const double eps = 1e-6;

struct node {
    int typ, x;
} a[N];
int n, k, c, w;

namespace small_n {
    double f[2][1005][1005], mp[1005][1005];
    int main() {
        double res = 0;
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j) {
                if (!i && !j) {
                    mp[i][j] = w;
                    continue;
                }
                f[0][i][j] = f[1][i][j] = -1000000000;
                if (i)
                    mp[i][j] = mp[i - 1][j] * (1 - 0.01 * k);
                else
                    mp[i][j] = mp[i][j - 1] * (1 + 0.01 * c);
            }
        for (int i = 1, x = 0, y = 0, cur = 1; i <= n; ++i, cur ^= 1) {
            x += (a[i].typ == 1), y += (a[i].typ == 2);
            for (int j = 0; j <= x; ++j)
                for (int k = 0; k <= y; ++k) {
                    f[cur][j][k] = f[cur ^ 1][j][k];
                    if (a[i].typ == 1 && j) {
                        double tmp = f[cur ^ 1][j - 1][k] + mp[j - 1][k] * a[i].x;
                        if (tmp > 0 && f[cur][j][k] - tmp < eps)
                            f[cur][j][k] = tmp;
                    } else if (a[i].typ == 2 && k) {
                        double tmp = f[cur ^ 1][j][k - 1] - mp[j][k - 1] * a[i].x;
                        if (tmp > 0 && f[cur][j][k] - tmp < eps)
                            f[cur][j][k] = tmp;
                    }
                    if (res - f[cur][j][k] < eps)
                        res = f[cur][j][k];
                }
        }
        printf("%.2lf\n", res);
        return 0;
    }
}

namespace once {
    int main() {
        int res = 0;
        for (int i = 1; i <= n; ++i)
            chk_max(res, a[i].x);
        printf("%.2lf\n", 1.0 * res * w);
        return 0;
    }
}

int main() {
    //freopen("in", "r", stdin);
    freopen("coal.in", "r", stdin);
    freopen("coal.out", "w", stdout);
    n = in(), k = in(), c = in(), w = in();
    for (int i = 1; i <= n; ++i)
        a[i].typ = in(), a[i].x = in();
    if (k == 100) {
        once::main();
    } else if (n <= 1000) {
        small_n::main();
    }
    return 0;
}
