#include<cstdio>
#include<algorithm>
using namespace std;
#define inf 1000000009
int n,ans,maxn,minn;
int a[100050];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
		if(a[i]>=maxn && a[i]>a[i+1]) ans+=a[i],minn=inf;
		if(a[i]<=minn && a[i]<a[i+1]) ans-=a[i],maxn=0;
	}
	printf("%d",ans);
	return 0;
}
/*
6
1 2 3 4 5 6
6
6 6 6 5 4 3 
7
1 2 3 3 2 2 1
*/
