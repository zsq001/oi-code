#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
long long int ans,b,n,d,m;
long long int x[100],y[100],z[100],p;
int main()
{
	freopen("minecraft.in","r",stdin);
	freopen("minecraft.out","w",stdout);
	long long int i,j;
	scanf("%lld%lld%lld%lld",&b,&n,&d,&m);
	if(b==1)
	{
		for(i=0;i<n;++i)
		{
			scanf("%lld",&x[i]);
		}
		sort(x,x+n);
		for(i=0;i<n;++i)
		{
			for(j=i+1;j<n;++j)
			{
				p=abs(x[i]-x[j]);
				if(p<=d) ans++;
				else break;
			}
		}
		printf("%d",ans);
		return 0;
	}
	else if(b==2)
	{
		for(i=0;i<n;++i)
		{
			scanf("%lld%lld",&x[i],&y[i]);
		}
		for(i=0;i<n;++i)
		{
			for(j=i+1;j<n;++j)
			{
				p=abs(x[i]-x[j])+abs(y[i]-y[j]);
				if(p<=d) ans++;
			}
		}
		printf("%lld",ans);
		return 0;	
	}
	else 
	{
		for(i=0;i<n;++i)
		{
			scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
		}	
		for(i=0;i<n;++i)
		{
			for(j=i+1;j<n;++j)
			{
				p=abs(x[i]-x[j])+abs(y[i]-y[j])+abs(z[i]-z[j]);
				if(p<=d) ans++;
			}
		}
		printf("%lld",ans);
		return 0;	
	}
	return 0;
}
