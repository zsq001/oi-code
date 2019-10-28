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
template<typename T>inline void chk_min(T &_, T __) { _ = _ < __ ? _ : __;}
template<typename T>inline void chk_max(T &_, T __) { _ = _ > __ ? _ : __;}

const int N = 1e5 + 5;

int n, h, b, e;

int main() {
    //freopen("in", "r", stdin);
    freopen("coffee.in", "r", stdin);
    freopen("coffee.out", "w", stdout);
    while (~scanf("%d %d %d %d", &n, &h, &b, &e)) {
        static int c[N], cnt[N], q[N];
        for (int i = 1; i <= n; ++i)
            c[i] = in();
        int l = 0, r = 0;
        for (int i = 1; i <= n; ++i) {
            cnt[i] = 0;
            while (l < r && i - q[l] > h)
                ++l;
            while (l < r && c[i] <= c[q[r - 1]])
                --r;
            q[r++] = i;
            ++cnt[q[l]];
        }
        for (int i = b; i <= e; ++i)
            printf("%d ", cnt[i]);
        puts("");
    }
    return 0;
}
