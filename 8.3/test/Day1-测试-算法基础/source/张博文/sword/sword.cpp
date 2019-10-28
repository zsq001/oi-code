#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define maxn 100010
typedef int int_;
#define int long long
using namespace std;
int n,m,ans,k,x,s,a[maxn],b[maxn],c[maxn],d[maxn];
int_ main(){
	freopen("sword.in","r",stdin);
	freopen("sword.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	scanf("%lld%lld",&x,&s);
	for(int i=1;i<=m;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++) scanf("%lld",&b[i]);
	for(int i=1;i<=k;i++) scanf("%lld",&c[i]);
	for(int i=1;i<=k;i++) scanf("%lld",&d[i]);
	ans=n*x;
	for(int j=1;j<=m;j++){
		for(int q=1;q<=k;q++){
			if(s>=b[j]){
				ans=min(ans,n*a[j]);
			}
			if(s>=d[q]+b[j]){
				ans=min(ans,(n-c[q])*a[j]);
			}
			else if(s>=d[q]){
				ans=min(ans,(n-c[q])*x);
			}
		}
	}
	printf("%lld",ans);
}
