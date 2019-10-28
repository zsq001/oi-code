#include<cstdio>
int ans;
void dfs(int n,int x)
{
	if(0 == n)
	{
		ans ++;
		ans %= 1000000007;
		return;
	}
	for(int i = x+1;i <= n;i ++)
	{
		dfs(n-i,i);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	dfs(n,0);
	printf("%d",ans);
	return 0;
}
