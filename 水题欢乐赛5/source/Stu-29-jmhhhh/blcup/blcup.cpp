#include<cstdio>
#include<algorithm>
using namespace std;
typedef int int_;
#define int long long
#define MOD 19260817
/*
   n          n            n
6*C     -3*(C     ) -3* C
  3n         2n            2n 
*/
int fac[30050],inv[30050],ans;
int n;
int ksm(int a,int p){
	int ret=1;
	while(p>0){
		if(p&1) ret=ret*a,ret%=MOD;
		a=a*a;
		a%=MOD;
		p>>=1;
	}
	return ret;
}

void init_(){
	fac[0]=1;
	for(int i=1;i<=3*n;i++){
		fac[i]=fac[i-1]*i;
		fac[i]%=MOD;
	}
	inv[3*n]=ksm(fac[3*n],MOD-2);
	for(int i=3*n-1;i>=1;i--){
		inv[i]=inv[i+1]*(i+1);
		inv[i]%=MOD;
	}
}





int_ main()
{
	freopen("blcup.in","r",stdin);
	freopen("blcup.out","w",stdout);
	scanf("%lld",&n);
	init_();
	ans=((fac[3*n]*inv[n])%MOD*inv[2*n])%MOD-((fac[2*n]*inv[n])%MOD*inv[n])%MOD;
	ans=(6ll*ans)%MOD;
	if(ans<0) ans+=MOD;
	printf("%lld",ans);
	return 0;
}



