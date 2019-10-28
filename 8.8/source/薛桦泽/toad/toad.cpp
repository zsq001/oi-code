#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;

ll x,y,m,n,l;
ll mtp,mts,g;
int cycle[100000000],cnt=0;

ll gcd(ll a,ll b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}

int main()
{
	freopen("toad.in","r",stdin);
	freopen("toad.out","w",stdout);
	
	scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
	if(m==n)
	{
		printf("Impossible");
		return 0;
	}
	mtp=((x-y)%l+l)%l;
	mts=((n-m)%l+l)%l;
	g=gcd(l,mts);
	if(mts==0)
	{
		printf("Impossible");
		return 0;
	}
	if(mtp%mts==0&&mtp>=mts)
	{
		printf("%d",mtp/mts);
		return 0;
	}
	int ans=0;
	int tx=x,ty=y;
	while(tx!=ty)
	{
		ans++;
		if(tx+m<=l)tx+=m;
		else tx=(tx+m+l)%l;
		if(ty+m<=l)ty+=n;
		else ty=(ty+n+l)%l;
		if(ans>=1000000010)
		{
			printf("Impossible");
			return 0;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
