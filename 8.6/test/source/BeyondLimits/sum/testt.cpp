#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
long long f[1000000001], n, a, b, c, d, e, ans;
int main() {
	f[1] = f[2] = 1;
	for(int i = 3; i <= 1000000000; i++)
		f[i] = (f[i - 1] + f[i - 2]) % mod;
	cout << (f[1000000000]) % mod << endl;
	while(true) {
		cin >> a >> b >> c >> d >> e;
		cout << ((f[a] + f[b]) % mod + (f[c] + f[d]) % mod + f[e]) % mod << endl;
	}
}
