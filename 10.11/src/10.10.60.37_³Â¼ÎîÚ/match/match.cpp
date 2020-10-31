#include <cstdio>
#define ll long long
using namespace std;
ll ans,tmp,n,m,x,y,a[100050],b[100050];
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%I64d%I64d%I64d%I64d",&n,&m,&x,&y);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%I64d",&b[i]);
	int j=1;
	for(int i=1;i<=n&&j<=m;i++)
	{
		if(b[j]>a[i]+y)continue;
		while(j<=m)
		{
			if(b[j]>=a[i]-x&&b[j]<=a[i]+y)
			{
				ans++;
				j++;
				break;
			}
			j++;
		}
	}
	printf("%I64d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
