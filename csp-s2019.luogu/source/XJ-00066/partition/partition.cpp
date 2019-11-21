#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

long long a[5050], n, type, anss[5050];

int main() {
	freopen("partition.in", "r", stdin);
	freopen("partition.out", "w", stdout);
	scanf("%lld%lld", &n, &type);
	for(long long i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	a[n + 1] = 1e9 + 7;
	anss[1] = a[1];
	long long cnt = 1, last = a[1];
	for(long long i = 2; i <= n; i++) {
		if(a[i] >= last) {
			anss[++cnt] = a[i];
			last = a[i];
		}
		else {
			if(a[i + 1] > last + a[i]) {
				anss[cnt] += a[i];
				last = anss[cnt];
			}
			else {
				anss[++cnt] = a[i] + a[i + 1];
				last = anss[cnt];
				i++;
			}
		}
	}
	long long ans = 0;
	for(long long i = 1; i <= cnt; i++) {
		ans += anss[i] * anss[i];
	}
	printf("%lld", ans);
	return 0;
}
