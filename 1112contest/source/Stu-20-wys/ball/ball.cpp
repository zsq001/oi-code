#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long ans;
int n;

long long poww(long long a, long long b) {
	long long ret = 1;
	while(b) {
		if(b & 1) {
			ret *= a;
		}
		a = a * a;
		b /= 2;
	}
	return ret;
}

int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	scanf("%d\n", &n);
	for(long long i = 1; i <= n; i++) {
		char t;
		scanf("%c", &t);
		if(t == 'B')
			ans += poww(2, i - 1);
	}
	printf("%lld", ans);
	return 0;
}
