#include <stdio.h>
#include <algorithm>
using namespace std;
#define lowbit(x) (x&(-x))
int a[100005];
int main()
{
	int n,k,t,minx=100,cnt,ans=0;
	freopen("lamp.in","r",stdin);
	freopen("lamp.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++)
		{
			scanf("%1d",&t);
			a[i]=a[i]+(1<<(k-j))*t;
		}
	k=(1<<k);
	for(int i=0;i<k;i++)
	{
		minx=100;
		for(int j=1;j<=n;j++)
		{
			t=(a[j]^i);cnt=0;
			while(t)
			{
				t-=lowbit(t);
				cnt++;
			}
			minx=min(minx,cnt);
		}
		ans=max(minx,ans);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
