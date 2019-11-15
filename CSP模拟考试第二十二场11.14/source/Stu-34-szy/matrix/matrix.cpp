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
template<typename T>
void out(T _) {
    if (_ < 0)
        putchar('-'), _ = -_;
    if (_ < 9)
        return (void)(putchar(_ ^ 48));
    out(_ / 10);
    putchar((_ % 10) ^ 48);
}
template<typename T>
void out_ln(T _) {
    out(_), puts("");
}
template<typename T>inline void chk_min(T &_, T __) { _ = _ < __ ? _ : __; }
template<typename T>inline void chk_max(T &_, T __) { _ = _ > __ ? _ : __; }

const int N = 1e3 + 5;

int n, m, q, mp[N][N];
std::pair<int, int> x[N], y[N];

int main() {
    //freopen("in", "r", stdin);
    freopen("matrix.in", "r", stdin);
    freopen("matrix.out", "w", stdout);
    n = in(), m = in(), q = in();
    for (int i = 1; i <= q; ++i) {
        int typ = in(), a = in(), w = in();
        if (typ == 1) {
            x[a] = std::make_pair(w, i);
        } else {
            y[a] = std::make_pair(w, i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            printf("%d ", x[i].second > y[j].second ? x[i].first : y[j].first);
        puts("");
    }
    return 0;
}
