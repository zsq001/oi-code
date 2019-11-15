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

const int mod = 1e9 + 7;

inline void add(int &_, int __) {
    _ += __;
    if (_ >= mod)
        _ -= mod;
}

int n;

struct matrix {
    int a[5][5];
    matrix(int _ = 0) {
        memset(a, 0, sizeof(a));
        if (_)
            for (int i = 0; i < 2; ++i)
                a[i][i] = _;
    }
    inline int* operator [] (const int _) {
        return a[_];
    }
    matrix operator * (matrix b) const {
        matrix ret;
        for (int k = 0; k < 2; ++k)
            for (int i = 0; i < 2; ++i)
                for (int j = 0; j < 2; ++j)
                    add(ret[i][j], 1ll * a[i][k] * b[k][j] % mod);
        return ret;
    }
    matrix operator ^ (int b) const {
        matrix base = *this, ret(1);
        for (; b; b >>= 1, base = base * base)
            if (b & 1)
                ret = ret * base;
        return ret;
    }
} ;

matrix res, trans;

int main() {
    //freopen("in", "r", stdin);
    freopen("coordinate.in", "r", stdin);
    freopen("coordinate.out", "w", stdout);
    n = in();
    res[0][0] = 1, res[1][0] = 2;
    trans[0][0] = 1, trans[0][1] = 1;
    trans[1][0] = 2, trans[1][1] = 1;
    res = (trans ^ (n - 1)) * res;
    add(res[0][0], res[1][0]);
    printf("%d\n", res[0][0]);
    return 0;
}
