#include <stdio.h>
const int mod=998244353;
int a[25][25],vis[2005],chen[105],prin[2005],kan[105];
int n,m,ans,num,visit;
void calc2()
{
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			if(i!=j)
				ans=(ans+(a[1][i]*a[2][j])%mod)%mod;
}		
void calc(int dep,int cnt)
{
	if(dep>num)
	{
		int tmp=1;
		for(int k=1,i=1;i<=num&&k<=num;i++,k++)
			tmp=(a[chen[i]][prin[k]]*tmp)%mod;
		ans=(ans+tmp)%mod;
		return ;
			
	}
	for(;cnt<=n;cnt++)
		if(!kan[cnt])
		{
			kan[cnt]=1;
			chen[dep]=cnt;
			calc(dep+1,cnt+1);
			kan[cnt]=0;
		}
}
		
void dfs(int dep)
{
	if(dep>num)
	{
		calc(1,1);
		return ;
	}
	for(int i=1;i<=m;i++)
		if(vis[i]<visit)
		{
			vis[i]++;
			prin[dep]=i;
			dfs(dep+1);
			vis[i]--;
		}
}
int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			a[i][j]%=mod;
		}
	if(n==2){calc2();printf("%d\n",ans);return 0;}
	for(num=2;num<=n;num++)
	{
		visit=num/2;
		dfs(1);
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
