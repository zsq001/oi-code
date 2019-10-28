#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define maxn 1000010
typedef int int_;
#define int long long
int n,m,p,q,col[maxn];
int_ main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&p,&q);
	for(int i=1;i<=m;i++){
		int l=(i*p+q)%n+1;
		int r=(i*q+p)%n+1;
		for(int j=l;j<=r;j++) col[j]=i;
	}
	for(int i=1;i<=n;i++) printf("%lld\n",col[i]);
	return 0;
}
