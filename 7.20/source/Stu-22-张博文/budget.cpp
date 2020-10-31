#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#define ll long long
#define maxn 100010
using namespace std;
struct Note{
	int w,val,q;
}a[maxn];
int dp[32010][66],bl[maxn][4],cnt;
int main(){
	freopen("budget.in","r",stdin);
	freopen("budget.out","w",stdout);
	int n,m;
	int minw=maxn;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].w ,&a[i].val ,&a[i].q );
		if(a[i].q!=0){
			bl[a[i].q][++cnt]=i;
		}
		minw=min(minw,a[i].w);
	}
	for(int i=minw;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[j].q==0) continue;
			if(bl[a[j].q][1]==j){
				if(a[j].w+a[a[j].q].w<=i){
					dp[i][j]=max(dp[i][j],dp[i-a[a[j].q].w-a[j].w][j-1]+a[a[j].q].val*a[a[j].q].w+a[j].val*a[j].w);
				}
				if(a[a[j].q].w+a[bl[a[j].q][2]].w<=i){
					dp[i][j]=max(dp[i][j],dp[i-a[a[j].q].w-a[bl[a[j].q][2]].w][j-1]+a[a[j].q].val*a[a[j].q].w+a[bl[a[j].q][2]].val*a[bl[a[j].q][2]].w);
				}
				if(a[j].w+a[a[j].q].w+a[bl[a[j].q][2]].w<=i){
					dp[i][j]=max(dp[i][j],dp[i-a[a[j].q].w-a[j].w-a[bl[a[j].q][2]].w][j-1]+a[a[j].q].val*a[a[j].q].w+a[j].val*a[j].w+a[bl[a[j].q][2]].val*a[bl[a[j].q][2]].w);	
				}
			}
			else{
				if(a[j].w+a[a[j].q].w<=i){
					dp[i][j]=max(dp[i][j],dp[i-a[a[j].q].w-a[j].w][j-1]+a[a[j].q].val*a[a[j].q].w+a[j].val*a[j].w);
				}
				if(a[a[j].q].w+a[bl[a[j].q][1]].w<=i){
					dp[i][j]=max(dp[i][j],dp[i-a[a[j].q].w-a[bl[a[j].q][1]].w][j-1]+a[a[j].q].val*a[a[j].q].w+a[bl[a[j].q][1]].val*a[bl[a[j].q][1]].w);
				}
				if(a[j].w+a[a[j].q].w+a[bl[a[j].q][1]].w<=i){
					dp[i][j]=max(dp[i][j],dp[i-a[a[j].q].w-a[j].w-a[bl[a[j].q][1]].w][j-1]+a[a[j].q].val*a[a[j].q].w+a[j].val*a[j].w+a[bl[a[j].q][1]].val*a[bl[a[j].q][1]].w);	
				}
			}
		}
	}
	printf("%d",dp[n][m]);
	return 0;
}
