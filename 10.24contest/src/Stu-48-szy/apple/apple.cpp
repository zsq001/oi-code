#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
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

const int N = 5e4 + 5;

std::vector<int> ver[N];
int tmp[N];
int len[N], lef[N];
int n, rt;
int f[N], id[N];

inline bool cmp(const int &i, const int &j) {
    if (f[i] == f[j])
        return i < j;
    return f[i] > f[j];
}
inline void jb(const int u, const int v) {
    ver[u].push_back(v), ver[v].push_back(u);
}

void dfs(const int u, const int fa = -1) {
    len[u] = 1, lef[u] = u;
    for (unsigned i = 0; i < ver[u].size(); ++i) {
        int v = ver[u][i];
        if (v == fa)
            continue;
        dfs(v, u);
        if (len[u] < len[v] + 1 || (len[u] == len[v] + 1 && lef[u] > lef[v]))
            len[u] = len[v] + 1, lef[u] = lef[v];
    }
    chk_max(f[lef[u]], len[u]);
}

int main() {
    //freopen("in", "r", stdin);
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    n = in(), rt = in() + 1;
    if (n == 1)
        return puts("0"), 0;
    for (int i = 2; i <= n; ++i)
        jb (i, in() + 1);
    dfs(rt);
    for (int i = 1; i <= n; ++i)
        id[i] = i;
    std::sort(id + 1, id + 1 + n, cmp);
    printf("%d\n", rt - 1);
    for (int i = 1; i <= n; ++i)
        if (f[id[i]])
            printf("%d\n", id[i] - 1);
    return 0;
}
