#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
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

int V;

long long work() {
    long long ret = 4ll * V + 2ll;
    for (int i = 1, k; i <= 1000; ++i)
        if (V % i == 0)
            for (int j = 1; j <= 1000; ++j)
                if ((V / i) % j == 0) {
                    k = V / i / j;
                    chk_min(ret, 2ll * i * j + 2ll * i * k + 2ll * j * k);
                }
    return ret;
}

int main() {
    //freopen("in", "r", stdin);
    freopen("box.in", "r", stdin);
    freopen("box.out", "w", stdout);
    V = in();
    printf("%lld\n", work());
    return 0;
}
