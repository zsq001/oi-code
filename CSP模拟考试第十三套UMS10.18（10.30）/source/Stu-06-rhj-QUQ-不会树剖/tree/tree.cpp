#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long
using namespace std;
const int N=100005;
template<class T>void read(T &x)
{
	bool f=0;x=0;char s=getchar();
	while(s>'9'||s<'0'){f|=(s=='-');s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	x=f?-x:x;
}
int n,m,f[N];
ll dist[N];
int head[N],ver[N<<1],nxt[N<<1],tot;
void addedge(int x,int y){ver[++tot]=y,nxt[tot]=head[x],head[x]=tot;}
void dfs(int x,int fa)
{
	for(int i=head[x];i;i=nxt[i])
	{
		int y=ver[i];
		if(y==fa) continue;
		dist[y]+=dist[x],f[y]=x;
		dfs(y,x);
	}
}
void update(int x,int fa,int k,int dep)
{
	dist[x]+=1ll*k*dep;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=ver[i];
		if(y==fa) continue;
		update(y,x,k,dep+1);
	}
}
void add(int x,int fa,int k)
{
	dist[x]+=k;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=ver[i];
		if(y==fa) continue;
		add(y,x,k);
	}
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;++i) read(dist[i]);
	for(int i=1;i<n;++i)
	{
		int x,y;
		read(x),read(y);
		addedge(x,y),addedge(y,x);
	}
	dfs(1,-1);
	while(m--)
	{
		int opt,x,y;
		read(opt),read(x);
		if(opt==3) printf("%d\n",dist[x]);
		else if(opt==2) read(y),update(x,f[x],y,1);
		else read(y),add(x,f[x],y);
	}
	return 0;
}
