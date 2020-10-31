#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[40000], w[65], blg[65], att[65][3], val[65];

int main() {
	freopen("budget.in", "r", stdin);
	freopen("budget.out", "w", stdout);
	int N, m;
	scanf("%d%d", &N, &m);
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &w[i], &val[i], &blg[i]);
		val[i] *= w[i];
		if(blg[i] != 0)
		{
			if(att[blg[i]][1] == 0) att[blg[i]][1] = i;
			else att[blg[i]][2] = i;
		}
	}
	for(int i = 1; i <= m; i++)
	{
		if(blg[i] != 0) continue;
		for(int k = N; k >= 0; k--)
		{
			if(k >= w[i]) dp[k] = max(dp[k], dp[k - w[i]] + val[i]);
			if(k >= w[i] + w[att[i][1]]) dp[k] = max(dp[k], dp[k - w[i] - w[att[i][1]]] + val[i] + val[att[i][1]]);
			if(k >= w[i] + w[att[i][2]]) dp[k] = max(dp[k], dp[k - w[i] - w[att[i][2]]] + val[i] + val[att[i][2]]);
			if(k >= w[i] + w[att[i][1]] + w[att[i][2]]) dp[k] = max(dp[k], dp[k - w[i] - w[att[i][1]] - w[att[i][2]]] + val[i] + val[att[i][1]] + val[att[i][2]]);
		}
	}
	printf("%d", dp[N]);
	return 0;
}
