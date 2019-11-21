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

const int N = 4e7 + 5;

int n, typ, nxt[N];
unsigned long long a[N];

unsigned long long work() {
}

int main() {
    //freopen("partition2.in", "r", stdin);
    freopen("partition.in", "r", stdin);
    freopen("partition.out", "w", stdout);
    n = in(), typ = in();
    for (int i = 1; i <= n; ++i)
        a[i] = (unsigned long long)in(), nxt[i] = i + 1;
    if (n <= 10) {
        int st = (1 << (n - 1)), now, res = 0;
        for (int i = 1; i <= n; ++i)
            a[i] += a[i - 1];
        res = a[n] * a[n];
        for (int i = 1, tmp, min; i < st; ++i) {
            now = 0, tmp = 0, min = -1;
            for (int j = 1; j < n; ++j) {
                if ((1 << (j - 1)) & i) {
                    if (!~min) {
                        min = a[j] - a[tmp];
                    } else if (a[j] - a[tmp] < min) {
                        now = a[n] * a[n];
                        break;
                    } else {
                        min = a[j] - a[tmp];
                    }
                    now += (a[j] - a[tmp]) * (a[j] - a[tmp]);
                    tmp = j;
                }
            }
            if (a[n] - a[tmp] < min) {
                now = a[n] * a[n];
            } else {
                now += (a[n] - a[tmp]) * (a[n] - a[tmp]);
            }
            chk_min(res, now);
        }
        printf("%d\n", res);
        return 0;
    } else {
        nxt[n] = 0;
        printf("%llu\n", work());
    }
    return 0;
}
