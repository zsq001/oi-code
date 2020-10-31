#include<cstdio>
#include<math.h>
#include<algorithm>
using namespace std;
int dp[100010],w[100010],val[100010],shuyu[100010];
int map[100010][4];
int main()
{
	int n,m,i,j,k;
	freopen("budget.in","r",stdin);
	freopen("budget.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&w[i],&val[i],&shuyu[i]);
		val[i]*=w[i];
		if(shuyu[i]!=0)
		{
			if(map[shuyu[i]][1]==0)map[shuyu[i]][1]=i;
			else map[shuyu[i]][2]=i;
		}
	}
	for(i=1;i<=m;i++)
	{
		if(shuyu[i]!=0)continue;
		for(j=n;j>=0;j--)
		{
			if(j>=w[i])dp[j]=max(dp[j],dp[j-w[i]]+val[i]);
			if(j>w[i]+w[map[i][1]])dp[j]=max(dp[j],dp[j-w[i]-w[map[i][1]]]+w[i]+w[map[i][1]]);
			if(j>w[i]+w[map[i][2]])dp[j]=max(dp[j],dp[j-w[i]-w[map[i][2]]]+w[i]+w[map[i][2]]);
			if(j>w[i]+w[map[i][1]]+w[map[i][2]])dp[j]=max(dp[j],dp[j-w[i]-w[map[i][1]]-w[map[i][2]]]+w[i]+w[map[i][1]]+w[map[i][2]]);
		}
	}
	printf("%d",dp[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
