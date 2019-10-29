#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int N=50005;
template<class T>void read(T &x)
{
	bool f=0;x=0;char s=getchar();
	while(s>'9'||s<'0'){f|=(s=='-');s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	x=f?-x:x;
}
int n,s,t,cnt=1,maxn;
int ver[N<<1],nxt[N<<1],head[N],vis[N],size[N],pre[N],tot;
void addedge(int x,int y){ver[++tot]=y,nxt[tot]=head[x],head[x]=tot;}
void dfs(int x,int fa)
{
	size[x]+=vis[x];
	if(size[x]>maxn||(size[x]==maxn&&x<t)) maxn=size[x],t=x;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=ver[i];
		if(y==fa||size[y]) continue;
		size[y]=size[x],pre[y]=x;
		dfs(y,x);
	}
}
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	read(n),read(s),++s,vis[1]=1;
	for(int i=2;i<=n;++i)
	{
		int x;
		read(x),++x,vis[i]=1;
		addedge(i,x),addedge(x,i);
	}
	printf("%d\n",s-1),vis[s]=0;
	while(cnt<n)
	{
		maxn=0;
		memset(size,0,sizeof(size));
		dfs(s,-1);
		printf("%d\n",t-1);
		int x=t;
		while(x!=s) vis[x]=0,x=pre[x];
		cnt+=maxn;
	}
	return 0;
}
