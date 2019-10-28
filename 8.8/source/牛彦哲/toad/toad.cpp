#include<stdio.h>
#include<stdlib.h>
#define abs(a) (a>0?a:-a)
typedef long long ll;
ll x,y,n,m,l,p,q;
void exgcd(ll a,ll b)
{
	if(b==0)
	{
		p=1;
		q=0;
		return;
	}
	exgcd(b,a%b);
	ll t=p;
	p=q;
	q=t-a/b*q;
}
int main()
{
	freopen("toad.in","r",stdin);
	freopen("toad.out","w",stdout);
	scanf("%d%d%d%d%d",&x,&y,&m,&n,&l);
	if(m==n)
	{
		printf("Impossible");
	}
	x%=l;
	y%=l;
	exgcd(m-n,l);
	printf("%lld",p*(l-x+y)-2);
	return 0;
}
