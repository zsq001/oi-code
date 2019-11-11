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
} e[N];
int ecnt, head[N];
int n, k;
int f[N][2];

inline void add_edge(const int u, const int v) {
    e[++ecnt] = (edge){head[u], v}, head[u] = ecnt;
}

void dfs(const int u) {
    f[u][0] = f[u][1] = 0;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        dfs(v);
        f[u][0] += std::max(f[v][0], f[v][1]);
    }
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        chk_max(f[u][1], f[u][0] - std::max(f[v][0], f[v][1]) + f[v][0] + 1);
    }
}

int main() {
    //freopen("in", "r", stdin);
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int T = in();
    while (T--) {
        ecnt = 1;
        memset(head, 0, sizeof(head));
        n = in(), k = in();
        for (int i = 2, fa; i <= n; ++i)
            fa = in(), add_edge(fa, i);
        dfs(1);
        int tmp = std::max(f[1][0], f[1][1]);
        if (tmp + tmp >= k) {
            printf("%d\n", (k + 1) >> 1);
        } else {
            printf("%d\n", k - tmp);
        }
    }
    return 0;
}
