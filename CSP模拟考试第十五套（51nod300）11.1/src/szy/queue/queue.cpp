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

const int N = 5e4 + 5;

int n, max;
int f[N];

int main() {
    //freopen("in", "r", stdin);
    freopen("queue.in", "r", stdin);
    freopen("queue.out", "w", stdout);
    n = in();
    for (int i = 1, k; i <= n; ++i) {
        k = in();
        f[k] = f[k - 1] + 1;
        chk_max(max, f[k]);
    }
    printf("%d\n", n - max);
    return 0;
}
