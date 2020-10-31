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
template<typename T>
void out(T _) {
    if (_ < 0)
        putchar('-'), _ = -_;
    if (_ < 9)
        return (void)(putchar(_ ^ 48));
    out(_ / 10);
    putchar((_ % 10) ^ 48);
}
template<typename T>
void out_ln(T _) {
    out(_), puts("");
}
template<typename T>inline void chk_min(T &_, T __) { _ = _ < __ ? _ : __; }
template<typename T>inline void chk_max(T &_, T __) { _ = _ > __ ? _ : __; }

const int N = 205, M = 2005;
const double eps = 1e-6;

struct edge {
    int next, to, w;
} e[M];
int ecnt = 1, head[N];
int ind_base[N];
int n, m;

void add_edge(const int u, const int v, const int w) {
    e[++ecnt] = (edge){head[u], v, w}, head[u] = ecnt;
    ++ind_base[v];
}

void prep() {
    static int q[N], l, r;
    l = r = 0;
    for (int i = 2; i <= n; ++i)
        if (!ind_base[i])
            q[r++] = i;
    while (l < r) {
        int u = q[l++];
        for (int i = head[u]; i; i = e[i].next) {
            int v = e[i].to;
            --ind_base[v];
            if (!ind_base[v] && v != 1)
                q[r++] = v;
        }
    }
}

bool chk(const double mid) {
    static int q[N], ind[N], l, r;
    static double f[N];
    for (int i = 1; i <= n; ++i)
        f[i] = 1e9;
    memcpy(ind, ind_base, sizeof(ind_base));
    l = r = 0;
    q[r++] = 1, f[1] = -mid;
    while (l < r) {
        int u = q[l++];
        for (int i = head[u]; i; i = e[i].next) {
            int v = e[i].to;
            if (f[u] + e[i].w - mid - f[v] < 0)
                f[v] = f[u] + e[i].w - mid;
            --ind[v];
            if (!ind[v])
                q[r++] = v;
        }
    }
    return f[n] <= 0;
}

double binary_search(double l, double r) {
    double mid;
    while (r - l > eps) {
        mid = (l + r) / 2;
        if (chk(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return l;
}

int main() {
    //freopen("in", "r", stdin);
    freopen("calabash.in", "r", stdin);
    freopen("calabash.out", "w", stdout);
    n = in(), m = in();
    while (m--) {
        int x = in(), y = in(), z = in();
        add_edge(x, y, z);
    }
    prep();
    printf("%.4lf\n", binary_search(0, 1e3));
    return 0;
}
