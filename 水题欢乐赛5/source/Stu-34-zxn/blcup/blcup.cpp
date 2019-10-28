#include<cstdio>
#define mod 19260817
long long n,fac[30010],inv[30010];
//int find(int n,int m){
//	if(n==0||m==0||n==1||n==m)return f[n][m]=1;
//	if(m==1||n-m==1)return f[n][m]=n;
//	return f[n][m]=(find(n-1,m-1)+find(n-1,m))%mod;
//}
void init(){
	fac[1]=inv[1]=1;
	int nn=3*n;
	
	for(int i=2;i<=nn;i++)fac[i]=fac[i-1]*i%mod;
	for(int i=2;i<=nn;i++)inv[i]=(mod-mod/i*inv[mod%i]%mod)%mod;
	for(int i=2;i<=nn;i++)inv[i]=inv[i-1]*inv[i]%mod;
}
long long C(int n,int m){
	return 1ll*fac[n]*inv[m]*inv[n-m]%mod;
}
int main(){
	freopen("blcup.in","r",stdin);
	freopen("blcup.out","w",stdout);
	scanf("%d",&n);
	init();
	printf("%lld",(6*((C(3*n,n)-C(2*n,n)+mod)%mod)%mod)%mod);
}
