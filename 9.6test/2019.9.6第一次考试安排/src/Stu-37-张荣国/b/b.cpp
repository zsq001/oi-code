#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
#define mod 1000000007
long long f[2005][2005],ans;
int n;
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) f[i][i]=1;
	for(int i=n;i>=1;i--){
		for(int j=i+1;j<=n;j++){
			for(int k=n;k-i>=0;k--){
				f[i][k]=(f[i][k]+f[j][k-i])%mod;
			}
			
		}
	}
	for(int i=1;i<=n;i++) ans=(ans+f[i][n])%mod;
	printf("%lld",ans);
	return 0;
}
