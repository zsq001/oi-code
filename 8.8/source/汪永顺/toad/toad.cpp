#include <cstdio>
#include <algorithm>
#include <cstring>
typedef int int_;
#define int long long

using namespace std;

int n, m, xx, yy, x, y, l, ans;

inline void exgcd(int a, int b, int &x, int &y)
{
	if(b == 0) 
	{
		x = 1, y = 0;
		return ;
	}
	exgcd(b, a % b, y, x);
	y -= (a / b) * x;
}

inline int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int_ main() {
	freopen("toad.in", "r", stdin);
	freopen("toad.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &xx, &yy, &m, &n, &l);
	int C = xx - yy, B = n - m;
	if(B < 0)
	{
		C = -C;
		B = -B;
	}
	exgcd(B, l, x, y);
	int d = gcd(B, l); 
	if(C % d != 0) printf("Impossible");
	else printf("%lld", ((x * C / d) % (l / d) + (l / d)) % (l / d));
	return 0;
}
