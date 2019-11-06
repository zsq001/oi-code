#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
const int N=1005;
const int M=5005;
template<class T>void read(T &x)
{
	bool f=0;x=0;char s=getchar();
	while(s>'9'||s<'0'){f|=(s=='-');s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	x=f?-x:x;
}
int n,m,v[N];
double ans=0;
int head[N],ver[M],nxt[M],edge[M],tot;
bool vis[N];
void addedge(int x,int y,int z){ver[++tot]=y,edge[tot]=z,nxt[tot]=head[x],head[x]=tot;}
void dfs(int x,int s,int sum,int t)
{
	vis[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=ver[i];
		if(y==s)
		{
			ans=max(ans,sum*1./(t+edge[i]));
			continue;
		}
		if(vis[y]) continue;
		dfs(y,s,sum+v[y],t+edge[i]);
	}
	vis[x]=0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;++i) read(v[i]);
	while(m--)
	{
		int x,y,z;
		read(x),read(y),read(z);
		addedge(x,y,z);
	}
	if(n<=5)
	{
		for(int i=1;i<=n;++i) dfs(i,i,v[i],0);
		printf("%.2lf\n",ans);
		return 0;
	}
	return 0;
}
