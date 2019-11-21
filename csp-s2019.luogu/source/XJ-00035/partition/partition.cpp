#include<cstdio>
#include<algorithm>
using namespace std;
typedef int int_;
#define int long long

int n,type;
int a[10000007],sum[10000007];
int ans,out;

void dfs(int o,int la){
	
	ans+=(sum[o]-sum[la])*(sum[o]-sum[la]);
	if(o==n){
		if(out==0) out=ans;
		else out=min(out,ans);
	}
	for(int i=o+1;i<=n;i++){
		if(sum[i]-sum[o] >= sum[o]-sum[la])
		dfs(i,o);
	}
	ans-=(sum[o]-sum[la])*(sum[o]-sum[la]);
}

int_ main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	scanf("%lld %lld",&n,&type);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	dfs(0,0);
	printf("%lld",out);
	return 0;
}
