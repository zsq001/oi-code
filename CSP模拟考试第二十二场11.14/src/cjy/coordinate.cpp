#include <cstdio>
#define mod 1000000007
#define ll long long
struct node
{
	ll a,b;
	ll c,d;
};
struct node2
{
	ll a,b;
}ans;
node mul(node a,node b)
{
	node c;
	c.a=a.a*b.a%mod+a.b*b.c%mod;
	c.a%=mod;
	c.b=a.a*b.b%mod+a.b*b.d%mod;
	c.b%=mod;
	c.c=a.c*b.a%mod+a.d*b.c%mod;
	c.c%=mod;
	c.d=a.c*b.b%mod+a.d*b.d%mod;
	c.d%=mod;
	return c;
}
node2 mul2(node2 a,node b)
{
	node2 c;
	c.a=a.a*b.a%mod+a.b*b.c%mod;
	c.a%=mod;
	c.b=a.a*b.b%mod+a.b*b.d%mod;
	c.b%=mod;
	return c;
}
void kpow(node base,ll n)
{
	while(n)
	{
		if(n%2)
		{
			ans=mul2(ans,base);
		}
		base=mul(base,base);
		n/=2;
	}
	return;
}
int main()
{
	freopen("coordinate.in","r",stdin);
	freopen("coordinate.out","w",stdout);
	ll n,ansnum;
	scanf("%I64d",&n);
	node base;
	base.a=1;base.b=2;
	base.c=1;base.d=1;
	ans.a=1;
	ans.b=0;
	kpow(base,n);
	ansnum=ans.a+ans.b;
	ansnum%=mod;
	printf("%I64d",ansnum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
