#include <stdio.h>
const int mod =100000007;
int prime[10000005],vis[10000005],w[10000005];
int main()
{
	int n,ans=1,cnt=0,ii,t;
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])prime[++cnt]=i,w[cnt]++;
		for(int j=1;(i*prime[j])<=n;j++)
		{
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
		ii=i;
		if(ii&&vis[i])
		{
			for(int j=1;prime[j]<=ii;j++)
			{
				t=w[j];
				while(ii%prime[j]==0)
					{
						ii/=prime[j];
						if(t)t--;
						else w[j]++;
					}
			}
		}
	}
	for(int i=1;i<=cnt;i++)
		for(int j=1;j<=w[i];j++)
		{
			ans=(ans*prime[i])%mod;
		}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
			
			
