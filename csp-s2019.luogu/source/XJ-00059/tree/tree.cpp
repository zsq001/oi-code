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
template<typename T>void chk_min(T &_, T __) { _ = _ < __ ? _ : __; }
template<typename T>void chk_max(T &_, T __) { _ = _ > __ ? _ : __; }

const int N = 2005;

struct edge {
    int next, to;
} e[N << 1];
int ecnt, head[N], deg[N];
int a[N], pos[N];
int n, m;
bool ban[N], vis[N];

inline void add_edge(const int u, const int v) {
    e[++ecnt] = (edge){head[u], v}, head[u] = ecnt;
    e[++ecnt] = (edge){head[v], u}, head[v] = ecnt;
    ++deg[u], ++deg[v];
}

inline void init() {
    ecnt = 1;
    memset(head, 0, sizeof(head));
    memset(ban, 0, sizeof(ban));
}

int get_min(const int u, const int fa = -1) {
    vis[u] = 1;
    int ret = ~fa ? u : n + 1;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if (v == fa || ban[i >> 1])
            continue;
        chk_min(ret, get_min(v, u));
    }
    return ret;
}


bool eliminate(const int u, const int t, const int fa = -1) {
    if (u == t)
        return 1;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if (v == fa || ban[i >> 1])
            continue;
        if (eliminate(v, t, u)) {
            std::swap(a[u], a[v]);
            std::swap(pos[a[u]], pos[a[v]]);
            ban[i >> 1] = 1;
            --m;
            return 1;
        }
    }
    return 0;
}

int main() {
    //freopen("tree3.in", "r", stdin);
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int T = in();
    while (T--) {
        init();
        n = in();
        for (int i = 1; i <= n; ++i)
            a[i] = in(), pos[a[i]] = i;
        for (int i = 1; i < n; ++i)
            add_edge(in(), in());
        m = n - 1;
        while (m) {
            memset(vis, 0, sizeof(vis));
            for (int j = 1, t; j <= n; ++j) {
                int i = pos[j];
                if (!vis[i]) {
                    t = get_min(i);
                    if (t == n + 1)
                        continue;
                    eliminate(t, i);
                }
            }
        }
        for (int i = 1; i <= n; ++i)
            printf("%d ", pos[i]);
        puts("");
    }
    return 0;
}
