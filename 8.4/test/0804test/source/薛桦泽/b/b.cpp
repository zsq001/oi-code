#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,q,d[100010];
int dp[100010]={0};
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&d[i]);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int k;
		scanf("%d",&k);
		dp[1]=0;
		for(int j=2;j<=n;j++)
		{
			dp[j]=j-1;
			for(int m=1;m<=min(j,k);m++)
			{
				 if(d[j]<d[j-m]) dp[j]=min(dp[j],dp[j-m]);
				 else dp[j]=min(dp[j],dp[j-m]+1);
			}
		}
		printf("%d\n",dp[n]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
}

