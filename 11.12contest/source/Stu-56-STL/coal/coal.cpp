#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
int n,type[maxn];
double k,c,w,a[maxn],dp[maxn];

int main(){
	freopen("coal.in","r",stdin);
	freopen("coal.out","w",stdout);
	cin>>n>>k>>c>>w;
	memset(dp,0,sizeof(dp));
	k/=100;c/=100;
	for(int i=1;i<=n;++i){
		cin>>type[i]>>a[i];
	}
	double p=w;
	for(int i=1;i<=n;++i){
		if(p){
			if(type[i]==1){//煤矿 
//				dp[i]=max(dp[i],dp[i-1])+p*a[i];
//				p=p*(1-k);
			}
			else if(type[i]==2){//补给站 
				dp[i]=min(dp[i],dp[i-1])-p*a[i];
				p=p*(1+c);
			}	
		}
	}
	printf("%.2lf\n",dp[n]);
	return 0;//保留两位小数 
}

/*
5 50 50 10
1 10
1 20
2 10
2 20
1 30
*/
