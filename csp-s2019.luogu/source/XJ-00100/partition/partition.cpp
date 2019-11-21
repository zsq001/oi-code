#include <bits/stdc++.h>
const int MAXN = 500050;
typedef int intt;
#define int long long
using namespace std;
int i, n, tp, num, ans, v[MAXN], a[MAXN], sum[MAXN];
intt main() {
	freopen("partition.in", "r", stdin);
	freopen("partition.out", "w", stdout);
	cin >> n >> tp;
	for(i = 1; i <= n; i++)
		cin >> a[i];
	for(i = 1; i <= n; i++) {
		if(a[i + 1] < a[i] || a[i] < v[num]) {
			if(i == n) {
				v[++num] = a[i];
				continue;
			}
			int lastone = v[num];
			int pos = i + 2, res = a[i] + a[i + 1];
			while(res > a[pos] && pos <= n) {
				res += a[pos];
				pos++;
			}
			if(res - v[num] > a[i] - v[num] && a[i] >= v[num] && num != 0) {
				v[++num] = a[i];
			}
			else {
				v[++num] = res;
				i = pos - 1;
			}
		}
		else
			v[++num] = a[i];
	}
	if(v[num] < v[num - 1]) {
		v[num - 1] += v[num];
		num--;
	}
	//for(int i = 1; i <= num; i++)
	//	cout << v[i] << " ";
	for(int i = 1; i <= num; i++)
		ans += 1ll * v[i] * v[i];
	cout << ans << endl;
	return 0;
}
/*
10 0
5 6 7 7 4 6 2 13 19 9
*/
