#include<stdio.h>
#include<algorithm>
#define maxn 100010
using namespace std;
int time,a[maxn],b[maxn],c[maxn],d[maxn],dp[maxn];//攻击间隔   技能花费  群众伤害  花费 
int main(){
	freopen("sword.in","r",stdin);
	freopen("sword.out","w",stdout);
	int n,m,k,x,s;
	scanf("%d%d%d%d%d",&n,&m,&k,&x,&s);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=k;i++)
		scanf("%d",&c[i]);
	for(int i=1;i<=k;i++)
		scanf("%d",&d[i]);
	for(int i=1;i<=k;i++){
		for(int j=s;j>=0;j--){
			dp[j]=max(dp[j],dp[j-d[i]]+c[i]);
		}
	}
	time=n*x;
	int S=s,X=x,N=n;
	for(int x=1;x<=m;x++){
		if(S>=b[x]) S-=b[x];
		else continue;
		X=a[x];
		for(int i=1;i<=k;i++){
			for(int j=S;j>=0;j--){
				dp[j]=max(dp[j],dp[j-d[i]]+c[i]);
			}
		}
		N-=dp[S];
		time=min(time,N*X);
	}
	printf("%d",time);
	return 0;
}
