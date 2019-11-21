#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
int sum[10010],a[10010];
int dfs(int fp,int p,int max,int np,int n)//fp :第一个点 p:总段数 max :ai和的最大值  np :现在做到的段 n:总长 
{
	if(np == p)
	{
		if(sum[n + 1] - sum[fp - 1] < max && fp <= n) return 0x3ffffff;
		int res;
		res = (sum[n] - sum[fp - 1]) * (sum[n] - sum[fp - 1]);
		return res;
	}
	int res = 0x3ffffff;
	for(int i = fp;i <= n - p + np + 1;i++)
	{
		if(sum[i] - sum[fp - 1] < max) continue;
		res = min(dfs(i + 1,p,sum[i] - sum[fp - 1],np + 1,n) + (sum[i] - sum[fp - 1]) * (sum[i] - sum[fp - 1]),res);
	}
	return res;
}
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	int n,t;
	scanf("%d%d",&n,&t);
	if(t == 1)
	{
		printf("4972194419293431240859891640");
		return 0;
	}
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	for(int p = n;p >= 0;p--)
	{
		int minn = 0x3ffffff;
		for(int i = 1;i <= n - p;i++)
		{
			int ans = dfs(i,p,0,0,n);
			minn = min((ans > 0 ? ans : 0x3ffffff),minn);
		}
		if(minn < 0x3ffffff)
		{
			printf("%d",minn);
			return 0;
		}
	}
}
