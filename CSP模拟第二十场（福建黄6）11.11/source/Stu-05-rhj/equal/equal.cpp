#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int N=100005;
template<class T>void read(T &x)
{
	bool f=0;x=0;char s=getchar();
	while(s>'9'||s<'0'){f|=(s=='-');s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	x=f?-x:x;
}
int n,m,fa[N][25],dep[N],size[N];
int head[N],ver[N<<1],nxt[N<<1],tot;
//int dep[N],top[N],son[N],f[N],size[N];
void addedge(int x,int y){ver[++tot]=y,nxt[tot]=head[x],head[x]=tot;}
void dfs(int x,int f)
{
	size[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=ver[i];
		if(y==f) continue;
		dep[y]=dep[x]+1,fa[y][0]=x;
		dfs(y,x);
		size[x]+=size[y];
	}
}
int Lca(int x,int y)
{
	if(dep[x]>dep[y]) swap(x,y);
	int del=dep[y]-dep[x];
	for(int i=20;i>=0;--i)
		if((1<<i)&del) y=fa[y][i];
	if(x==y) return x;
	for(int i=20;i>=0;--i)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int main()
{
	freopen("equal.in","r",stdin);
	freopen("equal.out","w",stdout);
	read(n);
	for(int i=2;i<=n;++i)
	{
		int x,y;
		read(x),read(y);
		addedge(x,y),addedge(y,x);
	}
	dep[1]=1,dfs(1,-1);
	for(int i=1;i<=20;++i)
		for(int j=1;j<=n;++j)
			fa[j][i]=fa[fa[j][i-1]][i-1];
	read(m);
	while(m--)
	{
		int x,y,lca,dist,del;
		read(x),read(y);
		lca=Lca(x,y),dist=dep[x]+dep[y]-dep[lca]*2;
		if(x==y)
		{
			printf("%d\n",n);
			continue;
		}
		if(dist%2)
		{
			printf("0\n");
			continue;
		}
		if(dep[x]>dep[y]) swap(x,y);
		del=dist/2-1;
		for(int i=20;i>=0;--i)
			if((1<<i)&del) x=fa[x][i],y=fa[y][i];
		if(dep[x]==dep[y]) printf("%d\n",n-size[x]-size[y]);
		else printf("%d\n",size[fa[y][0]]-size[y]);
	}
	return 0;
}
