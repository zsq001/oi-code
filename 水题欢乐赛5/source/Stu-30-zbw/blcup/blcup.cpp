#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
typedef int int_;
#define int long long
int n,c[1010][1010];
const int mod=19260817;
void init(){
	c[0][0]=1;
	for(int i=0;i<=1000;i++){
		for(int j=0;j<=i;j++){
			if(i==0&&j==0) continue;
			c[i][j]=((c[i-1][j]+c[i-1][j-1])%mod+mod)%mod;
			//printf("%d ",c[i][j]);
		}
		//puts("");
	}
}
int_ main(){
	freopen("blcup.in","r",stdin);
	freopen("blcup.out","w",stdout);
	scanf("%lld",&n);
	init();
	int c1=c[2*n][n];
	int c2=c[3*n][2*n];
	printf("%lld",((c2-c1)*6%mod+mod)%mod);
	return 0;
}
//c 2n n 4 2
//c 3n 2n 6 4
