#include <cstdio>
#include <cstring>
#include <algorithm>
typedef double db;
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

const int N = 1e3 + 5;
const double eps = 1e-4;

struct edge {
    int next, to, w;
} e[N << 1];
int ecnt = 1, head[N];
int w[N];
int vis[N], f[N], t[N];
int n, m;
db res;

void dfs(const int u) {
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if (f[v]) {
            chk_max(res, 1.0 * (f[u]- f[v] + w[v]) / (t[u] - t[v] + e[i].w));
        } else {
            f[v] = f[u] + w[v], t[v] = t[u] + e[i].w;
            dfs(v);
            f[v] = t[v] = 0;
        }
    }
}

int main() {
    //freopen("in", "r", stdin);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    n = in(), m = in();
    for (int i = 1; i <= n; ++i)
        w[i] = in();
    while (m--) {
        int u = in(), v = in(), w = in();
        e[++ecnt] = (edge){head[u], v, w}, head[u] = ecnt;
    }
    for (int i = 1; i <= n; ++i)
        dfs(i);
    printf("%.2lf\n", res);
    return 0;
}
