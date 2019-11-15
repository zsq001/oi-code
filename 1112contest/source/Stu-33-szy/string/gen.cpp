#include <bits/stdc++.h>

int main() {
    freopen("in", "w", stdout);
    srand(time(0) + 40051326);
    int T = 10;
    printf("%d\n", T);
    while (T--) {
        int n = 100;
        printf("%d\n", n);
        for (int i = 1; i <= n; ++i)
            printf("%c", rand() % 4 + 97);
        puts("");
    }
    return 0;
}
