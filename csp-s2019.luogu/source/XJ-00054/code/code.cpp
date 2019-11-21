#include<stdio.h>
#include<stdlib.h>
//´Ó0±àºÅ£¡£¡
long long n,k;
long long a[65]={1},b[1035]={0,1},sz[105];
void mymake(long long p)
{
	int cnt=0,i;
	while(p>0)
	{
		sz[++cnt]=p%2;
		p/=2;
	}
	for(i=n;i>0;i--)
	{
		printf("%lld",sz[i]);
	}
	printf("\n");
}
void dfs(long long l,long long r,long long x,long long y,long long to,int opt)
{
	if(l==r)
	{
		mymake(y);
		return;
	}
	long long mid1=(l+r)/2,mid2=(x+y)/2;
	if(to<=mid1)
	{
		if(opt==0)
		{
			dfs(l,mid1,x,mid2,to,0);
		}
		else
		{
			dfs(l,mid1,mid2+1,y,to,0);
		}
	}
	else
	{
		if(opt==0)
		{
			dfs(mid1+1,r,mid2+1,y,to,1);
		}
		else
		{
			dfs(mid1+1,r,x,mid2,to,1);
		}
	}
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	int i,j;
	if(n<=10)
	{
		for(i=1;i<=11;i++)
		{
			a[i]=a[i-1]*2;
		}
		for(i=2;i<=10;i++)
		{
			for(j=a[i-1];j<a[i];j++)
			{
				b[j]=b[a[i]-1-j]+a[i-1];
			}
		}
		mymake(b[k]);
		return 0;
	}
	for(i=1;i<=n&&i<63;i++)
	{
		a[i]=a[i-1]*2;
	}
	dfs(0,a[n]-1,0,a[n]-1,k,0);
	return 0;
}
