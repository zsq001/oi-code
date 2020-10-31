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

const int N = 55;

int n;
char s[N];
long long res;

int main() {
    //freopen("in", "r", stdin);
    freopen("ball.in", "r", stdin);
    freopen("ball.out", "w", stdout);
    n = in();
    scanf(" %s", s + 1);
    for (int i = 1; i <= n; ++i)
        if (s[i] == 'B')
            res += 1ll << (i - 1);
    printf("%lld\n", res);
    return 0;
}
