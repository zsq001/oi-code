#include<cstdio>
#include<algorithm>
using namespace std;
typedef int int_;
#define int long long
#define mod 1000000007

int n,k,d,ans,a[1050];

int count_(int mul,int now){
	int ret=0;
	for(int i=now;i<=n;i++){
		if(mul*a[i] == k){
			ret++;
			ret%=mod;
			continue;
		}
		if(mul*a[i]*a[i] > k) continue;
		if(mul*a[i] > k) break;
		ret+=count_(mul*a[i],i+1);
		ret%=mod;
	}
	return ret;
}

int_ main()
{
	freopen("banana.in","r",stdin);
	freopen("banana.out","w",stdout);
	scanf("%lld",&d);
	while(d--){
		ans=0;
		scanf("%lld %lld",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		sort(a+1,a+1+n);
		ans=count_(1,1);
		printf("%lld\n",ans);
    }
    return 0;
}
/*
3
3 3
1 1 3
3 6
2 3 6
3 5
1 5 1
*/
