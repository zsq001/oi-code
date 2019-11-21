#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int first[600010],next[600010],tot=0,to[600010];
int size[300010],father[300010],dep[300010],son[300010];
int T,n;
long long ans=0;
bool vis[300010];

void add(int x,int y)
{
	next[++tot]=first[x];
	first[x]=tot;
	to[tot]=y;
}

void dfs1(int fa,int x)
{
	father[x]=fa;
	size[x]=1;
	dep[x]=dep[fa]+1;
	son[fa]=x;
	for(int i=first[x];i;i=next[i])
	{
		int y=to[i];
		if(fa==y) continue;
		dfs1(x,y);
		size[x]+=size[y];
	}
}

void dfs2(int fa,int x)
{
	for(int i=first[x];i;i=next[i])
	{
		int y=to[i];
		if(y==fa) continue;
		dfs2(x,y);
		if(size[son[x]]<size[y]) son[x]=y;
	}
}

int centroid(int x,int fb,int p)
{
	if(p-size[son[x]]<=p/2&&size[son[x]]<=p/2&&son[x]!=fb) 
	return son[x];
	for(int i=first[x];i;i=next[i])
	{
		int y=to[i];
		if(y!=father[x]&&y!=fb) return centroid(y,fb,p);
	}
	return x;
}

int deal(int x,int y)
{
	if(dep[x]>dep[y]) swap(x,y);
	while(x!=0) 
	{
		size[x]-=size[y];
		x=father[x];
	}
	int a=centroid(1,y,size[1])+centroid(y,x,size[y]);
	while(x!=0) 
	{
		size[x]+=size[y];
		x=father[x];
	}
	return a;
}

int main()
{
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		dep[0]=0;
		dfs1(0,1);
		dfs2(0,1);
//		for(int i=1;i<=n;i++)
//			if(!son[i]) son[i]=i;
		for(int x=1;x<=n;x++)
		{
			vis[x]=true;
			for(int j=first[x];j;j=next[j])
			{
				int y=to[j];
				if(!vis[y]) ans+=deal(x,y);
			}
		}
		printf("%lld\n",ans);
		memset(vis,0,sizeof(vis));
		ans=0;
	}

	fclose(stdin);
	fclose(stdout);	
	return 0;
}
