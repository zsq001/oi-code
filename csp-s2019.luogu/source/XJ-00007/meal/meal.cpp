#include <cstdio>
#include <cstring>

typedef long long ll;
const int maxn = 41;
const int maxm = 4;
const ll mod = 998244353;
int n, m;
ll totans, a[maxn][maxm];

int in(int r = 0) {
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') r = (r << 1) + (r << 3) + (c ^ '0'), c = getchar();
    return r;
}

void solve2(int cur = 1) {
    ll f[2][maxn][maxn], ans = 0;
    memset(f, 0, sizeof(f));
    f[0][0][0] = 1;
    for (int i = 1; i <= n; ++i, cur ^= 1) {
        for (int x = 0; x < i; ++x) for (int y = 0; y < i && x + y < i; ++y) f[cur][x][y] = f[cur ^ 1][x][y];
        for (int x = 0; x < i; ++x) for (int y = 0; y < i && x + y < i; ++y) {
            (f[cur][x + 1][y] += f[cur ^ 1][x][y] * a[i][1] % mod) %= mod;
            (f[cur][x][y + 1] += f[cur ^ 1][x][y] * a[i][2] % mod) %= mod;
        }
    }
    cur ^= 1;
    for (int i = 0; i <= n; ++i) for (int j = 0; j <= n && i + j <= n; ++j) {
        int mx = (i + j) / 2;
        if (i + j > 1 && i <= mx && j <= mx) (ans += f[cur][i][j]) %= mod;
    }
    printf("%lld\n", ans);
}

void solve3(int cur = 1) {
    ll f[2][maxn][maxn][maxn], ans = 0;
    memset(f, 0, sizeof(f));
    f[0][0][0][0] = 1;
    for (int i = 1; i <= n; ++i, cur ^= 1) {
        for (int x = 0; x < i; ++x) for (int y = 0; y < i && x + y < i; ++y) for (int z = 0; z < i && x + y + z < i; ++z) f[cur][x][y][z] = f[cur ^ 1][x][y][z];
        for (int x = 0; x < i; ++x) for (int y = 0; y < i && x + y < i; ++y) for (int z = 0; z < i && x + y + z < i; ++z) {
            (f[cur][x + 1][y][z] += f[cur ^ 1][x][y][z] * a[i][1] % mod) %= mod;
            (f[cur][x][y + 1][z] += f[cur ^ 1][x][y][z] * a[i][2] % mod) %= mod;
            (f[cur][x][y][z + 1] += f[cur ^ 1][x][y][z] * a[i][3] % mod) %= mod;
        }
    }
    cur ^= 1;
    for (int x = 0; x <= n; ++x) for (int y = 0; y <= n && x + y <= n; ++y) for (int z = 0; z <= n && x + y + z <= n; ++z) {
        int mx = (x + y + z) / 2;
        if (x + y + z > 1 && x <= mx && y <= mx && z <= mx) (ans += f[cur][x][y][z]) %= mod;
    }
    printf("%lld\n", ans);
}

int main() {
    freopen("meal.in", "r", stdin);
    freopen("meal.out", "w", stdout);
    n = in(), m = in();
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) a[i][j] = in();
    if (m == 2) solve2();
    else if (m == 3) solve3();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
