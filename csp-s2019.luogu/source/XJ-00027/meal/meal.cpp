#include <stdio.h>

#define end 998244353

int f[110][2010];
int ans=0;
int n,m;

void dfs(int a,int b,int c,int d)//方法，食材，数目,k
{
	if(a>n)
		return ; 
	if(c<=d/2)
	{
		ans++;
		ans%=end;
	}
	for(int i=1;i<=m;i++)
			for(int j=1;j<=f[a][i];j++)
				dfs(a+1,i,j,d+j);
}

int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&f[i][j]);
	for(int i=1;i<=n;i++)
		dfs(i,1,0,0);
				
	printf("%d",ans);
	return 0;
}

