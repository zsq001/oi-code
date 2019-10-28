#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

long long maze[1010][1010];
long long dp[1010]={0};
int k,n;
bool cmp(int x,int y)
{
	return x<y;
}

int main()
{
	freopen("tree.in","r",stdin);	
	freopen("tree.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			maze[i][j]=100000000;
		}
			
	for(int i=1;i<=n-1;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		maze[x][y]=z;
		maze[y][x]=z;
	 }
	for(int i=1;i<=n;i++)
	{
		for(int e=1;e<=n;e++)
		{
			for(int r=1;r<=n;r++)
			{
				maze[e][r]=min(maze[e][r],maze[e][i]+maze[i][r]);
			}
		}
	}
	for(int i=1;i<=n-1;i++)
	{
		dp[i]=maze[i][i+1];
	}
	long long ans=dp[k+1];
	for(int i=k+1;i<=n-1;i++)
	{
		ans=min(ans,dp[i]-dp[i-k]);
	}
	printf("%d",ans);
	fclose(stdin);	
	fclose(stdout);	
	return 0;
}
/*
10 7
1 2 1
2 3 1
3 4 1
2 5 1
1 6 1
5 7 1
4 8 1
3 9 1
8 10 1
*/

