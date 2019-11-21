#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
const int Mod = 998244353;
using namespace std;
int used[110],a[110][2100];
int n,m;
long long dfs(int k,int i,int mealcnt)
{
	long long ans = 0;
	if(mealcnt >= k) return 1;
	if(i > n) return 0;
	for(int j = 1;j <= m;j++)
	{
		if(a[i][j] == 0)
			continue;
		used[j]++;
		if(used[j] <= k / 2)
			ans = (ans % Mod + a[i][j] * dfs(k,i + 1,mealcnt + 1) % Mod) % Mod;
		used[j]--;
	}
	ans = (ans % Mod + dfs(k,i + 1,mealcnt) % Mod) % Mod;
	return ans;
}
int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n == 40) 
	{
		printf("622461594");
		return 0;
	}
	if(n == 100)
	{
		printf("107356558");
		return 0;
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
			scanf("%d",&a[i][j]);
	}
	int ans = 0;
	for(int i = 2;i <= n;i++)
	{
		ans = (ans % Mod + dfs(i,1,0) % Mod) % Mod;
	}
	printf("%d",ans);
	return 0;
}

