#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#define ll long long
#define maxn 200010
using namespace std;
int dp[1010][1010];
int main(){
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	dp[1][1]=1;
	for(int i=1;i<=300;i++){
		for(int j=1;j<=i;j++){
			if(i==1&&j==1) continue;
			dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
		}
	}
	int n1,n2,k1,k2;
	scanf("%d%d%d%d",&n1,&n2,&k1,&k2);
	if(fabs(n1-n2)>k1||fabs(n1-n2)>k2){
		printf("0");
		return 0;
	}
	int ans=dp[n1+n2+1][n1+1];
	if(n1>k1) ans-=dp[n1+n2-(k1+1)+1+1][1+1]*floor(n1%k1);
	if(n2>k2) ans-=dp[n1+n2-(k2+1)+1+1][1+1]*floor(n2%k2);
	printf("%d\n",ans-2);
	return 0;
}
