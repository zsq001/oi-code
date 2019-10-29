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

const int N = 1e3 + 5, mod = 1e9 + 7;

int pri[10005], pcnt;
int n, m, nn;
int a[N], s[N], p[101], c[101];

void init() {
    for (int i = 2, j; i <= 10000; ++i) {
        for (j = 2; j * j <= i; ++j)
            if (i % j == 0)
                break;
        if (j * j > i)
            pri[++pcnt] = i;
    }
}

void prep() {
    memset(c, 0, sizeof(c));
    memset(s, 0, sizeof(s));
    nn = 0;
    for (int i = 1; i <= pcnt && pri[i] * pri[i] <= m; ++i) {
        if (m % pri[i] == 0) {
            p[++nn] = pri[i];
            while (m % pri[i] == 0)
                m /= pri[i], ++c[nn];
        }
    }
    if (m != 1)
        p[++nn] = m, c[nn] = 1;
    c[0] = 1;
    for (int i = 1; i <= nn; ++i)
        c[i] = c[i - 1] * (c[i] + 1);
    static int tmp[25];
    for (int i = 1; i <= n; ++i) {
        memset(tmp, 0, sizeof(tmp));
        for (int j = 1; j <= nn; ++j) {
            while (a[i] % p[j] == 0)
                a[i] /= p[j], ++tmp[j];
            s[i] += c[j - 1] * tmp[j];
        }
    }
}

int dp() {
    static int f[N];
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (int i = 1, cur = 1; i <= n; ++i, cur ^= 1) {
        for (int j = c[nn] - s[i] - 1; j >= 0; --j) {
            f[j + s[i]] += f[j];
            if (f[j + s[i]] >= mod)
                f[j + s[i]] -= mod;
        }
    }
    return f[c[nn] - 1];
}

int main() {
    //freopen("in", "r", stdin);
    freopen("banana.in", "r", stdin);
    freopen("banana.out", "w", stdout);
    init();
    int T = in();
    while (T--) {
        n = in(), m = in();
        for (int i = 1; i <= n; ++i) {
            a[i] = in();
            if (m % a[i])
                --i, --n;
        }
        prep();
        printf("%d\n", dp());
    }
    return 0;
}
