#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
typedef long long ll;
const int mod = 19260817;
using namespace std;
ll n, a, b, lasta, lastb;
int main() {
	freopen("pcr.in", "r", stdin);
	freopen("pcr.out", "w", stdout);
	scanf("%d", &n);
	lasta = 2;
	for(int i = 3; i <= n; i++) {
		a = (ll)(i * 2) % mod - 2;
		b = (lasta + (ll)(lastb * 2) % mod) % mod;
		lasta = a;
		lastb = b;
	}
	printf("%d\n", lastb);
	return 0;
}
