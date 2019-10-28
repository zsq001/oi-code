#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
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
} e[N << 2];
int ecnt = 1, head[N << 1];
int n;
bool f[2005][2005];
long long res;

void dfs(const int now, const int u) {
    f[now][u] = 1;
    for (int i = head[u]; i; i = e[i].next)
        dfs(now, e[i].to);
}

int main() {
    //freopen("in", "r", stdin);
    freopen("climb.in", "r", stdin);
    freopen("climb.out", "w", stdout);
    n = in();
    for (int i = 1, x, y; i < n; ++i) {
        x = in(), y = in();
        e[++ecnt] = (edge){head[x], y}, head[x] = ecnt;
    }
    for (int i = 1, x, y; i < n; ++i) {
        x = in() + n, y = in() + n;
        e[++ecnt] = (edge){head[x], y}, head[x] = ecnt;
    }
    for (int i = 1; i <= n + n; ++i)
        dfs(i, i);
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            res += f[i][j] & f[i + n][j + n];
    printf("%lld\n", res);
    return 0;
}
