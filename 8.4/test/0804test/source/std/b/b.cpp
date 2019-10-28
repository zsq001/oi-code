#include<cstdio>
#include<iostream>

using namespace std;

const int N = 1000005;
int n, m, p, q, k, i, j, x, y, f[N], a[N];
int get(int x)
{
    if(f[x] == x) return x;
    else return f[x] = get(f[x]);
}
int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    scanf("%d%d%d%d", &n, &m, &p, &q);
    for(i = 1; i <= n + 1; i++) f[i] = i;
    k = 0;
    for(i = m; i >= 1; i--)
    {
        x = (i * p % n + q) % n + 1;
        y = (i * q % n + p) % n + 1;

        if(x > y) swap(x, y);
        
        for(j = get(x); j <= y; j = get(j))
        {
            a[j] = i;
            f[j] = j + 1;
            k++;
            if(k == n) break;
        }
    }
    for(i = 1; i <= n; i++) printf("%d\n", a[i]);
    return 0;
}
