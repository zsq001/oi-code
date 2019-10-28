#include<stdio.h>
long long n;
int ans=1;
void dfs(long long n)
{
	if(n==1) return ;
	ans++;
	dfs(n/2);
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%lld",&n);
	dfs(n);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
