#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
#define mod 998244353
using namespace std;

int n,m;
int a[2010][2010];
long long ans=0;
int judge[2010],maxn;

void dfs(int k,int cnt,long long res,int ii)
{
	if(cnt==k)
	{
		ans=(ans+res)%mod;
		return;
	}
	for(int i=ii;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(!a[i][j]) continue;
			if(judge[j]+1<=maxn)
			{
				long long kk=(res*a[i][j])%mod;
				judge[j]++;
				dfs(k,cnt+1,kk,i+1);
				judge[j]--;
			}
		}
	}
}

//void init()
//{
//	memset(vis,0,sizeof(vis));
//	return;
//}

int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	int jd=min(n,m);
//	printf("%d",3/2);
//	return 0;
	for(int k=2;k<=jd;k++)
	{
		maxn=k/2;
//		printf("%d",maxn);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(!a[i][j]) continue;
				judge[j]++;
				dfs(k,1,a[i][j]%mod,i+1);
				judge[j]--;
			}
		}
	}
	printf("%lld",ans);
	
	fclose(stdin);
	fclose(stdout);	
	return 0;
}

//5 5
//1 0 0 1 1
//0 1 0 1 0
//1 1 1 1 0
//1 0 1 0 1
//0 1 1 0 1

