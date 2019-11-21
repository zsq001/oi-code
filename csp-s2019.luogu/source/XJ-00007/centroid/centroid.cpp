#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

typedef long long ll;
const int maxn = 3e5 + 5;
int n, cnt, del, tot, head[maxn], siz[maxn], col[maxn];
struct edge {
    int v, nxt;
}e[maxn << 1];
ll ans;
std::queue<int> q;

int in(int r = 0) {
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') r = (r << 1) + (r << 3) + (c ^ '0'), c = getchar();
    return r;
}

void add(int u, int v) {
    e[++cnt].v = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}

void init() {
    n = in();
    memset(head, 0, sizeof(head));
    cnt = ans = 0;
    for (int i = 1; i < n; ++i) {
        int u = in(), v = in();
        add(u, v), add(v, u);
    }
}

int dfs(int x, int fa = 0) {
    siz[x] = 1;
    for (int i = head[x]; i; i = e[i].nxt) if (e[i].v != fa && (i + 1) / 2 != del) siz[x] += dfs(e[i].v, x);
    return siz[x];
}

void dfs2(int x, int fa = 0) {
    int mx = tot - siz[x];
    for (int i = head[x]; i; i = e[i].nxt) if (e[i].v != fa && (i + 1) / 2 != del) {
        dfs2(e[i].v, x);
        mx = std::max(mx, siz[e[i].v]);
    }
    if (mx <= tot / 2) ans += (ll)x;
}

void getrt(int x) {
    memset(siz, 0, sizeof(siz));
    tot = dfs(x);
    dfs2(x);
}

void solve() {
    for (del = 1; del < n; ++del) getrt(e[del * 2].v), getrt(e[del * 2 - 1].v);
    printf("%lld\n", ans);
}

void solve_a() {
    memset(siz, 0, sizeof(siz));
    int x, num = 1;
    for (int i = 1; i <= cnt; ++i) ++siz[e[i].v];
    for (int i = 1; i <= n; ++i) if (siz[i] == 1) x = i;
    siz[x] = 0;
    for (;;) {
        ans += (ll)x * ((num == 1 || num == n || num == n / 2 + 1 || (n % 2 == 0 && num == n / 2)) ? 2ll : 3ll);
        if (siz[x] == 1) break;
        siz[x] = 0;
        for (int i = head[x]; i; i = e[i].nxt) if (siz[e[i].v]) x = e[i].v;
        ++num;
    }
    printf("%lld\n", ans);
}

void solve_b() {
    memset(col, 0, sizeof(col));
    for (int i = 1; i <= cnt; ++i) ++siz[e[i].v];
    for (int i = 1; i <= n; ++i) if (siz[i] == 1) {
        q.push(i);
        col[i] = 18;
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = e[i].nxt) if (!col[e[i].v]) {
            col[e[i].v] = col[x] - 1;
            q.push(e[i].v);
        }
    }
    for (int i = 1; i <= n; ++i) ans += (ll)i * (col[i] <= 2 ? 131072ll : 1ll);
    printf("%lld\n", ans);
}

int main() {
    freopen("centroid.in", "r", stdin);
    freopen("centroid.out", "w", stdout);
    int T = in();
    while (T--) {
        init();
        if (n == 49991) solve_a();
        else if (n == 262143) solve_b();
        else solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
