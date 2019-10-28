#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
const int MAXN = 1000050;
const int INF = 1 << 30;
typedef long long ll;
using namespace std;
ll n, m, p, q, l, r, cnt = 0, minl = INF, maxr = -INF, f[MAXN];
bool vis[MAXN];
ll get_max(ll a, ll b) { return a > b ? a : b; }
ll get_min(ll a, ll b) { return a < b ? a : b; }
int main() {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	cin >> n >> m >> p >> q;
	for(int i = m; i >= 1; i--) {
		l = ((ll)i * p + q) % n + 1;
		r = ((ll)i * q + p) % n + 1;
		if(vis[l])
			break;
		vis[l] = true;
		if(l > r)
			swap(l, r);
		if(l >= minl && r <= maxr)
			continue;
		minl = get_min(minl, l);
		maxr = get_max(maxr, r);
//		cout << l << " " << r << endl;
		for(int j = l; j <= r; j++)
			f[j] = get_max(f[j], i);
	}
	//cout << cnt << endl;
	for(int i = 1; i <= n; i++)
		printf("%lld\n", f[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
