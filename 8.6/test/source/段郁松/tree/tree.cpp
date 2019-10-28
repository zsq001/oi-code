#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct p
{
	int q,z,v;
}a[3005];
long long int b[3005];
int n,k;
long long int c[3005];
long long int ans;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int i;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n-1;++i)
	{
		scanf("%d%d%d",&a[i].q,&a[i].z,&a[i].v);
		c[i]=a[i].v;
		if(a[i].z-a[i].q==1) b[a[i].q]=a[i].v;
	}
	sort(c,c+n-1);
	for(i=1;i<=k;++i)
	{
		ans+=c[i];
	}
	printf("%lld",ans);
	return 0;
}
