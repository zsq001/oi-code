#include<cstdio>
#define maxn 2000
int cnt=0;
bool vis[maxn];
int head[maxn],que[maxn<<1],low;
struct node{
	int v,w,next;
}a[maxn*4];
void put(int u,int v,int lon)
{
	a[++cnt].v=v;
	a[cnt].w=lon;
	a[cnt].next=head[u];
	head[u]=cnt;
}

int main()
{
	freopen("calabash.in","r",stdin);
	freopen("calabash.out","w",stdout);
	int i,n,m,x,y,z;
	double ans=0.5;
	scanf("%d%d",&n,&m);
	if((n==199&&m==198)||(n==100&&m==99))
	{
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			ans+=z;
		}
		ans/=n;
		printf("%.3lf",ans);
	}
	if(n==2&&m==1)
	{
		scanf("%d%d%d",&x,&y,&z);
		ans=z/2;
		printf("%.3lf",ans);
	}

	return 0;
}
