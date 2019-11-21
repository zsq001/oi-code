#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod = 998244353;
int a[105][2005], n, m, ans = 0, sumc[2005];
void dfs(int step, int now, int k, int sum){
	if(step == k + 1){
		ans = (ans + sum) % mod;
		return ;
	}
	if (n - now > k - step) dfs(step, now + 1, k, sum);
	for (int i = 1;i <= m;i++){
		sumc[i]++;
		if (sumc[i] <= k / 2) dfs(step + 1, now + 1, k, sum * a[now][i] % mod);
		sumc[i]--;
	}
}
int main(){
	freopen("meal.in", "r", stdin);
	freopen("meal.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1;i <= n;i++) for (int j = 1;j <= m;j++) scanf("%d", &a[i][j]);
	for (int i = 2;i <= n;i++) memset(sumc, 0, sizeof(sumc)), dfs(1, 1, i, 1);
	printf("%d", ans % mod);
	return 0;
}
