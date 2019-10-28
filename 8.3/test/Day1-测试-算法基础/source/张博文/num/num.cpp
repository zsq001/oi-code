#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define maxn 100010
typedef int int_;
#define int long long
using namespace std;
int cnt=1,a[1010][1010];
int_ main(){
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++){
			a[i][j]=i*j;
			printf("%5lld ",a[i][j]);
		}
		puts("");
	}
	scanf("%lld%lld%lld",&n,&m,&k);
	if(k==1) printf("%lld",n*m),return 0;
	ans[1]=n*m;
	if(n==m){
		ans[++cnt]=ans[++cnt]=n*(m-1);
	}
	if(n<m){
		ans[++cnt]=m*(n-1);
		ans[++cnt]=n*(m-1);
	}
	if(n>m){
		ans[++cnt]=n*(m-1);
		ans[++cnt]=m*(n-1);
	}
	printf("%lld",ans[k]);
}
