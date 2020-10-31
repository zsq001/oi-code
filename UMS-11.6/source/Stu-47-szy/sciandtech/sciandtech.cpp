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

const int N = 1e3 + 5, M = 5e3 + 5;

struct edge {
    int next, to;
} e[N << 1];
int ecnt = 1, head[N];
int n, val[N];
int f[M][2];

void add_edge(const int u, const int v) {
    e[++ecnt] = (edge){head[u], v}, head[u] = ecnt;
}

int t[M];
void dfs(const int u) {
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        dfs(v);
    }
    memset(t, 0, sizeof(t));
    for (int i = head[u]; i; i = e[i].next) {
    }
}

int main() {
    //freopen("in", "r", stdin);
    freopen("sciandtech.in", "r", stdin);
    freopen("sciandtech.out", "w", stdout);
    n = in();
    for (int i = 2, fa; i <= n; ++i) {
        fa = in();
        add_edge(fa, i);
    }
    for (int i = 1; i <= n; ++i)
        val[i] = in();
    return 0;
}
