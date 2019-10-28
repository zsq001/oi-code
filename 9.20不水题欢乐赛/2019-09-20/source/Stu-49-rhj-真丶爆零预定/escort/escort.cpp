#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
template<class T>void read(T &x)
{
	bool f=0;x=0;char s=getchar();
	while(s>'9'||s<'0'){f|=(s=='-');s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	x=f?-x:x;
}
int n,m,s,ss,t,tt,X,ans,dist[10005];
int head[10005],ver[20005],nxt[20005],edge[20005],tot;
bool vis[10005];
queue<int>q;
void addedge(int x,int y,int z){ver[++tot]=y,edge[tot]=z,nxt[tot]=head[x],head[x]=tot;}
void spfa()
{
	while(q.empty()==0) q.pop();
	memset(vis,0,sizeof(vis));
	memset(dist,0x3f,sizeof(dist));
	q.push(s);
	dist[s]=0;
	while(q.empty()==0)
	{
		int x=q.front();
		q.pop();
		vis[x]=0;
		for(int i=head[x];i;i=nxt[i])
		{
			int y=ver[i];
			if(dist[y]>dist[x]+edge[i])
			{
				dist[y]=dist[x]+edge[i];
				if(vis[y]) continue;
				q.push(y);
				vis[y]=1;
			}
		}
	}
}
int main()
{
	freopen("escort.in","r",stdin);
	freopen("escort.out","w",stdout);
	read(n),read(m),read(t),read(s),read(X);
	if(t==1)
	{
		read(ss),read(tt);
		while(m--)
		{
			int x,y,z,zz;
			read(x),read(y),read(z),read(zz);
			addedge(x,y,z),addedge(y,x,zz);
		}
		spfa();
		ans=dist[ss],s=ss,ss=tt;
		spfa();
		printf("%d\n",ans+dist[ss]);
	}
	return 0;
}
