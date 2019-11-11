#include <bits/stdc++.h>

int main() {
    freopen("in", "w", stdout);
    srand(time(0) + 40051326);
    int T = 10;
    printf("%d\n", T);
    while (T--) {
        int n = 20, k = rand() % (n / 2) + 1 + (n / 2);
        printf("%d %d\n", n, k);
        for (int i = 2; i <= n; ++i)
            printf("%d\n", rand() % (i - 1) + 1);
    }
    return 0;
}
