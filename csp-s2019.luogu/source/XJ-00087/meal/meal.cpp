#include<cstdio>
const int M = 998244353;
int n,m,mp[110][2010],cnt[2010],ans;

void dfs(int cur,int lmt,int k,int sum)
{
	if(k == lmt)
	{
		ans = (1ll * ans + 1ll * sum) % M;
		return ;
	}
	if(cur > n) return ;
	for(int i = 1;i <= m;i ++)
	{
		if(!mp[cur][i]) continue;
		cnt[i] ++;
		if(cnt[i] > lmt/2)
		{
			cnt[i] --;
			continue;
		}
		
		dfs(cur+1,lmt,k+1,(1ll * sum * 1ll * mp[cur][i]) % M);
		cnt[i] --;
	}
	dfs(cur+1,lmt,k,sum);
}

int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= m;j ++)
		{
			scanf("%d",&mp[i][j]);
		}
	}
	for(int i = 2;i <= n;i ++)
	{
		dfs(1,i,0,1);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
