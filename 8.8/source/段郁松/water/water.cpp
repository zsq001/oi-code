#include<stdio.h>
int mod=100000007;
int n;
bool vis[10000000];
int p[10000000],cnt;
int a[10000000];
long long maxx;
long long int ans=1;
void shai(int n) 
{
	int i,j;
	for(i=2;i<=n;++i) 
	{
		if(!vis[i]) p[cnt++]=i;
		for(j=0;i*p[j]<=n;++j) 
		{
			vis[i*p[j]]=1;
			if (i%p[j]==0) break;
		}
	}
}
long long int quick(int a,int b)
{
	long long int ans;
	if(b==0) return 1;
	ans=quick(a*a,b/2);
	if(b%2!=0) ans=ans*a;
	return ans;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int i,j;
	scanf("%d",&n);
	shai(n);
	cnt--;
	for(i=0;i<=cnt;++i)
	{
		for(j=1;j<=n;++j)
		{
			maxx=quick(p[i],j);
			if(maxx>n)
			{
				break;
			}
			ans*=p[i];
			ans=(ans%mod+mod)%mod;
		}
	}
	printf("%lld",ans%mod);
	return 0;
}
