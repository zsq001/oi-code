#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
long long int a[10005][10005];
long long int n,m,x1,y1,x2,y2;
void work()
{
	long long int i,j;
	for(i=x1;i<=x2;++i)
	{
		for(j=y1;j<=y2;++j)
		{
			a[i][j]++;
		}
	}
	return ;
}
int main()
{
	freopen("carpet.in","r",stdin);
	freopen("carpet.out","w",stdout);
	long long int i,j;
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
		work();
	}
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			printf("%lld ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
