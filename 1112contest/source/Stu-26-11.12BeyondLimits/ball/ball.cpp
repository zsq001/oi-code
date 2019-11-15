#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
typedef long long ll;
const int MAXN = 1050;
const ll lim = 1000000000000000000;
using namespace std;
int n, p;
bool t[MAXN], flag;
ll ans;
string s;
ll qpow(ll x, ll y) {
	ll ans = 1;
	while(y) {
		if(y & 1)
			ans = 1ll * ans * x;
		x = 1ll * x * x;
		y >>= 1;
	}
	return ans;
}
int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	cin >> n >> s;
	for(int i = 0; i < (int)s.length(); i++)
		t[i + 1] = (s[i] == 'B') ? 1 : 0;
	for(int i = 1; i <= n; i++) {
		if(t[i] == 0) {
			p++;
			continue;
		}
		flag = true;
		ans += qpow(2, p);
		p++;
		if(ans >= lim) {
			cout << "-1" << "\n";
			return 0;
		}
	}
	cout << ans << "\n";
	return 0;
}
/*
11
BBBRBRBRRRR
50
BRBRBRBRBBBBRBRBRBRBRRRRBBRBRBRRBBRRBBRBRBBBRBRBRB
*/
