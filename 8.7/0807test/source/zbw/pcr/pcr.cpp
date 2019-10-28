#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

long long ans[1000010];
long long n;
const long long mod=19260817;
long long ksm(long long a,long long b){
	long long an=1;
	while(b){
		if(b&1) an=(an*a)%mod;
		b>>=1;
		a*=a;
	}
	return an%mod;
}
int main(){
	freopen("pcr.in","r",stdin);
	freopen("pcr.out","w",stdout);
	scanf("%lld",&n);
	if(n<=2){
		puts("0");
		return 0;
	}
	else{
		ans[3]=2;
		for(long long i=4;i<=n;i++){
			ans[i]=(ans[i-1]+ksm(2,i-1)-2)%mod;
		}
		printf("%lld\n",ans[n]);
		return 0;
	}
	return 0;
}
