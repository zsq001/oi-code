#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
priority_queue<int>Q;
typedef int int_;
#define int long long
int n,m,k;
int c(int x){
	int ret=0;
	for(int i=1;i<=n;i++){
		if(x%i==0&&x/i<=m)ret++;
	}
	return ret;
}
int_ main(){
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	if(k==n*m){
		printf("%lld",n*m);
		return 0;
	}
	if(n==1||m==1||k==1){
		printf("%lld",k);
		return 0;
	}
	int cnt=0;
	int qwq=n*m;
	for(int i=1;i<=qwq;i++){
		cnt+=c(i);
		if(cnt>=k){
			printf("%lld",i);
			return 0;
		}
	}
}
