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

const int N = 5e5 + 5;

struct edge {
    int next, to;
} e[N];
int ecnt = 1, head[N];
int n;
int qwq[N << 1];
int *buk = qwq + N;
char s[N];
long long res;

inline void add_edge(const int u, const int v) {
    e[++ecnt] = (edge){head[u], v}, head[u] = ecnt;
}

void dfs(const int u, int f, long long now) {
    int tmp = buk[f];
    if (s[u] == '(')
        buk[f] = 0;
    now += buk[f];
    ++buk[f];
    res ^= now * u;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to, t = f + (s[v] == '(' ? -1 : 1);
        dfs(v, t, now);
    }
    buk[f] = tmp;
}

void asdf(int f, long long now) {
    f = 0, now = 0;
    for (int i = 1; i <= n; ++i) {
        f += (s[i] == '(' ? -1 : 1);
        if (s[i] == '(')
            buk[f] = 0;
        now += buk[f];
        ++buk[f];
        res ^= now * i;
    }
}

int main() {
    //freopen("brackets2.in", "r", stdin);
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    n = in();
    scanf(" %s", s + 1);
    for (int i = 2, fa; i <= n; ++i)
        fa = in(), add_edge(fa, i);
    buk[0] = 1;
    dfs(1, (s[1] == '(' ? -1 : 1), 0);
    printf("%lld\n", res);
    return 0;
}
