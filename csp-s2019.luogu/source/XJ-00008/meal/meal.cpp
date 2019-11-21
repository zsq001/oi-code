#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
const int mod=998244353;
#define ll long long

int n,m,flag;
ll dp[105][2005],a[105][2005];

int main(){
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%lld",&a[i][j]);
		}
	}
	for(int i=1;i<=n;++i) dp[i][1]=0;
	for(int i=1;i<=m;++i) dp[1][i]=0;
	for(int i=1;i<=n;++i){
		for(int j=i;j<=m;++j){
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]+a[i][j]);
		}
	}
	cout<<flag<<endl;
	printf("%lld",dp[n][m]%mod);
	fclose(stdin);
	fclose(stdout);
}

/*

2 3
1 0 1
0 1 1

3 3
1 2 3
4 5 0
6 0 0

5 5
1 0 0 1 1
0 1 0 1 0
1 1 1 1 0
1 0 1 0 1
0 1 1 0 1
*/
