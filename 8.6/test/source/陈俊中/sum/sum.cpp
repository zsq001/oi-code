#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define maxn 10010
#define ll long long
using namespace std;

struct node
{
	ll fir,sec,len;
}f[maxn<<2];
ll add[maxn<<2],a[maxn],fib[maxn],sum[maxn];
int n,mod=1e9+7,m;

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

void init()
{
	fib[0]=1;fib[1]=1;
	for(int i=2;i<=n;i++) fib[i]=(fib[i-1]+fib[i-2])%mod;
	sum[0]=1;
	for(int i=1;i<=n;i++) sum[i]=(sum[i-1]+fib[i])%mod;
}

ll get(int x)
{
	if(x<0) return 0;
	else return fib[x];
}

void pushup(int o)
{
	ll len=f[o<<1].len;
	f[o].len=(f[o<<1].len+f[o<<1|1].len)%mod;
	f[o].fir=(f[o<<1].fir+f[o<<1|1].fir*get(len-2)+f[o<<1|1].sec*fib[len-1])%mod;
	f[o].sec=(f[o<<1].sec+f[o<<1|1].fir*fib[len-1]+f[o<<1|1].sec*fib[len])%mod;
}

void pushdown(int o,int l,int r)
{
	if(add[o]!=0)
	{
		add[o<<1]=(add[o<<1]+add[o])%mod;
		add[o<<1|1]=(add[o<<1|1]+add[o])%mod;
		f[o<<1].fir=(f[o<<1].fir+add[o]*sum[f[o<<1].len-1])%mod;
		f[o<<1].sec=(f[o<<1].sec+add[o]*sum[f[o<<1].len]-add[o])%mod;
		f[o<<1|1].fir=(f[o<<1|1].fir+add[o]*sum[f[o<<1|1].len-1])%mod;
		f[o<<1|1].sec=(f[o<<1|1].sec+add[o]*sum[f[o<<1|1].len]-add[o])%mod;
		add[o]=0;
	}
}

void build (int o,int l,int r)
{
	if(l==r)
	{
		f[o].sec=f[o].fir=a[l]%mod;
		f[o].len=1;
		return ;
	}
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	pushup(o);
}

void update(int o,int l,int r,int x,int y,int p)
{
	if(x<=l&&r<=y)
	{
		add[o]=(add[o]+p)%mod;
		f[o].fir=(f[o].fir+sum[r-l]*p)%mod;
		f[o].sec=(f[o].sec+sum[r-l+1]*p-p)%mod;
		return ;
	}
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	if(x<=mid) update(o<<1,l,mid,x,y,p);
	if(y>mid) update(o<<1|1,mid+1,r,x,y,p);
	pushup(o);
}

ll query(int o,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)
	{
		int len=l-x;
		if(len==0) return f[o].fir;
		return f[o].fir*get(len-2)+f[o].sec*get(len-1);
	}
	int mid=(l+r)>>1;
	pushdown(o,l,r);
	ll ans=0;
	if(x<=mid) ans=(ans+query(o<<1,l,mid,x,y))%mod;
	if(y>mid) ans=(ans+query(o<<1|1,mid+1,r,x,y))%mod;
	return ans%mod;
}

int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	read(n);read(m);
	init();
	for(int i=1;i<=n;i++) read(a[i]);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int q,l,r;
		ll val;
		read(q);
		if(q==1)
		{
			read(l);read(r);read(val);
			update(1,1,n,l,r,val);
		}
		if(q==2)
		{
			read(l);read(r);
			printf("%lld\n",query(1,1,n,l,r));
		}
	}
	return 0;
}
