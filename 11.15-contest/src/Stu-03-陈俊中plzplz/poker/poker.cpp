#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 
using namespace std;

int n,m,c[55],ans;

bool pd(int x)
{
	int tmp=min(m,x);
	for(int i=1;i<=n;i++)
	{
		if(c[i]<x) tmp-=(x-c[i]);
		if(tmp<0) return 0;
	}
	return 1;
}

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&c[i]);
//		maxc=max(maxc,c[i]);
//		minc=min(minc,c[i]);
	}
	int l=0,r=1e10;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(pd(mid)) 
		{
			l=mid+1;
			ans=mid;
		}
		else r=mid;
	}
	printf("%d\n",ans);
	return 0;
}
