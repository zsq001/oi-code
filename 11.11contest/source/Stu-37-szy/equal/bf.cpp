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

int fa[N], dep[N];
void prep(const int u) {
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if (v == fa[u])
            continue;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        prep(v);
    }
}
int get_lca(int u, int v) {
    if (dep[u] > dep[v])
        std::swap(u, v);
    while (dep[v] != dep[u])
        v = fa[v];
    while (u != v)
        u = fa[u], v = fa[v];
    return u;
}
inline int dist(int u, int v) {
    return dep[u] + dep[v] - dep[get_lca(u, v)] * 2;
}

inline int calc(int u, int v) {
    int ret = 0;
    for (int i = 1; i <= n; ++i)
        if (dist(u, i) == dist(i, v))
            ++ret;
    return ret;
}

int main() {
    freopen("in", "r", stdin);
    //freopen("equal.in", "r", stdin);
    freopen("bf.out", "w", stdout);
    n = in();
    for (int i = 1; i < n; ++i)
        add_edge(in(), in());
    prep(1);
    m = in();
    while (m--)
        printf("%d\n", calc(in(), in()));
    return 0;
}
