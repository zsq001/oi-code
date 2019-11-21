#include <cstdio>

typedef long long ll;
const int maxn = 5e5 + 5;
int n, cnt, tp, tp2, fa[maxn], head[maxn], col[maxn], stk[maxn], f[maxn];
ll totans;
struct edge {
    int v, nxt;
}e[maxn];

int in(int r = 0) {
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {
        r = (r << 1) + (r << 3) + (c ^ '0');
        c = getchar();
    }
    return r;
}

int gin() {
    char c = getchar();
    while (c != '(' && c != ')') c = getchar();
    return c == '(' ? -1 : 1;
}

void add (int u, int v) {
    fa[v] = u;
    e[++cnt].v = v;
    e[cnt].nxt = head[u];
    head[u]= cnt;
}

void dfs(int x, ll ans = 0) {
    int tmp = tp2;
    stk[++tp] = x;
    if (col[x] == 1 && tp2 && col[stk[tp2]] == -1) {
        f[x] = f[fa[stk[tp2--]]] + 1;
    } else {
        tp2 = tp;
    }
    ans += f[x];
    totans ^= (ll)x * ans;
    for (int i = head[x]; i; i = e[i].nxt) dfs(e[i].v, ans);
    --tp;
    tp2 = tmp;
}

int main() {
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    int n = in();
    for (int i = 1; i <= n; ++i) col[i] = gin();
    for (int i = 2; i <= n; ++i) add(in(), i);
    dfs(1);
    printf("%lld\n", totans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
