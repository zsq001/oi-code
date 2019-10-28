#include<stdio.h>
#include<string.h>
bool way[2010][2010];
bool vis[2010];
int a[2010],b[2010],link[2010];
int n,m,x,y,head=1,ans;
bool find(int u)
{
	for(int i=1;i<=m;i++)
	{
		if(!vis[i]&&way[u][i])
		{
			vis[i]=true;
			if(!link[i]||find(link[i]))
			{
				link[i]=u;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int j=1;j<=m;j++)
	{
		scanf("%d",&b[j]);
		for(int i=head;i<=n;i++)
		{
			bool flag=false;
			if(a[i]<=b[j]+x&&a[i]>=b[j]-y)
			{
				if(!flag)head=i;
				if(!flag)flag=true;				
				way[i][j]=true;
			}
			if(a[i]>b[j]+x)break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		if(find(i))ans++;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
