#include<stdio.h>
#include<algorithm>
using namespace std;
#define maxn 110
int dp[100010],attr[2][maxn],w[maxn],v[maxn],ip[maxn];
int main(){
	freopen("budget.in","r",stdin);
	freopen("budget.out","w",stdout);
	int W,m;
	scanf("%d%d",&W,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&w[i],&v[i],&ip[i]);
		v[i]*=w[i];
		if(ip[i]!=0){
			if(attr[1][ip[i]]!=0) attr[2][ip[i]]=i;
			else attr[1][ip[i]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		if(ip[i]!=0) continue ;
		for(int j=W;j>0;j--){
			if(j>=w[i]) dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
			if(j>=w[i]+w[attr[1][i]]) dp[j]=max(dp[j],dp[j-w[i]-w[attr[1][i]]]+v[i]+v[attr[1][i]]);
			if(j>=w[i]+w[attr[2][i]]) dp[j]=max(dp[j],dp[j-w[i]-w[attr[2][i]]]+v[i]+v[attr[2][i]]);
			if(j>=w[i]+w[attr[1][i]]+w[attr[2][i]])
				dp[j]=max(dp[j],dp[j-w[i]-w[attr[1][i]]-w[attr[2][i]]]+v[i]+v[attr[1][i]]+v[attr[2][i]]);
		}
	}
	printf("%d\n",dp[W]);
	return 0;
}
