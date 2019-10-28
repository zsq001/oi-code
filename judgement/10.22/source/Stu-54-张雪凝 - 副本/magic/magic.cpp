#include<cstdio>
#include<algorithm>
using namespace std;
#define mod 1000000007
#define ll long long

ll ksm(ll a,ll b){
	ll ret=1;
	while(b){
		if(b&1) ret=(ret*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ret%mod;
}

int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	int n;
	scanf("%d",&n);
	printf("%lld",((ksm(3,n)-1)/2*3+1)%mod);
}
