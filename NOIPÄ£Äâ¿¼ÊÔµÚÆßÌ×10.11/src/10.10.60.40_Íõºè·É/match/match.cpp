#include<stdio.h>
const int MAXN=100010;
int a[MAXN],b[MAXN];
bool visa[MAXN],visb[MAXN];
int ans;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int n,m,x,y;
	scanf("%d%d%d%d",&n,&m,&x,&y);
	int i,j;
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(i=1;i<=m;++i)
		scanf("%d",&b[i]);
	for(j=1;j<=m;++j)
		for(i=1;i<=n;++i)
			if(a[i]-x<=b[j]&&a[i]+y>=b[j]&&visa[i]==false&&visb[j]==false)
			{
				visa[i]=true;
				visb[j]=true;
				ans++;
			}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
