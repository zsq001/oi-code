#include<bits/stdc++.h>
using namespace std;

int dp[65][30005][5],w[65][3],v[65][3];
int W,n;
int main(){
	freopen("budget.in","r",stdin);
	freopen("budget.out","w",stdout);
	scanf("%d%d",&W,&n);
	for(int i=1;i<=n;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(c){
			if(w[c][1]){
				v[c][2]=a*b;
				w[c][2]=a;
			}
			else {
				v[c][1]=a*b;
				w[c][1]=a;
			}
		}
		else {
			v[i][0]=a*b;
			w[i][0]=a;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=W;j++)
			for(int k=0;k<5;k++){
				dp[i][j][0]=max(dp[i][j][0],dp[i-1][j][k]);
				if(j-w[i][0]>=0) dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-w[i][0]][1]+v[i][0]);
				if(j-w[i][0]-w[i][1]>=0) dp[i][j][2]=max(dp[i][j][2],dp[i-1][j-w[i][0]-w[i][1]][2]+v[i][0]+v[i][1]);
				if(j-w[i][0]-w[i][2]>=0) dp[i][j][3]=max(dp[i][j][3],dp[i-1][j-w[i][0]-w[i][2]][3]+v[i][0]+v[i][2]);
				if(j-w[i][0]-w[i][1]-w[i][2]>=0) dp[i][j][4]=max(dp[i][j][4],dp[i-1][j-w[i][0]-w[i][1]-w[i][2]][4]+v[i][0]+v[i][1]+v[i][2]);
			}
	int ans=0;
	for(int i=0;i<5;i++){
		ans=max(ans,dp[n][W][i]);
	}
	printf("%d",ans);
	return 0;
}
