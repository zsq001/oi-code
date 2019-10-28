#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool vis[1100][1100];
int point,fa[11000],head[11000];
int n,m,y,x,ans,a[110000],b[110000];
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=m;i++)scanf("%d",b+i);
	for(int i=1;i<=n;i++)
	{
		int s=lower_bound(b+1,b+m+1,a[i]-x)-b;
		for(int k=s;b[k]<=a[i]+y&&k<=m;k++)
		if(!fa[k])
		{
			fa[k]=i;
			ans++;
			break;
		}
	}
	printf("%d",ans);
	return 0;
}
