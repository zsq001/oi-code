#include<cstdio>
#include<algorithm>
#include<iostream>
#define maxn 110
using namespace std;
int w[maxn],val[maxn],blg[maxn],dp[maxn];
int att[maxn][5];
int main()
{
	int n,m;
	freopen("budget.in","r",stdin);
	freopen("budget.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&w[i],&val[i],&blg[i]);
		val[i]*=w[i];
		if(blg[i]!=0){
			if(att[blg[i]][1]==0)att[blg[i]][1]=i;
			else att[blg[i]][2]=i;
		}
	}
	for(int i=1;i<=m;i++){
		if(blg[i]!=0)continue;
		for(int k=n;k>=0;k--){
			if(k>=w[i])dp[k]=max(dp[k],dp[k-w[i]]+val[i]);
			if(k>=w[i]+w[att[i][1]])dp[k]=max(dp[k],dp[k-w[i]-w[att[i][1]]]+val[i]+val[att[i][1]]);
			if(k>=w[i]+w[att[i][2]])dp[k]=max(dp[k],dp[k-w[i]-w[att[i][2]]]+val[i]+val[att[i][2]]);
			if(k>=w[i]+w[att[i][2]]+w[att[i][1]])dp[k]=max(dp[k],dp[k-w[i]-w[att[i][1]]-w[att[i][2]]]+val[i]+val[att[i][2]]+val[att[i][1]]);
		}
	}
	printf("%d",dp[n]);
	return 0;
}
