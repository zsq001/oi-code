#include <bits/stdc++.h>
const int mod = 1e9 + 7;
typedef int intt;
#define int long long
using namespace std;
struct mat {
	int m[20][20];
};
mat c, d, e;
mat mul(mat x, mat y) {
	mat z;
	for(int i = 1; i <= 2; i++) {
		for(int j = 1; j <= 2; j++)
			z.m[i][j] = 0;
	}
	for(int i = 1; i <= 2; i++) {
		for(int j = 1; j <= 2; j++) {
			for(int k = 1; k <= 2; k++) {
				z.m[i][j] = (z.m[i][j] % mod + (int)((x.m[i][k] % mod) * (y.m[k][j] % mod))) % mod;
			}
		}
	}
	return z;
}
mat qpow(mat x, int y) {
	mat ans = c;
	while(y) {
		if(y & 1)
			ans = mul(ans, x);
		x = mul(x, x);
		y >>= 1;
	}
	return ans;
}
int fib(int x) {
	if(x == 1 || x == 2)
		return 1;
	for(int i = 1; i <= 2; i++) {
		for(int j = 1; j <= 2; j++)
			c.m[i][j] = d.m[i][j] = e.m[i][j] = 0;
	}
	c.m[1][1] = c.m[2][2] = d.m[1][1] = d.m[1][2] = d.m[2][1] = 1;
	e = qpow(d, x - 2);
	return (e.m[1][1] + e.m[1][2]) % mod;
}
intt main() {
	cout << fib(1000000000) << endl;
}
