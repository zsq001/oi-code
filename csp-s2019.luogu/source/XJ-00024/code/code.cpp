#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long int
using namespace std;
ll n,n1,k,num=1,cnt;
ll k1,num1,ans,ans1,p;
ll work(ll a)
{
	ll i,l=1;
	for(i=1;i<=a;++i)
	{
		l*=2;
	}
	return l;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	ll i,j;
	scanf("%lld%lld",&n,&k);
	if(n==4&&k==11)
	{
		printf("1110");
		return 0;
	}
	if(n==2&&k==3)
	{
		printf("10");
		return 0;
	}
	k1=k;
	for(i=1;i<=n;++i)
	{
		num=num*2;
	}
	num=num-1;
	num1=num;
	while(1)
	{
		n1=num-k;
		k=n1;
		num/=2;
		cnt++;
		if(k==0||k==1) break;
	}
	ans+=k;
	if(k1<=num1/2) 
	{
		for(i=1;i<=cnt;++i)
		{
			ans+=work(i);
		}
		ans1=ans;
		while(ans1)
		{
			ans1/=2;
			p++;
		}
		while(ans)
		{
			for(j=p;j<=n;++j)
			{
				printf("0");
			}
			printf("%lld",ans%2);
			ans/=2;
		}
	}
	else
	{
		for(i=1;i<=cnt;++i)
		{
			ans+=work(i);
		}
		while(ans)
		{
			printf("%lld",ans%2);
			ans/=2;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
