#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010
using namespace std;

int n,w;
struct node
{
	int op,a;
}ca[maxn];
double p,k,c,dp[maxn];

int main()
{
	freopen("coal.in","r",stdin);
	freopen("coal.out","w",stdout);
	scanf("%d%lf%lf%d",&n,&k,&c,&w);
	k=(100-k)/100.0;c=(100+c)/(100.0);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&ca[i].op,&ca[i].a);
		ca[i].a=ca[i].a*(ca[i].op==1?1:-1);
	}
	dp[n+1]=0;//最优情况下到终点一滴不剩 
	for(int i=n;i>=1;i--)
	{
		dp[i]=max(dp[i+1],dp[i+1]*(ca[i].op==1?k:c)+ca[i].a);
	}//倒着走回去 
//	p=(double)w;
	printf("%.2lf",dp[1]*w);
	return 0;
}
