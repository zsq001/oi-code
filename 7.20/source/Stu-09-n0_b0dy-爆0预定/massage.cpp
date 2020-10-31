#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
int T,Q,s,t,num[10005],cnt,head[10005],ver[200005],nxt[200005],edge[200005],cost[10005],pre[10005],tot=1,way[10005];
bool prime[10005],vis[10005];
queue<int>q;
void addedge(int x,int y,int z){ver[++tot]=y,edge[tot]=z,nxt[tot]=head[x],head[x]=tot;}
void build()
{
	for(int i=1000;i<10000;++i)
	{
		if(prime[i]==0) continue;
		int x1=i/1000,x2=i/100%10,x3=i/10%10,x4=i%10;
		for(int j=1000;j<10000;++j)
		{
			if(prime[j]==0) continue;
			int y1=j/1000,y2=j/100%10,y3=j/10%10,y4=j%10,cnt=0;
			if(x1==y1) ++cnt;
			if(x2==y2) ++cnt;
			if(x3==y3) ++cnt;
			if(x4==y4) ++cnt;
			if(cnt==3)
			{
				if(x1!=y1) addedge(i,j,abs(x1-y1));
				if(x2!=y2) addedge(i,j,abs(x2-y2));
				if(x3!=y3) addedge(i,j,abs(x3-y3));
				if(x4!=y4) addedge(i,j,abs(x4-y4));
			}
		}
	}
}
void spfa()
{
	memset(cost,0x7f,sizeof(cost));
	cost[s]=0;
	q.push(s);
	while(q.empty()==0)
	{
		int x=q.front();
		q.pop();
		vis[x]=0;
		for(int i=head[x];i;i=nxt[i])
		{
			int y=ver[i];
			if(cost[y]>cost[x]+edge[i])
			{
				cost[y]=cost[x]+edge[i];
				if(Q) pre[y]=x;
				if(vis[y]) continue;
				vis[y]=1;
				q.push(y);
			}
		}
	}
}
int main()
{
	freopen("massage.in","r",stdin);
	freopen("massage.out","w",stdout);
	scanf("%d%d",&T,&Q);
	for(int i=2;i<=10000;++i) prime[i]=1;
	for(int i=2;i<=10000;++i)
	{
		if(prime[i]) num[++cnt]=i;
		for(int j=1;(j<=cnt)&&(num[j]*i<=10000);++j)
		{
			prime[num[j]*i]=0;
			if(i%num[j]==0) break;
		}
	}
	build();
	while(T--)
	{
		scanf("%d%d",&s,&t);
		if(s==t)
		{
			printf("%d\n",0);
			if(Q) printf("%d\n",s);
			return 0;
		}
		
		spfa();
		printf("%d\n",cost[t]);
		if(Q)
		{
			int x=t;
			tot=0;
			while(x!=s)
			{
				way[++tot]=pre[x];
				x=pre[x];
			}
			for(int i=tot;i;--i)
				printf("%d-",way[i]);
			printf("%d\n",t);
		}
	}
	return 0;
}
