#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
const int INF = 1 << 30;
const int MAXN = 1000050;
typedef int intt;
#define int long long 
using namespace std;
int n, m, k, a[MAXN], f[MAXN];
int read() {
	int x = 0;
	bool sign = false;
	char alpha = 0;
	while(!isdigit(alpha)) {
		sign |= alpha == '-';
		alpha = getchar();
	}
	while(isdigit(alpha)) {
		x = (x << 1) + (x << 3) + (alpha ^ 48);
		alpha = getchar();
	}
	return sign ? -x : x;
}
void dp() {
	for(int i = 2; i <= n; i++) {
		for(int j = k; j >= 1; j--) {
			if(i - j >= 0)
				a[i] >= a[i - j] ? f[i] = min(f[i], f[i - j] + 1) : f[i] = min(f[i], f[i - j]);
		}
	}
}
void init() {
	f[1] = 0;
	for(int i = 2; i <= n; i++)
		f[i] = INF;
}
intt main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i++)
		a[i] = read();
	m = read();
	while(m--) {
		init();
		k = read();
		dp();
		printf("%lld\n", f[n]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
