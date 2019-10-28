#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define minn -0x7fffffff
#define max(a,b) a>b?a:b
struct node
{
	int value;
	int flag;
}dp[210][210][210];
int n,m,a[200010],stt;
int dfs(int alr,int pos,int bef)
{
	if(dp[alr][pos][stt].flag==1)
	{
		return dp[alr][pos][stt].value;
	}
	if(alr==m)
	{
		if(bef<n||stt>1)
		{
			return 0;
		}
		return minn;
	}
	int tmp=minn,spc=(m-alr-1)*2;
	for(int i=pos;i+spc<=n;i++)
	{
		if(alr==0)
		{
			stt=i;
		}
		tmp=max(tmp,dfs(alr+1,i+2,i)+a[i]);
	}
	dp[alr][pos][stt].flag=1;
	dp[alr][pos][stt].value=tmp;
	return tmp;
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	memset(dp,0,sizeof(dp));
	stt=1;
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(2*m>n)
	{
		printf("Error!");
		return 0;
	}
	printf("%d",dfs(0,1,-1));
	return 0;
}
/*
7 3
1 2 3 4 5 6 7
*/
