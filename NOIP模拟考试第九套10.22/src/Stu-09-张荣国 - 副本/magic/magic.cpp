#include<stdio.h>
typedef int int_;
#define int long long
#define mod 1000000007
using namespace std;
int n;
int q_pow(int a,int b){
	int base=a,ret=1;
	while(b){
		if(b&1)
			ret=(base*ret)%mod;
		b>>=1;
		base=(base*base)%mod;
	}
	return ret;
}
int_ main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%lld",&n);
	int a=1,tmp=q_pow(3,n);
	printf("%lld",(a*(tmp-1)*((mod+1)/2)+mod)%mod);
	return 0;
}
