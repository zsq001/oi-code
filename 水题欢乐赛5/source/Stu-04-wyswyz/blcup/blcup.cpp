#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
typedef int int_;
#define int long long

//6 * C(n, 3n) - 6 * C(n, 2n);

const int p = 19260817;

using namespace std;

int n, m, t = 1, ans;

int pow(int a, int b)
{
	int ret = 1;
	while(b)
	{
		if(b & 1) ret = ret * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return ret;
}

int ni(int x)
{
	return pow(x, p - 2);
}

int work(int n, int m)
{
	int x = 1, y = 1;
	for(int i = n; i >= n - m + 1; i--) x = x * i % p;
	for(int i = 1; i <= m; i++) y = y * i % p;
	return x * ni(y) % p;
}

int_ main() {
	freopen("blcup.in", "r", stdin);
	freopen("blcup.out", "w", stdout);
	scanf("%lld", &n);
	n *= 3;
	m = n / 3;
	ans = (6 * work(n, m) % p - 6 * (work(2 * m, m)) % p + p) % p;
	printf("%lld", ans);
	return 0;
}
