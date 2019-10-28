#include<cstdio>
const int MAXN=100000,INF=214748364;
int n,m,x,y,a[MAXN],b[MAXN],c[MAXN],ans;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=m;++i)scanf("%d",&b[i]);
	a[n+1]=INF;
	for(int i=1;i<=m;++i)
	{
		int j=c[i-1]+1;
		while(a[j]<b[i]-x)++j;
		if(a[j]>b[i]+y)
		{
			c[i]=j-1;
			continue;
		}
		c[i]=j;
		++ans;
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
