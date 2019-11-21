#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define mod 998244353
using namespace std;
long long maxx,n,m,a[101][2001],v[101],vv[2001],ans;
long long Search(long long x,long long now){
	if(x==0) return 1;
	long long cnt=0;
	for(int i=now;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]&&v[j]<maxx&&!vv[i]){
				vv[i]=1;
				v[j]++;
				cnt+=(a[i][j]*(Search(x-1,i+1)%mod))%mod;
				vv[i]=0;
				v[j]--;
			}
	return cnt;
}
int main(){
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%lld",&a[i][j]);
		}
	for(int i=2;i<=n;i++){
		maxx=i/2;
		ans+=Search(i,1)%mod;
	}
	printf("%lld",ans%mod);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
