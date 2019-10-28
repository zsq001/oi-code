#include <cstdio>
#include <algorithm>

#define MAXN 1111111
#define INF 2047483647

int n, m, step, l, r;
int f[MAXN], a[MAXN];
int d[MAXN];

inline void get_int(int &x, int y = 1) {
	x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') y = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); }
	x *= y;
}

int main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    get_int(n);
    for(int i = 1; i <= n; i++) get_int(a[i]);
    get_int(m);
    while(m--) {
        l = 1; r = 1;
        get_int(step);
        f[1] = 0;
        d[1] = 1;
        for(int i = 2; i <= n; i++) {
            while(l <= r && d[l] < i - step) l++;
            f[i] = f[d[l]] + (a[d[l]] <= a[i]);
            while(l <= r && (f[d[r]] > f[i] || (f[d[r]] == f[i] && a[d[r]] <= a[i]))) r--;
            d[++r] = i;
        }
        printf("%d\n", f[n]);
    }
}
/*
9
4 6 3 6 3 7 2 6 5
2
2
5
*/
