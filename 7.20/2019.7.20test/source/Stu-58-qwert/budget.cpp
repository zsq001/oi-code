#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int val[100],cost[100],atc[100][3],dp[100001],f[100];
int main(){
	freopen("budget.in","r",stdin);
	freopen("budget.out","w",stdout);
	int money,goal;
	scanf("%d%d",&money,&goal);
	int op;
	for(int i=1;i<=goal;i++){
		scanf("%d%d%d",&cost[i],&val[i],&op);
		val[i]*=cost[i];
		if(op){
			if(atc[op][0])atc[op][1]=i;
			else atc[op][0]=i;
		}
		else f[i]=1;
	}
	for(int i=1;i<=goal;i++){
		if(!f[i])continue;
		for(int j=money;j;j--){
			if(cost[i]<j)dp[j]=max(dp[j],dp[j-cost[i]]+val[i]);
			if(atc[i][0]&&cost[atc[i][0]]+cost[i]<j)
				dp[j]=max(dp[j],dp[j-cost[atc[i][0]]-cost[i]]+val[i]+val[atc[i][0]]);
			if(atc[i][1]&&cost[atc[i][1]]+cost[i]<j)
				dp[j]=max(dp[j],dp[j-cost[atc[i][1]]-cost[i]]+val[i]+val[atc[i][1]]);
			if(atc[i][0]&&atc[i][1]&&cost[atc[i][0]]+cost[atc[i][1]]+cost[i]<j)
				dp[j]=max(dp[j],dp[j-cost[atc[i][0]]-cost[atc[i][1]]-cost[i]]+val[i]+val[atc[i][0]]+val[atc[i][1]]);
		}
	}
	printf("%d",dp[money]);
	return 0;
}
