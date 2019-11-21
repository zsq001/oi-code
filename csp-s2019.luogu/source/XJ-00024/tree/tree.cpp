#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#define ll long long int
using namespace std;
int t,a[1000005],p,n,l;
bool cmp(int a,int b)
{
	return a<b;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+1+n,cmp);
		for(i=1;i<=n;++i)
		{
			printf("%d ",a[i]);
		}
		for(i=1;i<n;++i)
		{
			scanf("%d%d",&l,&p);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
