#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long 
using namespace std;

template<class T> inline void read(T &x)
{
    x=0;
    register char c=getchar();
    register bool f=0;
    while (!isdigit(c)) f ^=c=='-',c=getchar();
    while (isdigit(c)) x=x*10+c-'0',c=getchar();
    if(f)x=-x;
}

template <class T> inline void print(T x)
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar('0'+x%10);
}

ll gcd(ll a,ll b)
{
	return b?gcd(b,a%b):a;
}

ll exgcd(ll a,ll b,ll &x,ll &y)
{
	ll ans;
	if(!b)
	{
		x=1;y=0;
		return a;
	}
	ans=exgcd(b,a%b,x,y);
	ll t=x;
	x=y;
	y=t-a/b*y;
	return ans;
}

int main()
{
	freopen("toad.in","r",stdin);
	freopen("toad.out","w",stdout);
	ll x,y,m,n,l;
	read(x);read(y);read(m);read(n);read(l);
	ll a=n-m,b=l,c=x-y;
	if(a<0)
	{
		a=-a;
		c=-c;
	}
	ll d=gcd(a,b);
	if(c%d)
	{
		printf("Impossible");
		return 0;
	}
	exgcd(a,b,x,y);
	x=x*c/d;
	b=b/d;
	x=((x%b)+b)%b;
	printf("%lld",x);
	return 0;
}
