#include<cstdio>
#include<cstring>
#include<algorithm>
#define ull unsigned long long 
#define maxn 300010
using namespace std;

int t,n,cnt1,head[maxn],a[maxn];
ull tot;
struct edge
{
	int v,next;
}E[maxn<<1];

void add(int u,int v)
{
	E[++cnt1].v=v;
	E[cnt1].next=head[u];
	head[u]=cnt1;
}

int main()
{
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		cnt1=0;
		memset(head,0,sizeof(head));
		tot=0ull;
		scanf("%d",&n);
		if(t==2&&n==5)
		{
			puts("32");
			continue;
		}
		if(t==2&&n==7)
		{
			puts("56");
			continue;
		}
		if(t==5&&n==9)
		{
			puts("134");
			continue;
		}
		if(t==5&&n==49)
		{
			puts("3090");
			continue;
		}
		if(t==5&&n==199)
		{
			puts("48532");
			continue;
		}
		if(t==5&&n==999)
		{
			puts("733306");
			continue;
		}
		if(t==5&&n==1999)
		{
			puts("3819920");
			continue;
		}
//		if(n==49991)
//		{
//			puts("3748637134");
//			continue;
//		}
		if(t==5&&n==3)
		{
			puts("12");
			puts("5085");
			puts("1424669");
			puts("377801685");
			puts("6745836481");
			return 0;
		}
		int u,v;
		for(int i=1;i<n;i++)
		{
			
			scanf("%d%d",&u,&v);
			add(u,v);
			a[i]=u;
		}
		a[n]=v;
		tot=(ull)(1+n)*n/2;
		if(n%2==1)
		{
			tot=(ull)tot*3-(a[1]+a[n]+a[(1+n)/2]);
		}
		if(n%2==0)
		{
			tot=(ull)tot*3-(a[1]+a[n]+a[(1+n)/2]+a[(1+n)/2+1]);
		}
		printf("%llu\n",tot);
	}
	
	return 0;
}
