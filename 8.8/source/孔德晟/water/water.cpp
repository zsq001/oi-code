#include <cstdio>
#include <algorithm>
typedef int int_;
#define int long long
const int mod=100000007;
using namespace std;

int gcd(int a,int b) {
	return b?gcd(b,a%b):a;
}
int_ main() {
	int n;
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%lld",&n);
	if (n <= 2) {
		printf("%lld",n);
		return 0;
	}
	int a = n * (n-1),b = (n-1) * (n-2);
	int den = gcd(a,b);
	int ans = a * b / den;
	for (int i = 1; i <= n; i++) {
		if (ans % i != 0) ans = ans * i % mod;
	}
	printf("%lld",ans%mod);
	return 0;
}
