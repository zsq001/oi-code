#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
typedef int int_;
#define int long long
#define inf 1000000009

int n,m;
int c[55];
int ansl=inf,ansr;

bool check(int now){
	int tp=m;
	for(int i=1;i<=n;i++){
		if((c[i]>=now) || tp<0) break;
		tp-=(now-c[i]);
	}
	if(tp>=0) return true;
	else return false;
}


int_ main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		ansl=min(ansl,c[i]);
		ansr=max(ansr,c[i]);
	}
	sort(c+1,c+1+n);
	while(ansl<=ansr){
		int mid=(ansl+ansr)>>1;
		if(check(mid)) ansl=mid+1;
		else ansr=mid-1;
	}
	printf("%lld",ansr);
	return 0;
}
