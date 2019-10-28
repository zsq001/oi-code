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

struct node {
    int x, y, z;
    inline bool operator < (const node &b) const {
        return this->x < b.x;
    }
} a[N];

int B, n, d, m, nn;
long long res;

struct binary_index_tree {
    int t[N << 1];
    void modify(int p, int k) { for (; p <= nn; p += (p & -p)) t[p] += k; }
    int ask(int p, int ret = 0) { for (; p; p -= (p & -p)) ret += t[p]; return ret; }
} bit;

int main() {
    //freopen("in", "r", stdin);
    freopen("minecraft.in", "r", stdin);
    freopen("minecraft.out", "w", stdout);
    B = in(), n = in(), d = in(), m = in();
    if (d >= m) {
        printf("%lld\n", n * (n - 1) / 2);
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        a[i].x = in();
        a[i].y = B > 1 ? in() : 0;
        a[i].z = B > 2 ? in() : 0;
    }
    if (B == 1) {
        std::sort(a + 1, a + 1 + n);
        int pos = 1;
        for (int i = 1; i <= n; ++i) {
            while (a[i].x - a[pos].x > d)
                ++pos;
            res += i - pos;
        }
    } else if (B == 2) {
        for (int i = 1; i <= n; ++i)
            a[i] = (node){a[i].x - a[i].y, a[i].x + a[i].y}, chk_max(nn, a[i].y);
        std::sort(a + 1, a + 1 + n);
        int pos = 1;
        for (int i = 1; i <= n; ++i) {
            while (a[i].x - a[pos].x > d)
                bit.modify(a[pos].y, -1), ++pos;
            res += bit.ask(std::min(nn, a[i].y + d)) - bit.ask(std::max(0, a[i].y - d - 1));
            bit.modify(a[i].y, 1);
        }
    } else {
        if (d <= m / 2) {
            std::sort(a + 1, a + 1 + n);
        } else {
        }
    }
    printf("%lld\n", res);
    return 0;
}
