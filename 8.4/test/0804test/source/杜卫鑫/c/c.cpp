#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int d[1000],dp[10000];
int main()
{
	int n,k,Q;
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&d[i]);
	scanf("%d",&Q);
	while(Q--)
	{
		memset(dp,127,sizeof(dp));
		dp[1]=0;
		scanf("%d",&k);
		for(int j=2;j<=n;j++)	
			for(int i=1;i<j&&i<=k;i++)
			{
				if(d[j-i]<=d[j])
					 dp[j]=min(dp[j],dp[j-i]+1);
				else dp[j]=min(dp[j],dp[j-i]);
			}
		printf("%d\n",dp[n]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}	
