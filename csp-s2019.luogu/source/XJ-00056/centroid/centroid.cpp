#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long
using namespace std;
template<class T>void read(T &x)
{
	bool f=0;x=0;char s=getchar();
	while(s>'9'||s<'0'){f|=(s=='-');s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	x=f?-x:x;
}
int T,n,dx,dy,cnt;
int head[300005],ver[600005],nxt[600005],tot,num1,num2,size[300005],du[300005];
long long ans;
bool vis[300005];
struct node
{
	int fr,to;
}edge[300005];
void addedge(int x,int y){ver[++tot]=y,nxt[tot]=head[x],head[x]=tot;}
void find(int x,int fa)
{
	vis[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=ver[i];
		if((x==dx&&y==dy)||(x==dy&&y==dx)||y==fa) continue;
		find(y,x);
	}
}
void dfs(int x,int fa)
{
	size[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=ver[i];
		if(y==fa||vis[y]==0) continue;
		dfs(y,x);
		size[x]+=size[y];
	}
}
void solve1()
{
	for(int i=1;i<=cnt;++i)
	{
		dx=edge[i].fr,dy=edge[i].to,num1=0,num2=0;
		memset(vis,0,sizeof(vis));
		find(dx,-1);
		for(int x=1,minn=1<<30;x<=n;++x)
			if(vis[x])
			{
				dfs(x,-1);
				int mx=0;
				for(int i=head[x];i;i=nxt[i])
				{
					int y=ver[i];
					if(y==dy) continue;
					if(size[y]>mx) mx=size[y];
				}
				if(mx<minn) minn=mx,num1=x,num2=0;
				else if(mx==minn) num2=x;
			}
		ans+=num1+num2;
		num1=0,num2=0;
		memset(vis,0,sizeof(vis));
		find(dy,-1);
		for(int x=1,minn=1<<30;x<=n;++x)
			if(vis[x])
			{
				dfs(x,-1);
				int mx=0;
				for(int i=head[x];i;i=nxt[i])
				{
					int y=ver[i];
					if(y==dx) continue;
					if(size[y]>mx) mx=size[y];
				}
				if(mx<minn) minn=mx,num1=x,num2=0;
				else if(mx==minn) num2=x;
			}
		ans+=num1+num2;
	}
	printf("%lld\n",ans);
}
void dfs1(int x,int fa,int flag)
{
	ans+=(x<<1);
	if(flag) ans+=x;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=ver[i];
		if(y==fa) continue;
		dfs1(y,x,flag?0:1);
	}
}
int main()
{
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	read(T);
	while(T--)
	{
		memset(head,0,sizeof(head));
		tot=0,ans=0,cnt=0;
		read(n);
		for(int i=1;i<n;++i)
		{
			int x,y;
			read(x),read(y);
			addedge(x,y),addedge(y,x);
			edge[++cnt].fr=x,edge[cnt].to=y;
			du[x]++,du[y]++;
		}
		if(n<=2000) solve1();
//		else solve2();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
