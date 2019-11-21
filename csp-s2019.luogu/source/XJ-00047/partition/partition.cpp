#include<stdio.h>
using namespace std;

long long ans;

struct P
{
	int w,prev,next;
}a[50010];

int qmax(int a,int b)
{
	if(a>b)return a;
	return b;
}

int main()
{
	int n,pan,mp=-0xfffffff;
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	
	scanf("%d%d",&n,&pan);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].w);
		a[i].prev=i-1;a[i].next=i+1;
	}
	for(int i=2;i<n;i=a[i].next)
	{
		if(mp>a[a[i].prev].w)
		{
			a[a[i].prev].w+=a[i].w,a[i].w=0,mp=qmax(mp,a[a[i].prev].w);
			a[a[i].next].prev=i-1,a[a[i].prev].next=i+1;
		}
		 if(a[i].w<a[a[i].prev].w)
		{
			if(a[a[i].prev].w+a[i].w>a[a[i].next].w)
				a[a[i].next].w+=a[i].w,a[i].w=0;
			else a[a[i].prev].w+=a[i].w,a[i].w=0,mp=qmax(mp,a[a[i].prev].w);
			a[a[i].next].prev=i-1,a[a[i].prev].next=i+1;
		}
	}
	for(int i=n;i>=1;i=a[i].prev)
		if(a[i].w<a[a[i].prev].w)
		{
			a[a[i].prev].w+=a[i].w;
			a[i].w=0;
		}
	for(int i=1;i<=n;i++)
		ans+=a[i].w*a[i].w;
	printf("%lld",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
	
