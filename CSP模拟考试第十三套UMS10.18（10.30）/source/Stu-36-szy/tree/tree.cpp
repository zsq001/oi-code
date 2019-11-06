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
int n, m, w[N];

inline void add_edge(const int u, const int v) {
    e[++ecnt] = (edge){head[u], v}, head[u] = ecnt;
    e[++ecnt] = (edge){head[v], u}, head[v] = ecnt;
}


struct segment_tree {
    long long sum[N << 2];
    long long lazy[N << 2];
    inline void push_up(const int p) {
        sum[p] = sum[p << 1] + sum[p << 1 | 1];
    }
    inline void spread(const int p, const int tl, const int tr, const int mid) {
        sum[p << 1] += lazy[p] * (mid - tl + 1);
        sum[p << 1 | 1] += lazy[p] * (tr - mid);
        lazy[p << 1] += lazy[p];
        lazy[p << 1 | 1] += lazy[p];
        lazy[p] = 0;
    }
    void modify(int l, int r, int k, int tl = 1, int tr = n, int p = 1) {
        if (l <= tl && tr <= r) {
            sum[p] += 1ll * k * (tr - tl + 1);
            lazy[p] += k;
            return ;
        }
        int mid = (tl + tr) >> 1;
        if (lazy[p])
            spread(p, tl, tr, mid);
        if (mid >= l)
            modify(l, r, k, tl, mid, p << 1);
        if (mid < r)
            modify(l, r, k, mid + 1, tr, p << 1 | 1);
        push_up(p);
    }
    long long query(int l, int r, int tl = 1, int tr = n, int p = 1) {
        if (l <= tl && tr <= r)
            return sum[p];
        int mid = (tl + tr) >> 1;
        if (lazy[p])
            spread(p, tl, tr, mid);
        if (mid < l)
            return query(l, r, mid + 1, tr, p << 1 | 1);
        if (mid >= r)
            return query(l, r, tl, mid, p << 1);
        return query(l, r, tl, mid, p << 1) + query(l, r, mid + 1, tr, p << 1 | 1);
    }
} T;

//heavy-light decomposition begin
int siz[N], hson[N], fa[N], fro[N], dfn[N];
void dfs1(const int u) {
    siz[u] = 1;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if (v == fa[u])
            continue;
        fa[v] = u;
        dfs1(v);
        siz[u] += siz[v];
        if (siz[v] > siz[hson[u]])
            hson[u] = v;
    }
}
void dfs2(const int u, const int tp) {
    fro[u] = tp;
    dfn[u] = ++dfn[0];
    if (hson[u])
        dfs2(hson[u], tp);
    for (int i = head[u]; i; i = e[i].next)
        if (e[i].to != fa[u] && e[i].to != hson[u])
            dfs2(e[i].to, e[i].to);
}
//heavy-light decomposition end

long long query(int u) {
    long long ret = 0;
    while (u) {
        ret += T.query(dfn[fro[u]], dfn[u]);
        u = fa[fro[u]];
    }
    return ret;
}

int main() {
    //freopen("in", "r", stdin);
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    n = in(), m = in();
    for (int i = 1; i <= n; ++i)
        w[i] = in();
    for (int i = 1; i < n; ++i)
        add_edge(in(), in());
    dfs1(1), dfs2(1, 1);
    for (int i = 1; i <= n; ++i)
        T.modify(dfn[i], dfn[i], w[i]);
    while (m--) {
        int typ = in(), x = in(), a;
        if (typ == 1) {
            a = in();
            T.modify(dfn[x], dfn[x], a);
        } else if (typ == 2) {
            a = in();
            T.modify(dfn[x], dfn[x] + siz[x] - 1, a);
        } else {
            printf("%lld\n", query(x));
        }
    }
    return 0;
}
