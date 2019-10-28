#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 100010
#define ll long long 
using namespace std;

int n,m,x,y,a[maxn],b[maxn];
//int flag[maxn];
ll ans;

int main()
{
	freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
	int l=1,r=1;
    scanf("%d%d%d%d",&n,&m,&x,&y);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	int qaq=min(n,m);
	while(l<=qaq&&r<=qaq)
    {
//    	if(b[r]>a[l]+y||b[r]<a[l]-x) break;
    	if(b[r]<=a[l]+y&&b[r]>=a[l]-x)
    	{
    		l++;r++;ans++;
			continue;
		}
		if(b[r]>a[l]+y) 
		{
			l++;
			continue;
		}
		if(b[r]<a[l]-x)
		{
			r++;
			continue;
		}
//		r++;l++;
	}
	printf("%lld",ans);
	return 0;
}
