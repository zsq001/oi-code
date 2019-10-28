#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll u,v,m,l1,l2,a,b,c,d;
ll mod(ll k,ll p)
{
	return ((k%p)+p)%p;
}
ll gcd(ll k,ll p)
{
	if(!p)
	{
		return k;
	}
	else gcd(p,k%p);
}
void exgcd(ll k,ll p,ll &x,ll &y)
{
	if(!p)
	{
		x=1;
		y=0; 
		return ;
	}
	else exgcd(p,k%p,y,x);
	y-=(k/p)*x;
	return ;
}
int main()
{
	freopen("toad.in","r",stdin);
	freopen("toad.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&u,&v,&l1,&l2,&m);
	a=l1-l2,b=m,c=v-u;
	if(a<0)
	{
		a=-a;
		c=-c;
	}
	d=gcd(a,b);
	if(c%d!=0)
	{
		printf("Impossible");
		return 0;
	}
	ll x,y;
	exgcd(a,b,x,y);
	b/=d;
	x*=c/d;
	x=mod(x,b);
	printf("%lld",x);
}
