#include<stdio.h>
#include<stdlib.h>
int n,wl,ans[10000][305],sum[50000],min=100000000,max=0,count,a[305];
int isok()
{
	int i,j,k,t;
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			t=a[i]+a[j];
			for(k=1;k<=wl;k++)
			{
				if(sum[k]==t)
				{
					break;
				}
			}
			if(k>wl)
			{
				return 0;
			}
		}
	}
	return 1;
}
void dfs(int now,int lst)
{
	int i,j;
	if(now==1)
	{
		for(i=min/2;i>=lst;i--)
		{
			a[now]=i;
			dfs(now+1,i+1);
		}
		return;
	}
	if(now>n)
	{
		if(isok())
		{
			count++;
			for(i=1;i<=n;i++)
			{
				ans[count][i]=a[i];
			}
		}
		return;
	}
	if(lst>=max)
	{
		return;
	}
	for(i=lst;i<=max;i++)
	{
		a[now]=i;
		dfs(now+1,i+1);
	}
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int i,j;
	scanf("%d",&n);
	wl=n*(n-1)/2;
	for(i=1;i<=wl;i++)
	{
		scanf("%d",&sum[i]);
		if(sum[i]>max)
		{
			max=sum[i];
		}
		if(sum[i]<min)
		{
			min=sum[i];
		}
	}
	dfs(1,1);
	printf("%d\n",count);
	for(i=1;i<=count;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
