#include<cstdio>
#include<algorithm>
using namespace std;

struct node{
	int val,cost;
};
node a[2][200050];
int ans,dp[200050];
int tp[2];
int n,k,x,s,m;

bool cmp(node a,node b){
	return a.cost<b.cost;
}

int main()
{
	freopen("sword.in","r",stdin);
	freopen("sword.out","w",stdout);
	
	scanf("%d %d %d",&n,&m,&k);
	scanf("%d %d",&x,&s);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[0][i].val);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&a[0][i].cost);
		if(a[0][i].cost <= s) tp[0]++;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&a[1][i].val);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&a[1][i].cost);
		if(a[1][i].cost <= s) tp[1]++;
	}
	sort(a[1]+1,a[1]+1+k,cmp);
	sort(a[0]+1,a[0]+1+m,cmp);
	for(int i=0;i<=s;i++){
		dp[i]=n;
	}
	int i=1;
	for(int j=s;j>=0;j--){
		for(int q=1;q<=tp[i];q++){
			if(j-a[i][q].cost >= 0)
			dp[j]=min(dp[j-a[i][q].cost]-a[i][q].val,dp[j]);			
		}
	}
	i=0;
	for(int j=s;j>=0;j--){
		for(int q=1;q<=tp[i];q++){
			if(j-a[i][q].cost >= 0)
			dp[j]=min(dp[j-a[i][q].cost]*a[i][q].val/x,dp[j]);			
		}
	}
	ans=dp[s]*x;
	printf("%d",ans);
	return 0;	
}
