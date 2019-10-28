#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long 
#define maxn 1000010
using namespace std;

ll n,mod=19260817;


struct MAT
{
    ll A[110][110];
    ll x,y;
    MAT(ll x_,ll y_)
    {
    	x=x_;y=y_;
    	for(ll i=1;i<=x;++i)
    	{
    		for(ll j=1;j<=y;++j)
    		{
    			A[i][j]=0;
			}
		}
	}
	void Init(bool flag)
	{
		for(ll i=1;i<=x;++i)
		{
			for(ll j=1;j<=y;++j)
			{
				A[i][j]=0;
			}
		}
		if(flag)
		{
			for(ll i=1;i<=x;++i) A[i][i]=1;
		}
	}
	MAT operator*(MAT b)
	{
		MAT a=*this;
		MAT c(a.x,b.y);
		c.Init(0);
		for(ll i=1;i<=a.x;++i)
		{
			for(ll j=1;j<=b.y;++j)
			{
				for(ll k=1;k<=a.y;++k)
				{
					c.A[i][j]+=a.A[i][k]*b.A[k][j];
					c.A[i][j]%=mod;
				}
			}
		}
		return c;
	}
	MAT operator^(ll b)
	{
		MAT a=*this;
		MAT ret(x,x);
		ret.Init(1);
		while(b)
		{
			if(b&1) ret=ret*a;
			b>>=1;
			a=a*a;
		}
		return ret;
	}
};




int main()
{
	
	freopen("pcr.in ","r",stdin);
	freopen("pcr.out","w",stdout);
	scanf("%lld",&n);
	if(n<=2)
	{
		printf("0");
		return 0;
	}
	if(n==3)
	{
		printf("2");
		return 0;
	}
	MAT ans(3,3),work(3,1);
	ans.A[1][1]=2;ans.A[1][2]=2;
	ans.A[2][2]=ans.A[2][3]=ans.A[3][3]=1;
	work.A[1][1]=0;work.A[2][1]=work.A[3][1]=1;
	ans=ans^(n-2);
	work=ans*work;
	printf("%lld",work.A[1][1]);
	return 0;
}
