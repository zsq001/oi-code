#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define mod 100000007
int p[100001],prime[100001];
bool f[100001];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	int n,cnt=0,ans=1;
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d",&n);
//	if(n<=100){
//		int ans=1;
//		for(int i=1;i<=n;i++){
//			if(ans%i)ans=ans*i/gcd(i,ans);
//		}
//		printf("%d\n",ans);
//		return 0;
//	}
	if(n<=10000){
		for(int i=2;i<=n;i++){
			if(f[i])continue;
			prime[++cnt]=i;
			p[cnt]++;
			for(int j=i;j*i<=n;j++){
				f[i*j]=1;
			}
		}
		for(int i=2;i<=n;i++){
			if(!f[i])continue;
			int b=i;
			for(int j=1;prime[j]<b&&j<=cnt;j++){
				int nowmax=0;
				while(b&&b%prime[j]==0){
						b/=prime[j];
						nowmax++;
				}
				p[j]=max(p[j],nowmax);
			}
		}
		for(int i=1;i<=cnt;i++){
			while(p[i]){
				ans=(1ll*prime[i]*ans)%mod;
				p[i]--;
			}
		}
		printf("%d",ans);
	}
	return 0;
}
