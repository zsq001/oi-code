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
unsigned long long lin() {
    unsigned long long x = 0; char c = getchar(); bool f = 0;
    while (c < '0' || c > '9')
        f |= c == '-', c = getchar();
    while (c >= '0' && c <= '9')
        x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
    return f ? -x : x;
}
template<typename T>void chk_min(T &_, T __) { _ = _ < __ ? _ : __; }
template<typename T>void chk_max(T &_, T __) { _ = _ > __ ? _ : __; }

int n;
unsigned long long k;

int main() {
    //freopen("in", "r", stdin);
    freopen("code.in", "r", stdin);
    freopen("code.out", "w", stdout);
    n = in(), k = lin();
    for (int i = n - 1, cur = 1; i >= 0; cur = (~(k >> i) & 1), --i) {
        if (cur) {
            printf("%llu", (k >> i) & 1ull);
        } else {
            printf("%llu", ~(k >> i) & 1ull);
        }
    }
    puts("");
    return 0;
}
