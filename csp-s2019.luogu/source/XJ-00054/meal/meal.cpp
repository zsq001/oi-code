#include<stdio.h>
#include<stdlib.h>
#define mo 998244353
int a[105][2005],b[2005],n,m,ans,flag,lj,lc=1;
void dfs2(int st,int kmx,int alr)
{
	int i;
	if(st>n)
	{
		if(alr>1)
		{
			int t=alr/2;
			for(i=1;i<=m;i++)
			{
				if(b[i]>t)
				{
					break;
				}
			}
			if(i>m)
			{
				ans++;
				ans%=mo;
			}
		}
		return;
	}
	dfs2(st+1,kmx,alr);
	for(i=1;i<=m;i++)
	{
		if(a[st][i]==0||b[i]+1>kmx)
		{
			continue;
		}
		b[i]++;
		dfs2(st+1,kmx,alr+1);
		b[i]--;
	}
}
void dfsd(int st,int kmx,int alr,int ji)
{
	int i,j;
	if(st>n)
	{
		if(alr>1)
		{
			int t=alr/2;
			for(i=1;i<=m;i++)
			{
				if(b[i]>t)
				{
					break;
				}
			}
			if(i>m)
			{
				ans+=ji;
				ans%=mo;
			}
		}
		return;
	}
	dfsd(st+1,kmx,alr,ji);
	for(i=1;i<=m;i++)
	{
		if(a[st][i]==0||b[i]+1>kmx)
		{
			continue;
		}
		b[i]++;
		dfsd(st+1,kmx,alr+1,ji*a[st][i]);
		b[i]--;
	}
}
int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		lj=0;
		for(j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			lj+=a[i][j];
			if(a[i][j]>1)
			{
				flag=1;
			}
		}
		lc*=lj;
	}
	if(flag==0)
	{
		dfs2(1,n/2,0);		
	}
	else
	{
		dfsd(1,lc/2,0,1);
	}
	printf("%d",ans);
	return 0;
}
