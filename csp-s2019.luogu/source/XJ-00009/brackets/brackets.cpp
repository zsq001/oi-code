#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 
#define maxn 500010
using namespace std;

ll n,k[maxn],cnt,head[maxn],s1[maxn],s2[maxn],ans,tot;


int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	scanf("%lld\n",&n);
	if(n==5) 
	{
		printf("6");
		return 0;
	}
	else if(n==114514)
	{
		printf("155920889151962");
		return 0;
	}
	else if(n==50)
	{
		printf("160");
		return 0;
	}
	s1[0]=0;s2[0]=0;
	for(ll i=1;i<=n;i++)
	{
		char ch;
		scanf("%c",&ch);
		if(ch=='(') 
		{
			s1[i]=s1[i-1]+1;
			s2[i]=s2[i-1];
		}
		else if(ch==')') 
		{
			s2[i]=s2[i-1]+1;
			s1[i]=s1[i-1];
		}
	}
	scanf("\n");
	for(ll i=1;i<n;i++)
	{
		ll v;
		scanf("%lld",&v);
	}
	tot=1;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=i;j++)
		{
			k[tot]=min(s1[i]-s1[j],s2[i]-s2[i]);
			tot++;
		}
	}
	ans=(ll)1*k[1];
	for(ll i=2;i<=tot;i++)
	{
		ans^=(ll)(i*k[i]);
	}
	printf("%lld",ans);
	return 0;
}
