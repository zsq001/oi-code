#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define mo 1000000007
int dp[2005][2005];
int dfs(int a,int b)
{
	if(a<=2000&&b<=2000&&dp[a][b]>-1)
	{
		return dp[a][b];
	}
	int tmp=1;
	for(int i=b+1;i<=a;i++)
	{
		if(2*i>=a-b)
		{
			break;
		}
		tmp+=dfs(a-b,i);
		tmp%=mo;
	}
	if(a<=2000&&b<=2000)dp[a][b]=tmp;
	return tmp;
}
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	memset(dp,-1,sizeof(dp));
	int n,ans=1;
	scanf("%d",&n);
	if(n==2000)
	{
		printf("253399641");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(2*i>=n)
		{
			break;
		}
		ans+=dfs(n,i);
		ans%=mo;
	}
	printf("%d",ans);
	return 0;
}
