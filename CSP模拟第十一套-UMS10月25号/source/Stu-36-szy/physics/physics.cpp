#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
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

const int N = 1e5 + 5, M = 1e6;

struct info {
    int a, t;
    inline bool operator < (const info &b) const {
        return this->a > b.a;
    }
} p[N];
int n;

struct INT {
    long long a[10];
    INT() {
        memset(a, 0, sizeof(a));
    }
    inline long long& operator [] (const int x) {
        return a[x];
    }
    inline INT operator + (long long b) {
        INT ret;
        for (int i = 9; i >= 0; --i)
            ret[i] = a[i];
        ret[0] += b;
        for (int i = 0; i < 9; ++i)
            if (ret[i] >= M)
                ret[i + 1] += ret[i] / M , ret[i] %= M;
        return ret;
    }
    inline INT operator + (INT b) {
        INT ret;
        for (int i = 9; i >= 0; --i)
            ret[i] = a[i] + b[i];
        for (int i = 0; i < 9; ++i)
            if (ret[i] >= M)
                ret[i + 1] += ret[i] / M , ret[i] %= M;
        return ret;
    }
    inline INT operator * (long long b) {
        INT ret;
        for (int i = 9; i >= 0; --i)
            ret[i] = a[i] * b;
        for (int i = 0; i < 9; ++i)
            if (ret[i] >= M)
                ret[i + 1] += ret[i] / M , ret[i] %= M;
        return ret;
    }
    inline INT operator - (INT b) {
        INT ret;
        for (int i = 9; i >= 0; --i)
            ret[i] = a[i] - b[i];
        for (int i = 0; i < 9; ++i)
            if (ret[i] < 0)
                ret[i + 1] += (ret[i] / M - 1) , ret[i] = (ret[i] % M + M) % M;
        return ret;
    }
    inline void operator += (long long b) {
        *this = *this + b;
    }
    inline void operator += (INT b) {
        *this = *this + b;
    }
    inline void operator -= (INT b) {
        *this = *this - b;
    }
    void half() {
        int i;
        for (i = 9; i >= 0; --i)
            if (a[i] > 0)
                break;
        if (!~i)
            return (void)(puts("0.0"));
        int rest = a[i] & 1;
        printf("%lld", a[i] >> 1);
        for (--i ; i >= 0; --i) {
            printf("%06lld", (a[i] + rest * M) >> 1);
            rest = a[i] & 1;
        }
        puts(rest ? ".5" : ".0");
    }
    void out() {
        int i;
        for (i = 9; i >= 0; --i)
            if (a[i] > 0)
                break;
        if (!~i)
            return (void)(puts("0.0"));
        printf("%lld", a[i]);
        for (--i ; i >= 0; --i)
            printf("%06lld", a[i]);
        puts("");
    }
} ;

int main() {
    //freopen("in", "r", stdin);
    freopen("physics.in", "r", stdin);
    freopen("physics.out", "w", stdout);
    n = in();
    for (int i = 1; i <= n; ++i)
        p[i] = (info){in(), in()};

    INT t1, t2, v_1, v_2;
    for (int i = 1; i <= n; ++i) {
        t1 += v_1 * (p[i].t + p[i].t) + 1ll * p[i].a * p[i].t * p[i].t;
        v_1 += 1ll * p[i].a * p[i].t;
    }

    std::sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; ++i) {
        t2 += v_2 * (p[i].t + p[i].t) + 1ll * p[i].a * p[i].t * p[i].t;
        v_2 += 1ll * p[i].a * p[i].t;
    }

    //t1.out(), t2.out();
    (t2 - t1).half();
    return 0;
}
