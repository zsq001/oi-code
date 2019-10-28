#include<cstdio>
#include<algorithm>
using namespace std;
typedef int int_;
#define int long long
#define MOD 1000000007

int n,inv2;
int s;
int ksm(int x,int m){
	int ret=1;
	while(m>0){
		if(m&1) ret*=x,ret%=MOD;
		x*=x,x%=MOD;
		m>>=1;
	}
	return ret;
}


//S=a1(1-q^(n+1))/1-q;

int_ main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%lld",&n);
	inv2=(MOD+1)/2;
	s=ksm(3,n+1);
	s-=1;
	s=((s%MOD)+MOD)%MOD;
	s*=inv2;
	s=((s%MOD)+MOD)%MOD;
	printf("%lld",s);
	return 0;
}

