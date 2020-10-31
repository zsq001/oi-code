#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;
ll n,m,k;
ll sq[1100][1100];
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	memset(sq,0,sizeof (sq));
	ll x,y,z;
	for(int i=1;i<=k;++i){
		scanf("%lld %lld %lld",&x,&y,&z);
		ll j=1;
		if(x==1){
			while(j<=m){
				sq[y][j]=z;
				++j;
			}
		}
		if(x==2){
			while(j<=n){
				sq[j][y]=z;
				++j;
			}
		}
	}
	for(int i=1;i<=n;++i){
		puts(" ");
		for(int j=1;j<=m;++j)
			printf("%lld ",sq[i][j]);
	}
	
			return 0;
}
