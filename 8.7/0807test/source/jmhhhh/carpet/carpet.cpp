#include<cstdio>
#include<algorithm>
using namespace std;
typedef int int_;
#define int long long


int n,m;
int p[2050][2050];

int_ main()
{
	freopen("carpet.in","r",stdin);
	freopen("carpet.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=m;i++){
		int tp1,tp2,tp3,tp4;
		scanf("%lld %lld %lld %lld",&tp1,&tp2,&tp3,&tp4);
		p[tp1][tp2]++;
		p[tp1][tp4+1]--;
		p[tp3+1][tp4+1]++;
		p[tp3+1][tp2]--;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			p[i][j]+=p[i][j-1];
		}
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++){
			p[i][j]+=p[i-1][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%lld ",p[i][j]);
		}
		printf("\n");
	}
	return 0;
}
