#include <cstdio>
#include <algorithm>
typedef long long ll;
using namespace std;
const ll mod=19260817;

ll ys[2][1000010];
ll node(ll n) {
	if (n == 3) return 2;
	ll ret = ((((n-2)%mod+node(n-1)%mod)%mod)<<1)%mod;
	return ret;
}
int main() {
	ll n;
	freopen("pcr.in","r",stdin);
	freopen("pcr.out","w",stdout);
	scanf("%lld",&n);
	if (n <= 2) {
		printf("0\n");
	} else if (n <= 26000) {
		printf("%lld",node(n));
	} else {
		ys[1][1]=1;
		ll ans=0; 
		for (int i=2;i<=n;i++) {
			for(int j=1;j<=i;j++){
				ys[i&1][j]=(ys[(i-1)&1][j-1]+ys[(i-1)&1][j])%mod;
				if(i==n&&j>=3) ans+=ys[i&1][j];
			}
		}
		printf("%lld",(ans<<1)%mod);
	}
	return 0;
}
