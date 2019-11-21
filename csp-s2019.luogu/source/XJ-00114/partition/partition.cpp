#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
int a[40000005], n;
signed main(){
	freopen("partition.in", "r", stdin);
	freopen("partition.out", "w", stdout);
	int t, ans = 0; scanf("%lld%lld", &n, &t);
	for (int i = 1;i <= n;i++) scanf("%lld", &a[i]);
	for (int i = 1;i < n;i++){
		if (a[i] == -1) continue;
		if (a[i] > a[i + 1]){
			if (i == n - 1) a[i + 1] += a[i], a[i] = -1;
			else if (a[i] + a[i + 1] > a[i + 2]) a[i + 2] += a[i + 1], a[i + 1] = -1;
			else a[i + 1] += a[i], a[i] = -1;
		}
	}
	for (int i = 1;i <= n;i++) if (a[i] != -1) ans += a[i] * a[i];
	printf("%lld", ans);
	return 0;
}
