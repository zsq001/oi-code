#include <cstdio>

typedef unsigned long long ull;
ull bi[80];

void print(int n, ull k) {
    if (n == 1) {
        printf("%llu", k);
    } else {
        if (k < bi[n - 1]) {
            printf("0");
            print(n - 1, k);
        }
        else {
            printf("1");
            if (n == 64) print(n - 1, bi[64] - k);
            else print(n - 1, bi[n] - k - 1);
        }
    }
}

int main() {
    freopen("code.in", "r", stdin);
    freopen("code.out", "w", stdout);
    ull n, k;
    bi[0] = 1;
    scanf("%llu %llu", &n, &k);
    for (int i = 1; i <= n && i < 64; ++i) bi[i] = bi[i - 1] << 1;
    if (n == 64) bi[64] = bi[63] - 1 + bi[63];
    print(n, k);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
