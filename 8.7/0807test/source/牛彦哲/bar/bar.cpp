#include<stdio.h>
#include<stdlib.h>
int T,n,yn[1010][1010],dan,rox[2010],roy[2010];
int dfs(int x,int y,int tm)
{
	if(yn[x][y]==1)
	{
		return 0;
	}
	if(x==n&&y==n)
	{
		return 1;
	}
	if(tm<=dan)
	{
		yn[rox[tm]][roy[tm]]=1;
	}
	if(x+1<=n&&dfs(x+1,y,tm+1)==1)
	{
		yn[rox[tm]][roy[tm]]=0;
		return 1;
	}
	if(y+1<=n&&dfs(x,y+1,tm+1)==1)
	{
		yn[rox[tm]][roy[tm]]=0;
		return 1;
	}
	if(x-1>0&&dfs(x-1,y,tm+1)==1)
	{
		yn[rox[tm]][roy[tm]]=0;
		return 1;
	}
	if(y-1>0&&dfs(x,y-1,tm+1)==1)
	{
		yn[rox[tm]][roy[tm]]=0;
		return 1;
	}
	yn[rox[tm]][roy[tm]]=0;
	return 0;
}
int main()
{
	freopen("bar.in","r",stdin);
	freopen("bar.out","w",stdout);
	int i,j;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d",&n);
		dan=2*n-2;
		for(j=1;j<=dan;j++)
		{
			scanf("%d%d",&rox[j],&roy[j]);
		}
		if(n==1||dfs(1,1,0)==1)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
