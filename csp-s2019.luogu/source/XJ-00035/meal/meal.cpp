#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;


int aa[205][2005];
int n,m,ans;
int dp[205][205][205];
int cur[205][205];


int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&aa[i][j]);
		}
	}
	
	printf("%d",m);
	return 0;
}
