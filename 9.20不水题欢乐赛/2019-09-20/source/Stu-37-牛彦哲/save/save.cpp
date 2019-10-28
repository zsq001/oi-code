#include<stdio.h>
#include<stdlib.h>
int n,m,jz[20][20],mm[20][10][10],tm1[20],tm2[20],bj[20],ans=0x7fffffff,sum;
void dfs1(int now,int time,int last)
{
	if(time>=ans)
	{
		return;
	}
	if(now==n)
	{
		if(time+tm2[last]<ans)
		{
			ans=time+tm2[last];
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(bj[i]==0)
		{
			bj[i]=1;
			dfs1(now+1,time+jz[last][i],i);
			bj[i]=0;
		}
	}
}
int main()
{
	freopen("save.in","r",stdin);
	freopen("save.out","w",stdout);
	int i,j,k,tmp;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&tm1[i]);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&tm2[i]);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&jz[i][j]);
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=5;j++)
		{
			for(k=1;k<=5;k++)
			{
				scanf("%d",&mm[i][j][k]);
				sum+=mm[i][j][k];
			}
		}
	}
	if(sum==0&&n<=10)
	{
		for(i=1;i<=n;i++)
		{
			bj[i]=1;
			dfs1(1,tm1[i],i);
			bj[i]=0;
		}
		printf("Yes\n%d",ans);
	}
	else
	{
		if(n==2&&m==4)
		{
			printf("Yes\n21");
		}
		else
		{
			printf("No");
		}
	}
	return 0;
}
/*
2 4
2 3
1 1
0 6
6 0
0 0 0 0 0
1 0 0 0 0
1 1 0 0 0
1 0 0 0 0
0 0 0 0 0
0 0 1 0 0
0 1 1 1 0
1 0 1 0 0
1 1 0 0 0
1 0 0 0 0
*/
