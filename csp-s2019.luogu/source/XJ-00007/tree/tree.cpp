#include <cstdio>
#include <algorithm>
#include <queue>

const int maxn = 2005;
int n, goa, cnt, tmp_Cnt, Cnt, tp, num[maxn], col[maxn], tmp_Head[maxn], Head[maxn], head[maxn], stk[maxn], d[maxn], p[maxn];
bool vis[maxn];
struct edge {
    int u, v, nxt;
}e[maxn << 1], E[maxn << 1];
std::queue<int> q;

int in(int r = 0) {
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {
        r = (r << 1) + (r << 3) + (c ^ '0');
        c = getchar();
    }
    return r;
}

void add(int u, int v) {
    e[++cnt].u = u;
    e[cnt].v = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}

void Add(int u, int v) {
    E[++Cnt].u = u;
    E[Cnt].v = v;
    E[Cnt].nxt = Head[u];
    Head[u] = Cnt;
}

bool dfs(int x) {
    if (x == goa) return 1;
    for (int i = head[x]; i; i = e[i].nxt) {
        stk[++tp] = (i + 1) / 2;
        if (dfs(e[i].v)) return 1;
        --tp;
    }
    return 0;
}

bool dfs2(int x) {
    if (vis[x]) return 1;
    vis[x] = 1;
    for (int i = Head[x]; i; i = E[i].nxt) if (dfs2(E[i].v)) return 1;
    return 0;
}

bool cmp(int a, int b) {
    return col[a] < col[b];
}

void init() {
    n = in();
    cnt = Cnt = 0;
    for (int i = 1; i <= n; ++i) col[num[i] = in()] = i, p[i] = i, d[i] = 0, head[i] = Head[i] = 0;
    for (int i = 1; i < n; ++i) {
        int u = in(), v = in();
        add(u, v), add(u, v);
    }
}

int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int T = in();
    while (T--) {
        init();
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                goa = i;
                tp = 0;
                if (!dfs(num[i])) continue;
                if (!tp) break;
                int tmp_Cnt = Cnt;
                for (int w = 1; w < n; ++w) tmp_Head[w] = Head[w], vis[w] = 0;
                for (int w = 1; w < tp; ++w)
                    Add(stk[w], stk[w + 1]);
                if (dfs2(stk[1])) {
                    Cnt = tmp_Cnt;
                    for (int w = 1; w < n; ++w) Head[w] = tmp_Head[w];
                } else break;
            }
        }
        for (int j = 1; j <= Cnt; ++j) ++d[E[j].v];
        for (int j = 1; j < n; ++j) if (!d[j]) q.push(j);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            std::swap(col[e[x * 2].u], col[e[x * 2].v]);
            for (int j = Head[x]; j; j = E[j].nxt) {
                --d[E[j].v];
                if (!d[E[j].v]) q.push(E[j].v);
            }
        }
        std::sort(p + 1, p + 1 + n, cmp);
        for (int i = 1; i <= n; ++i) printf("%d ", p[i]);
        puts("");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
