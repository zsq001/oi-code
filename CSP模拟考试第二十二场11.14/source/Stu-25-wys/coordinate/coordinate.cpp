#include <cstdio>
#include <cstring>
#include <algorithm>

const int mod = 1e9 + 7;

using namespace std;

int f[1000006], n;

int main() {
	freopen("coordinate.in", "r", stdin);
	freopen("coordinate.out", "w", stdout);
	scanf("%d", &n);
	f[1] = 3; f[2] = 7; f[3] = 17;
	for(int i = 4; i <= n; i++) {
		f[i] = (f[i - 2] * 3 + (f[i - 1] - f[i - 2]) * 2) % mod;
	}
	printf("%d", f[n]);
	return 0;
}
