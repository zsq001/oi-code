#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define mod 100000007
using namespace std;
typedef long long ll;

ll ans=1,b=1;
int cnt=0,p[10010],n,num[10010];
bool vis[100000000]={false};


ll Mod(ll a)
{
	return (a%mod+mod)%mod;
}

int jud(int a,int n)
{
	int c=0;
	while(n%a==0)
	{
		c++;
		n/=a;
		vis[n]=true;
	}
	return c;
}

ll quick_pow(int a,int k)
{
	ll res=1;
	while(k)
	{
		if(k&1) res=Mod(res*a);
		k>>=1;
		a=Mod(a*a);
	}
	return Mod(res);
}

ll quick_a(int a,int k)
{
	ll res=0;
	while(k)
	{
		if(k&1) res=Mod(res+a);
		k>>=1;
		a=Mod(a<<1);
	}
	return Mod(res);
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d",&n);
	if(n==0)
	{
		printf("0");
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])
		{
			for(int j=1;i*j<=n;j++)
				vis[i*j]=true;
			p[++cnt]=i;
		}
	}
	memset(vis,false,sizeof(vis));
	for(int i=n;i>=2;i--)
	{
		if(!vis[i])
		for(int j=1;j<=cnt;j++)
		{
			num[j]=max(num[j],jud(p[j],i));
		}
//		printf("%d\n",p[i]);
	}
	for(int i=1;i<=cnt;i++)
		ans=Mod(quick_a(ans,quick_pow(p[i],num[i])));
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
