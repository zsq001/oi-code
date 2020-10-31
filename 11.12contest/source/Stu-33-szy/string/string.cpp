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

const int N = 2e5 + 5, mod = 998244853;

int n, h[N], bi[N];
char s[N];

int qpow(int base, int b, int ret = 1) {
    for (; b; b >>= 1, base = 1ll * base * base % mod)
        if (b & 1)
            ret = 1ll * ret * base % mod;
    return ret;
}

void prep() {
    bi[0] = 1;
    for (int i = 1; i <= n; ++i) {
        h[i] = (137ll * h[i - 1] + s[i]) % mod;
        bi[i] = 137ll * bi[i - 1] % mod;
    }
}

inline int calc(const int i, const int j) {
    return (h[j] - 1ll * h[i - 1] * bi[j - i + 1] % mod + mod) % mod;
}

int binary_search(int l, int r) {
    int x = l, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (calc(x, mid) == h[mid - x + 1]) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

bool chk(const int len) {
    bool used = 0;
    int i, j, k;
    for (i = len + 1; i + len <= n; i += len) {
        j = i + len - 1;
        if (calc(i, j) != h[len]) {
            if (used)
                return 0;
            k = binary_search(i, j);
            if (calc(k + 1, j + 1) != calc(k - i + 1, len))
                return 0;
            ++i;
            used = 1;
        }
    }
    if (i <= n && calc(i, n) != h[n - i + 1]) {
        if (used)
            return 0;
        if (i == n)
            return 1;
        k = binary_search(i, n);
        if (calc(k + 1, n) != calc(k - i + 1, n - i))
            return 0;
        ++i;
        used = 1;
    }
    return 1;
}

int main() {
    //freopen("in", "r", stdin);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int T = in();
    while (T--) {
        n = in();
        scanf(" %s", s + 1);
        prep();
        int res;
        for (res = 1; res < n; ++res)
            if (chk(res))
                break;
        printf("%d\n", res);
    }
    return 0;
}
