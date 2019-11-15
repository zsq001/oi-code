#include <bits/stdc++.h>

int main() {
    freopen("in", "w", stdout);
    srand(time(0) + 40051326);
    int n = 200;
    printf("%d\n", n);
    for (int i = 2; i <= n; ++i)
        printf("%d %d\n", rand() % (i - 1) + 1, i);
    int m = 200;
    printf("%d\n", m);
    for (int i = 1; i <= m; ++i)
        printf("%d %d\n", rand() % n + 1, rand() % n + 1);
    return 0;
}
