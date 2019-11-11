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

const int N = 1e7 + 5;

int m, czy;
int l, r, q[N], f[N];
int qwq[N + N], *nxt = qwq + 2, *lst = qwq + 2 + N + 1;
int res;

int main() {
    //freopen("in", "r", stdin);
    freopen("tea.in", "r", stdin);
    freopen("tea.out", "w", stdout);
    m = in(), czy = in();
    for (int i = -1; i < 10000000; ++i)
        nxt[i] = i + 1, lst[i + 1] = i;
    nxt[10000000] = -1, lst[-1] = 10000000;
    while (m--) {
        int typ = in(), x, tmp;
        if (typ == 1) {
            x = in() ^ (res * czy);
            nxt[lst[x]] = nxt[x];
            lst[nxt[x]] = lst[x];
        } else if (typ == 2) {
            tmp = 0;
            x = in() ^ (res * czy);
            for (; l < r && q[r - 1] > x; --r)
                tmp += f[r - 1];
            q[r++] = x;
            f[r - 1] = tmp + 1;
        } else if (typ == 3) {
            --f[l];
            if (!f[l])
                ++l;
        } else {
            res = nxt[-1];
            if (l < r)
                chk_min(res, q[l]);
            printf("%d\n", res);
        }
    }
    return 0;
}
