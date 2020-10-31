#include <cstdio>
#include <cstring>
#include <algorithm>

const long long mod = 1e9 + 7;

using namespace std;

long long n;

long long pow(long long a, long long b) {
	long long ret = 1;
	while(b != 0) {
		if(b & 1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret % mod;
}

int main() {
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w" , stdout);
	scanf("%lld", &n);
	printf("%lld", ((pow(3, n + 1)) / 2) % mod);
	return 0;
}
