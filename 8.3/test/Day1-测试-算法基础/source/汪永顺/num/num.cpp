#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <string>

using namespace std;

long long ans[10500100], cnt, n, m, k;

int main() {
	freopen("num.in", "r", stdin);
	freopen("num.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			ans[++cnt] = i * j;
		}
	}
	sort(ans + 1, ans + 1 + cnt);
	printf("%lld", ans[k]);
	return 0;
}
