#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
double type_[10010];
double a[10010];
double dp[1010][1010];
double dp1[1010][1010];
double p[1010][1010],p1[1010][1010];
int n,w/*初始魔力值*/;
double k,c;/*当前魔力值*/;
int main(){
	freopen("coal.in","r",stdin);
	freopen("coal.out","w",stdout);
	scanf("%d %lf %lf %d",&n,&k,&c,&w);
	for(int j=1;j<=n;++j){
		scanf("%lf %lf",&type_[j],&a[j]);
	}
	p[1][1]=w;//1则加上a[i]*p,魔力值-k%,2则可以花费a[i]*p,魔力值加c%
	if(type_[1]==1){
		dp[1][1]=a[1]*p[1][1];
		p[1][1]=(1-k/100)*p[1][1];
	}
	if(type_[1]==2){
		dp[1][1]=-a[1]*p[1][1];
		p[1][1]=(1+c/100)*p[1][1];
	}
	dp1[1][1]=0;
	p1[1][1]=10;
	for(int i=2;i<=n;++i){
		for(int j=1;j<=pow(2,(i-1));++j){
			if(j%2==0){
				dp[i][j]=dp[i-1][j/2]+0;
				
			}
			if(j%2!=0){
				if(type_[i]==1){
					dp[i][j]=dp[i-1][(j+1)/2]+a[i]*p[i-1][(j+1)/2];
					p[i][j]=(1-k/100)*p[i-1][(j+1)/2];
				}
				if(type_[i]==2){
					if(dp[i-1][(j+1)/2]<a[i]*p[i-1][(j+1)/2])
					dp[i][j]=dp[i-1][(j+1)/2]+0;
					else{
						dp[i][j]=dp[i-1][(j+1)/2]-a[i]*p[i-1][(j+1)/2];
					p[i][j]=(1+c/100)*p[i-1][(j+1)/2];
					}
				}
			}
		}
	}
	for(int i=2;i<=n;++i){
		for(int j=1;j<=pow(2,(i-1));++j){
			if(j%2==0){
				dp1[i][j]=dp1[i-1][j/2]+0;
				
			}
			if(j%2!=0){
				if(type_[i]==1){
					dp1[i][j]=dp1[i-1][(j+1)/2]+a[i]*p1[i-1][(j+1)/2];
					p1[i][j]=(1-k/100)*p1[i-1][(j+1)/2];
				}
				if(type_[i]==2){
					if(dp1[i-1][(j+1)/2]<a[i]*p1[i-1][(j+1)/2]){
						dp1[i][j]=dp1[i-1][(j+1)/2]+0;
					}
					else{
						dp1[i][j]=dp1[i-1][(j+1)/2]-a[i]*p1[i-1][(j+1)/2];
					p1[i][j]=(1+c/100)*p1[i-1][(j+1)/2];
					}	
				}
			}
		}
	}
	double max1=0,max2=0;
	for(int q=1;q<=pow(2,(n-1));++q){
		max1=max(dp[n][q],max1);
		max2=max(dp1[n][q],max2);
	}
	double ans;
	ans=max(max1,max2);
	printf("%.2lf",ans);
	return 0;
}
