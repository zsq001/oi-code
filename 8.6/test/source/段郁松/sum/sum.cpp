#include<stdio.h>
long long int a[100005],b[100005];
long long int n,m,x,q,z,v,ans;
void da()
{

	long long int i=3;
	a[1]=1;
	a[2]=1;
	while(1)
	{
		a[i]=a[i-1]+a[i-2];
		a[i]=a[i]%(1000000000+7);
		i++;
		if(i==100000) break;
	}
	return ;
}
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	long long int i,j;
	da();
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;++i)
	{
		scanf("%lld",&b[i]);
	}
	for(i=1;i<=m;++i)
	{
		scanf("%lld",&x);
		if(x==1)
		{
			scanf("%lld%lld%lld",&q,&z,&v);
			for(j=q;j<=z;++j)
			{
				b[j]+=v;
			}
		}
		if(x==2)
		{
			scanf("%lld%lld",&q,&z);
			for(j=q;j<=z;++j)
			{
				ans+=a[b[j]];
				ans=ans%(1000000000+7);
			}
			printf("%lld\n",ans%(1000000000+7));
			ans=0;
		}
	}
	return 0;
}
