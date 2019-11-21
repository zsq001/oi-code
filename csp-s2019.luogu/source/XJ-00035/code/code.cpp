#include<cstdio>
#include<algorithm>
using namespace std;
typedef int int_;
#define int long long


int n,k;
int ans[100];

void work(int o){
	if(o==1){
		if(k==1) ans[o]=0;
		else ans[o]=1;
		return ;
	}
	if(o==64){
		ans[o]=0;
		work(o-1);
	}
	else{
		if(k>(1ll<<(o-1))) ans[o]=1,k=((1ll<<(o-1))-(k-(1ll<<(o-1)))+1ll),work(o-1);
		else ans[o]=0,work(o-1);
	}
	return ;
}


int_ main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	k+=1;
	work(n);
	for(int i=n;i>=1;i--){
		printf("%lld",ans[i]);
	}
	return 0;
}
