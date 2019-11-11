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

struct edge {
    int next, to;
} e[N << 1];
int ecnt = 1, head[N];
int n, m;

inline void add_edge(const int u, const int v) {
    e[++ecnt] = (edge){head[u], v}, head[u] = ecnt;
    e[++ecnt] = (edge){head[v], u}, head[v] = ecnt;
}

int fa[N][19], dep[N], bi[25], siz[N];
void prep(const int u) {
    siz[u] = 1;
    for (int i = 1; i < 17 && bi[i] <= dep[u]; ++i)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if (v == fa[u][0])
            continue;
        fa[v][0] = u;
        dep[v] = dep[u] + 1;
        prep(v);
        siz[u] += siz[v];
    }
}
int get_k(int u, int k) {
    for (int i = 0; i < 17; ++i)
        if (k & bi[i])
            u = fa[u][i];
    return u;
}
int get_lca(int u, int v) {
    if (dep[u] > dep[v])
        std::swap(u, v);
    v = get_k(v, dep[v] - dep[u]);
    if (u == v)
        return u;
    for (int i = 16; i >= 0; --i)
        if (fa[u][i] != fa[v][i])
            u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}

inline int calc(int u, int v) {
    if (u == v)
        return n;
    if (dep[u] > dep[v])
        std::swap(u, v);
    int lca = get_lca(u, v);
    int dis = dep[u] + dep[v] - dep[lca] - dep[lca] + 1;
    if (~dis & 1)
        return 0;
    dis >>= 1;
    if (dep[u] == dep[v])
        return n - siz[get_k(u, dis - 1)] - siz[get_k(v, dis - 1)];
    return siz[get_k(v, dis)] - siz[get_k(v, dis - 1)];
}

int main() {
    //freopen("in", "r", stdin);
    freopen("equal.in", "r", stdin);
    freopen("equal.out", "w", stdout);
    n = in();
    for (int i = 1; i < n; ++i)
        add_edge(in(), in());
    bi[0] = 1;
    for (int i = 1; i < 25; ++i)
        bi[i] = bi[i - 1] << 1;
    prep(1);
    m = in();
    while (m--)
        printf("%d\n", calc(in(), in()));
    return 0;
}
