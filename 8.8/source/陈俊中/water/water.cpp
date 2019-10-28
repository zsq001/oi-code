#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<bitset>
#define ll long long 
#define maxn 100000000
using namespace std;

ll mod=100000007;
bitset <maxn> f;
int p[6000005],tot;
int n;
ll ans=1;

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

ll work(ll a,ll b)
{
	ll s=1;
	while(b)
	{
		if(b&1) s=(s*a)%mod;
		b>>=1;
		a=(a*a)%mod;
	}
	return s;
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d",&n);
	int len=sqrt(n);
	f[1]=1;
	for(register int i=2;i<=n;i++)
	{
		if(!f[i])
		{
			p[++tot]=i;
			if(i>len) ans=(ans*i)%mod;
			else ans=ans*work(i,log2(n)/log2(i))%mod;
		}
		for(register int j=1;j<=tot&&i*p[j]<=n;j++)
		{
			f[p[j]*i]=1;
			if(i%p[j]==0) break;
		}
	}
	printf("%lld\n",ans);
//	printf("%.3fMB\n",(double)sizeof(f)/(1<<20));
	return 0;
}
