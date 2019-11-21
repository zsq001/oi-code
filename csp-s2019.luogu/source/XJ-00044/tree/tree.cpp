#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
bool mp[100][100];
long long num[100],n,ans = 0x7fffffff7fffffff,pos[100];
void dfs(int last)
{
	if(last == 1)
	{
		long long val = 0;
		for(int i = 1;i <= n;i++)
		{
			val = val * 10 + pos[i] - 1;
		}
		ans = min(val,ans);
		return ;
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i + 1;j <= n;j++)
		{
			if(mp[i][j])
			{
				mp[i][j] = 0;
				mp[j][i] = 0;
				swap(num[i],num[j]);
				swap(pos[num[i]],pos[num[j]]);
				dfs(last - 1);
				mp[i][j] = 1;
				mp[j][i] = 1;
				swap(num[i],num[j]);
				swap(pos[num[i]],pos[num[j]]);
			}
		}
	}
	return ;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(num,0,sizeof(num));
		memset(mp,0,sizeof(mp));
		scanf("%lld",&n);
		ans = 0x7fffffff7fffffff;
		for(int i = 1;i <= n;i++)
		{
			int x;
			scanf("%d",&x);
			num[x] = i;
			pos[i] = x;
		}
		for(int i = 1;i < n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			mp[x][y] = 1;
			mp[y][x] = 1;
		}
		dfs(n);
		int output[10010];
		for(int i = 0;i < n;i++)
		{
			output[n - i] = ans % 10 + 1;
			ans /= 10;
		}
		for(int i = 1;i <= n;i++)
			printf("%d ",output[i]);
		printf("\n");
	}
	return 0;
}
