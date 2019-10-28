#include <cstdio>
#include <algorithm>
typedef int int_;
#define int long long
#define maxn 10010
const int Mod=1e9+7;
using namespace std;

int an[maxn],fib[100010];
int fibb(int x){
	if(fib[x] != 0) return fib[x];
	if(x < 100000 ) return fib[x]=(fibb(x-1)%Mod+fibb(x-2)%Mod)%Mod;
	else return (fibb(x-1)%Mod+fibb(x-2)%Mod)%Mod;
}
int_ main() {
	int n,m;
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	fib[1]=1;
	fib[2]=1;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&an[i]);
	}
	while (m--) {
		int l,r,z,op;
		scanf("%lld%lld%lld",&op,&l,&r);
		if (op == 1) {
			scanf("%lld",&z);
			for(int i=l;i<=r;i++){
				an[i]+=z;
			}
		} else {
			int ret=0;
			for(int i=l;i<=r;i++){
				ret+=fibb(an[i]);
			}
			printf("%lld\n",ret);
		}
	}
	return 0;
}
