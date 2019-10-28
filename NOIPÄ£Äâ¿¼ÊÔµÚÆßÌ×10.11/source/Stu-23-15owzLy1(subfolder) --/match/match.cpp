#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
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

struct node {
    int l, r;
    inline bool operator < (const node &b) const {
        return this-> r > b.r;
    }
} a[N];

std::priority_queue <node> q;

int n, m, x, y, b[N];
int res;

int main() {
    //freopen("in", "r", stdin);
    freopen("match.in", "r", stdin);
    freopen("match.out", "w", stdout);
    n = in(), m = in(), x = in(), y = in();
    for (int i = 1, tmp; i <= n; ++i) {
        tmp = in();
        a[i] = (node){tmp - x, tmp + y};
    }
    for (int i = 1; i <= m; ++i)
        b[i] = in();
    for (int i = 1, pos = 1; i <= m; ++i) {
        while (pos <= n && a[pos].l <= b[i])
            q.push(a[pos++]);
        while (!q.empty()) {
            if (q.top().r >= b[i]) {
                ++res;
                q.pop();
                break;
            }
            q.pop();
        }
    }
    printf("%d\n", res);
    return 0;
}
