#include<cstdio>
#include<algorithm>
using namespace std;
#define MN 100000
int t[MN+5],a[MN+5];
int main()
{
	freopen("coal.in","r",stdin);
	freopen("coal.out","w",stdout);
	int n,k,c,w,i;double ans=0;
	scanf("%d%d%d%d",&n,&k,&c,&w);
	for(i=1;i<=n;++i)scanf("%d%d",&t[i],&a[i]);
	for(i=n;i;--i)ans=max(ans,t[i]<2?(1-.01*k)*ans+a[i]:(1+.01*c)*ans-a[i]);
	printf("%.2lf",ans*w);
}
