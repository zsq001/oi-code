#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef double db;
const int MAXN = 100050;
typedef long long ll;
using namespace std;
struct node {
	ll x, y;
}a[MAXN];
ll n;
db ans1, ans2;
bool cmp(node a, node b) { return a.x > b.x; }
db solve() {
	ll x = 1ll * 0.5 * a[1].x * a[1].y * a[1].y, vt = 1ll * a[1].x * a[1].y;
	for(int i = 2; i <= n; i++) {
		x += 1.0 * 1ll * vt * a[i].y + 0.5 * a[i].x * a[i].y * a[i].y;
		vt += 1.0 * 1ll * a[i].x * a[i].y;
	}
	return x;
}
int main() {
	freopen("physics.in", "r", stdin);
	freopen("physics.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d %d", &a[i].x, &a[i].y);
	ans1 = solve();
	sort(a + 1, a + n + 1, cmp);
	ans2 = solve();
	printf("%.1lf\n", ans2 - ans1);
	return 0;
}
