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

struct edge {
    int next, to;
} e[N << 1];
int ecnt = 1, head[N];
int f[N], g[N];
int n, res;
int deg[N];

void add_edge(const int u, const int v) {
    e[++ecnt] = (edge){head[u], v}, head[u] = ecnt;
    e[++ecnt] = (edge){head[v], u}, head[v] = ecnt;
    ++deg[u], ++deg[v];
}

void dfs(const int u, const int fa = -1) {
    int tmp = 1;
    bool flag = 0;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if (v == fa)
            continue;
        dfs(v, u);
        flag = 1;
        tmp = 1ll * tmp * f[v] % mod;
    }
    if (flag) {
        f[u] = (tmp + tmp) % mod;
    } else {
        f[u] = 1;
    }
}

inline int qpow(int base, int b, int ret = 1) {
    for (; b; b >>= 1, base = 1ll * base * base % mod)
        if (b & 1)
            ret = 1ll * ret * base % mod;
    return ret;
}

void calc(const int u, const int fa = -1) {
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if (v == fa)
            continue;
        g[v] = g[u];
        if (deg[u] == 1 && deg[v] > 1) {
            g[v] = g[u] * 500000004ll % mod;
        }
        if (deg[u] > 1 && deg[v] == 1) {
            g[v] = g[u] * 2ll % mod;
        }
        calc(v, u);
    }
}

int main() {
    //freopen("in", "r", stdin);
    freopen("huazhong.in", "r", stdin);
    freopen("huazhong.out", "w", stdout);
    n = in();
    for (int i = 1; i < n; ++i)
        add_edge(in(), in());
    dfs(1);
    g[1] = f[1];
    calc(1);
    for (int i = 1; i <= n; ++i)
        res += g[i], res = res >= mod ? res - mod : res;
    printf("%d\n", res);
    return 0;
}
