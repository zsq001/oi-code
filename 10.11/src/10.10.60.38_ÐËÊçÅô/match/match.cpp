#include<cstdio>
const int N=100005;
int x[N],y[N];
int main()
{
	freopen("match.in","r",stdin),freopen("match.out","w",stdout);
	int n,m,a,b,ans=0,l=0,r;
	scanf("%d%d%d%d",&n,&m,&a,&b);
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&y[i]);
	for(int i=1;i<=n;i++)
	{
		r=m;
		while(l<r-1)
		{
			int mid=(l+r)>>1;
			if(y[mid]>=x[i]-a) r=mid;
			else l=mid;
		}
		if(y[r]>=x[i]-a&&y[r]<=x[i]+b) ans++,l=r;
	}
	printf("%d",ans);
	fclose(stdin),fclose(stdout);
	return 0;
}
