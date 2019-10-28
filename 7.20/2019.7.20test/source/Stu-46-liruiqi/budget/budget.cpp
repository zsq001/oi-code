#include<cstdio>
using namespace std;
#define maxn 1010
int n,m;
int dp[maxn][maxn];
struct bag{
	int v;
	int imp;
	int belong;
	int num;
}a[100010];
int main()
{
	freopen("budget.in" ,"r",stdin);
	freopen("budget.out ","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
	scanf("%d %d %d",&a[i].v,&a[i].imp,&a[i].belong);
	a[i].num=i;
	}
	for(int i=1;i<=m;i++)
		for (int j=1;j<=m;j++)
		{
			dp[i][j]=a[i].v;
		}
		for(int i=1;i<=m;i++)
		{
			dp[i][i]=0;
		}
	for(int k=5;k>=0;k++)
	{
		for(int i=1;i<=m;i++)
		 {
	 		for(int j=1;j<=m;j++)
	 		dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]+a[i].v)
	 		ans+=dp[i][j];
		 }
	}
	printf("%d",ans);
	return 0;
}
