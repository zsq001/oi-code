#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
//priority_queue<int, vector<int>, greater<int> >q;
int n, m,f[50];
long long a[20][50], ans;

void dfs(int x, int y, int t, int times, long long sum, int lim)
{
	sum *= a[x][y];
	sum %= 998244353;
	if(f[y] > lim)
		return;
	if(t == times)
	{
		ans += sum;
		ans %= 998244353;
		return;
	}
	for(int i = x+1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(a[i][j] != 0)
			{
				f[j]++;
				dfs(i, j, t+1, times, sum, lim);
				f[j]--;
			}
}

int main()
{
	freopen("meal.in", "r", stdin);
	freopen("meal.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%lld", &a[i][j]);	
	ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(a[i][j] != 0)
				for(int q = 2; q <= n-i+1; q++)
				{
					memset(f, 0, sizeof(f));
					f[j]++;
					dfs(i, j, 1, q, 1, q/2);
				}
	ans %= 998244353;
	printf("%lld", ans);
	return 0;
}
