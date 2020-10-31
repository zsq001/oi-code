#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

#define ll long long

using namespace std;

ll n, ans = 1e15 + 7;

ll js(ll a, ll b, ll c)
{
	ll ret = 0;
	ret = 2 * a * b + 2 * a * c + 2 * b * c;
	return ret;
}

int main() {
	freopen("box.in", "r", stdin);
	freopen("box.out", "w", stdout);
	scanf("%lld", &n);
	for(ll i = 1; i * i * i <= n; i++) {
		if(n % i != 0) continue;
		if(js(i, sqrt(n / i), sqrt(n / i)) > ans) continue;
		for(ll j = 1; j * j <= n / i; j++) {
			if((n / i) % j != 0) continue;
			ans = min(ans, js(i, j, (n / i) / j));
		}
	}
	printf("%lld", ans);
}
