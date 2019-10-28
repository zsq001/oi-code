#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#define maxn 200010
#define ll long long 
using namespace std;

ll n,a[maxn];
ll suma,sumb,ans;

int main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(i%2==1) suma+=a[i];
		else sumb+=a[i];
	}
	int flag=2;
	if(sumb<suma)
	{
		flag=1;
	}
	if(sumb==suma) flag=3;
	if(flag==1)
	{
		int i=1;
		while(i%2==1&&i<=n)
		{
			if(sumb+a[i]==suma) ans++;
			i+=2;
		}
	}
	if(flag==2)
	{
		int i=2;
		while(i%2==0&&i<=n)
		{
			if(suma+a[i]==sumb) ans++;
			i+=2;
		}
	}
	if(flag==3)
	{
		int i=1;
		while(i<=n)
		{
			if(sumb+a[i]==suma) ans++;
			i++;
		}
	}
	printf("%lld",ans);
	return 0;
}
