#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,type;
int a[100005],b[10005];
long long int ans,p;
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	int i;
	scanf("%d%d",&n,&type);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
	}
	a[n+1]=1e7;
	if(type==1)
	{
		p=rand();
		printf("%lld",p*p%998244353);
	}
	else
	{
		for(i=2;i<n;++i)
		{
			if(a[i]<a[i-1]&&a[i]<a[i+1]&&a[i]+a[i-1]<a[i]+a[i+1])
			{
				a[i-1]=a[i-1]+a[i];
				a[i]=0;
			}
			else if(a[i]<a[i-1]&&a[i]<a[i+1]&&a[i]+a[i-1]>=a[i]+a[i+1])
			{
				a[i+1]=a[i+1]+a[i];
				a[i]=0;
			}
		}
		if(a[1]>a[2])
		{
			a[2]=a[1]+a[2];
			a[1]=0;
		}
		if(a[n-1]>a[n])
		{
			a[n-1]=a[n-1]+a[n];
			a[n]=0;
		}
	}
	for(i=1;i<=n;++i)
	{
		ans+=a[i]*a[i];
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
