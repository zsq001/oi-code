#include<cstdio>
#include<algorithm>
#include<iostream>
#define N 100010
using namespace std;
int n,k,c,w,maxx;
int pf(){
	while (n--){
		int type,val;
		scanf("%d%d",&type,&val);
		if(type==1&&maxx<val){maxx=val;}
	}
	printf("%.2f",w*maxx*1.0);
	return 0;
}
double dp[N][3],p0[N],p1[N];
int main(){
	freopen("coal.in","r",stdin);
	freopen("coal.out","w",stdout);
	scanf("%d%d%d%d",&n,&k,&c,&w);
	if(k==100){pf();return 0;}
	p1[0]=p0[0]=w;
	dp[0][0]=dp[0][1]=0;
	for(int i=1;i<=n;i++){
		int type,val;
		scanf("%d%d",&type,&val);
		if(dp[i-1][0]>dp[i-1][1]){
			dp[i][0]=dp[i-1][0];
			p0[i]=p0[i-1];
		}
		else {
			dp[i][0]=dp[i-1][1];
			p0[i]=p1[i-1];
		}//dp[i][0]µÄ¼Ì³Ð 
		if(type==1){
			if( (dp[i-1][0]+p0[i-1]*val) > (dp[i-1][1]+p1[i-1]*val)){
				dp[i][1]=dp[i-1][0]+p0[i-1]*val;
				p1[i]=p0[i-1]-p0[i-1]*k*0.01;
			}
			else {
				dp[i][1]=dp[i-1][1]+p1[i-1]*val;
				p1[i]=p1[i-1]-p1[i-1]*k*0.01;
			}
		}
		if(type==2){
			if( (dp[i-1][0]-p0[i-1]*val) > (dp[i-1][1]-p1[i-1]*val)){
				dp[i][1]=dp[i-1][0]-p0[i-1]*val;
				p1[i]=p0[i-1]+p0[i-1]*c*0.01;
			}
			else {
				dp[i][1]=dp[i-1][1]-p1[i-1]*val;
				p1[i]=p1[i-1]+p1[i-1]*c*0.01;
			}
		}
	}
	printf("%.2f",max(dp[n][0],dp[n][1]));
	return 0;
}
/*
5 50 50 10
1 10
1 20
2 10
2 20
1 30
*/
