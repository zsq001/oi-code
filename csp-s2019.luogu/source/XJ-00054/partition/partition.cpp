#include<stdio.h>
#include<stdlib.h>
int n,type;
long long a[500005],sum[500005],ans=0x7fffffffffffffff;
void dfs(int ste,long long lst,long long alr)
{
	if(alr>=ans)
	{
		return;
	}
	if(ste>n)
	{
		ans=alr;
	}
	int i=ste;
	long long t;
	while(sum[i]-sum[ste-1]<lst&&i<=n)
	{
		i++;
	}
	for(;i<=n;i++)
	{
		t=sum[i]-sum[ste-1];
		dfs(i+1,t,alr+t*t);
	}
}
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	int i,j,k,t;
	scanf("%d%d",&n,&type);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	dfs(1,0,0);
	printf("%lld",ans);
	return 0;
}
