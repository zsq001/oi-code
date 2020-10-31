#include<cstdio>
#include<algorithm>
using namespace std;
int n1,n2,k1,k2;
int ans;
const int mod = 1e8;
int f[110][110][20][20];
//i个0，j个1，末尾连续k个0/1的方案数 
int main(){
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	scanf("%d%d%d%d",&n1,&n2,&k1,&k2);
	f[0][1][1][1] = f[1][0][1][0] = 1;
	for(int i = 0; i <= n1; i++) 
		for(int j = 0; j <= n2; j++){
			if(i){
				for(int k = 2; k <= k1; k++)
					f[i][j][k][0] = f[i-1][j][k-1][0];
				for(int k = 1; k <= k2; k++)
					f[i][j][1][0] = (f[i][j][1][0]+f[i-1][j][k][1])%mod;
			}
			if(j){
				for(int k = 2; k <= k2; k++)
					f[i][j][k][1] = f[i][j-1][k-1][1];
				for(int k = 1; k <= k1; k++)
					f[i][j][1][1] = (f[i][j][1][1]+f[i][j-1][k][0])%mod;
			}
		}
	for(int i = 1; i <= k1; i++)
		ans = (ans+f[n1][n2][i][0])%mod;
	for(int i = 1; i <= k2; i++)
		ans = (ans+f[n1][n2][i][1])%mod;
	printf("%d",ans);
}  
