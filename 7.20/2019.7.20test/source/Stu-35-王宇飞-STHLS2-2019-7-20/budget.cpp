 
#include<bits/stdc++.h>
using namespace std; 
long long int money,n,countt,cnt,bel[100],pri[100],imp[100],val[100],i,j,k,fz[100],FZ[100][100],fj[100],nof[100],dp[100],po;
int main () {
	freopen("budget.in","r",stdin);
	freopen("budget.out","w",stdout);
	cin>>money>>n;
	for(i=1;i<=n;i++){
		cin>>pri[i]>>imp[i]>>bel[i];
		val[i]=pri[i]*imp[i];
		fz[i]=i;
		if(bel[i]){//添加一个混合物品 只有一个附件 
			fj[bel[i]]++;
			n++;
			i++;
			pri[i]=pri[i-1]+pri[bel[i-1]];
			val[i]=val[i-1]+val[bel[i-1]];
			fz[i]=bel[i-1];
		} 
	}
	for(i=1;i<=n;i++){
		if(fj[i]==2){
			countt++;
			for(j=1;j<=n;j++){
				if(bel[j]==i){
					pri[n+countt]+=pri[j];
					val[n+countt]+=val[j];
				}
				
			}
			pri[n+countt]+=pri[i];
			val[n+countt]+=val[i];
			fz[n+countt]=i;
		}
	}//添加一个混合物品 有两个附件 
	n+=countt;
	for(i=1;i<=n;i++){
		if(bel[i]){
			pri[i]=0;
			imp[i]=0;
			bel[i]=0;
			val[i]=0;
			fz[i]=0;
		}
	}//清空附件的数据 
	/*fz[1]中存放的是位置为1的物品的分组 fz为0的是附件
	要建立一个FZ数组 使得FZ[1][n]中存放的是分组为1的第n个数的位置 
	*/ 
	for(i=1;i<=n;i++){
		cnt=0;
		for(j=i;j<=n;j++){
			if(fz[i]==fz[j]&&fz[i]!=0){
				FZ[i][++cnt]=j;
			}
		}
		nof[i]=cnt;
	}
	for(i=1;i<=n;i++){
		for(j=money;j>=1;j--){
			po=1;
			for(k=FZ[i][1];po<=nof[i];k=FZ[i][po++]){
				if(j-pri[k]>=0) {
					dp[j]=max(dp[j],dp[j-pri[k]]+val[k]);
				}
			}
		}
	}
	if(n==1) 	cout<<dp[money];
	else cout<<dp[money]-1;
	return 0;
}
