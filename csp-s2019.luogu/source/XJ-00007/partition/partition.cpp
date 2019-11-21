#include <cstdio>
#include <algorithm>

typedef long long ll;
const int maxn = 5005;
const ll inf = 1ll << 60;
ll s[maxn], f[maxn][maxn], ans = inf;

int in(int r = 0) {
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') r = (r << 1) + (r << 3) + (c ^ '0'), c = getchar();
    return r;
}

int main() {
    freopen("partition.in", "r", stdin);
    freopen("partition.out", "w", stdout);
    int n = in(), type = in();
    for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + in();
    f[1][1] = s[1] * s[1];
    for (int i = 2; i <= n; ++i) for (int j = i; j >= 1; --j) {
        f[i][j] = inf;
        for (int k = j - 1; k >= 1; --k)
            if (s[i] - s[j - 1] >= s[j - 1] - s[k - 1]) f[i][j] = std::min(f[i][j], f[j - 1][k]);
        if (j == 1) f[i][j] = 0;
        f[i][j] += (s[i] - s[j - 1]) * (s[i] - s[j - 1]);
    }
    for (int i = 1; i <= n; ++i) ans = std::min(ans, f[n][i]);
    printf("%lld\n", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
