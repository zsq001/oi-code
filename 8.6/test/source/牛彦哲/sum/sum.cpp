#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define mo 1000000007
#define sz 60000000
int fib[sz]={0,1},n,m,a[100010],block[400],ks,ans;
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int i,j,co,l,r,z;
	for(i=2;i<sz;i++)
	{
		fib[i]=(fib[i-1]+fib[i-2])%mo;
	}
	scanf("%d%d",&n,&m);
	ks=(int)(sqrt(n)+0.5);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d",&co);
		if(co==1)
		{
			scanf("%d%d%d",&l,&r,&z);
			if(l/ks==r/ks)
			{
				for(j=l;j<=r;j++)
				{
					a[j]+=z;
				}
			}
			else
			{
				j=l;
				while(j%ks>0)
				{
					a[j]+=z;
					j++;
				}
				while(j+ks<=r)
				{
					block[j/ks]+=z;
					j+=ks;
				}
				while(j<=r)
				{
					a[j]+=z;
					j++;
				}
			}
		}
		else
		{
			scanf("%d%d",&l,&r);
			ans=0;
			for(j=l;j<=r;j++)
			{
				ans+=fib[a[j]+block[j/ks]];
				ans%=mo;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
