#include<bits/stdc++.h>
using namespace std;
int w[70],b[70],a[70][2],val[70],dp[40040];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&w[i],&val[i],&b[i]);
		val[i]*=w[i];
		if(b[i]!=0){
			if(a[b[i]][1]==0) a[b[i]][1]=i;
			else a[b[i]][2]=i;
		}
	}
	for(int i=1;i<=m;++i){
		if(b[i]!=0) continue;
		for(int k=n;k>=0;--k){
			if(k>=w[i]) dp[k]=max(dp[k],dp[k-w[i]]+val[i]);
			if(k>=w[i]+w[a[i][2]]) dp[k]=max(dp[k],dp[k-w[i]-w[a[i][2]]]+val[i]+val[a[i][2]]);
			if(k>=w[i]+w[a[i][1]]) dp[k]=max(dp[k],dp[k-w[i]-w[a[i][1]]]+val[i]+val[a[i][1]]);
			if(k>=w[i]+w[a[i][1]]+w[a[i][2]]) dp[k]=max(dp[k],dp[k-w[i]-w[a[i][1]]-w[a[i][2]]]+val[i]+val[a[i][1]]+val[a[i][2]]);
		}
	}
	printf("%d",dp[n]);
}
