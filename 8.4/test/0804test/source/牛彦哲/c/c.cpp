#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int d[1000010],k[30],dp[1000010];
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int n,q,i,j,ii,min,mnum,ht;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
	}
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d",&k[i]);
	}
	for(i=1;i<=q;i++)
	{
		memset(dp,0,sizeof(dp));
		mnum=1;
		min=0;
		ht=d[1];
		for(j=2;j<=n;j++)
		{
			if(j-mnum<=k[i])
			{
				if(ht<=d[j])
				{
					dp[j]=min+1;
				}
				else
				{
					ht=d[j];
					mnum=j;
					dp[j]=min;
				}
				continue;
			}
			min=dp[j-1];
			ht=d[j-1];
			for(ii=j-2;ii>0&&ii>=j-k[i];ii--)
			{
				if(dp[ii]<min||dp[ii]==min&&d[ii]<ht)
				{
					min=dp[ii];
					ht=d[ii];
					mnum=ii;
				}
			}
			if(ht<=d[j])
			{
				dp[j]=min+1;
			}
			else
			{
				ht=d[j];
				mnum=j;
				dp[j]=min;
			}
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}
