#include<cstdio>
#include<algorithm>
using namespace std;
int w[65],v[65];
int q[65][3];
int dp[32010];
int main()
{
	freopen("budget.in","r",stdin);
	freopen("budget.out","w",stdout);
	int t,m;
	scanf("%d%d",&t,&m);
	for(int i = 1;i <= m;i ++)
	{
		int p,Q;
		scanf("%d%d%d",&w[i],&p,&Q);
		v[i] = p * w[i];
		if(Q != 0)
		{
			if(q[Q][1] == 0) q[Q][1] = i;
			else q[Q][2] = i;
		}
		else
			q[i][0] = 1;
	}
	for(int i = 1;i <= m;i ++)
	{
		for(int j = t;j >= 0;j --)
		{
			if(!q[i][0]) continue;
			int q1 = q[i][1],q2 = q[i][2];
			if(j >= w[i]) dp[j] = max(dp[j],dp[j - w[i]] + v[i]);
			if(j >= w[i] + w[q1]) dp[j] = max(dp[j],dp[j - w[i] - w[q1]] + v[i] + v[q1]);
			if(j >= w[i] + w[q2]) dp[j] = max(dp[j],dp[j - w[i] - w[q2]] + v[i] + v[q2]);
			if(j >= w[i] + w[q1] + w[q2]) dp[j] = max(dp[j],dp[j - w[i] - w[q1] - w[q2]] + v[i] + v[q1] + v[q2]);
		}
	}
	printf("%d",dp[t]);
	return 0;
}
