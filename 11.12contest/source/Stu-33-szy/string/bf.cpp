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

const int N = 2e5 + 5;

int n;
char s[N];

bool chk(const int len) {
    bool used = 0;
    for (int i = len + 1, j = 1; i <= n; ++i, j = j % len + 1) {
        if (s[i] != s[j]) {
            if (used)
                return 0;
            --j;
            used = 1;
        }
    }
    return 1;
}

int main() {
    freopen("in", "r", stdin);
    freopen("bf.out", "w", stdout);
    int T = in();
    while (T--) {
        n = in();
        scanf(" %s", s + 1);
        int res;
        for (res = 1; res < n; ++res)
            if (chk(res))
                break;
        printf("%d\n", res);
    }
    return 0;
}
