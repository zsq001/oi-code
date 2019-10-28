#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;

int n,m,t,s,x,cnt;
int op,ed;
int head[20010],dis1[20010],vis1[20010],dis2[20010],vis2[20010];
struct edge
{
	int v,next,w;
}E[20010];
priority_queue< pair<int,int> > q1;
priority_queue< pair<int,int> > q2;

void add(int u,int v,int w)
{
	E[++cnt].v=v;
	E[cnt].w=w;
	E[cnt].next=head[u];
	head[u]=cnt;
}

void dij1()
{
	memset(dis1,0x3f3f3f3f,sizeof(dis1));
	memset(vis1,0,sizeof(vis1));
	dis1[s]=0;
	q1.push(make_pair(0,s));
	while(!q1.empty())
	{
		int x=q1.top().second;
		q1.pop();
		if(vis1[x]) continue;
		vis1[x]=1;
		for(int i=head[x];i;i=E[i].next)
		{
			int v=E[i].v,w=E[i].w;
			if((!vis1[v])&&(dis1[v]>dis1[x]+w))
			{
				dis1[v]=dis1[x]+w;
				q1.push(make_pair(-dis1[v],v));
			}
		}
	}
}

void dij2()
{
	memset(dis2,0x3f3f3f3f,sizeof(dis2));
	memset(vis2,0,sizeof(vis2));
	dis2[op]=0;
	q2.push(make_pair(0,op));
	while(!q2.empty())
	{
		int x=q2.top().second;
		q2.pop();
		if(vis2[x]) continue;
		vis2[x]=1;
		for(int i=head[x];i;i=E[i].next)
		{
			int v=E[i].v,w=E[i].w;
			if((!vis2[v])&&(dis2[v]>dis2[x]+w))
			{
				dis2[v]=dis2[x]+w;
				q2.push(make_pair(-dis2[v],v));
			}
		}
	}
}

int main()
{
	freopen("escort.in","r",stdin);
	freopen("escort.out","w",stdout);
	scanf("%d%d%d%d%d",&n,&m,&t,&s,&x);
	for(int i=1;i<=t;i++) scanf("%d",&op);
	for(int i=1;i<=t;i++) scanf("%d",&ed);
	for(int i=1;i<=m;i++)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		add(a,b,c);add(b,a,d);
	}
	dij1();dij2();
//	for(int i=1;i<=n;i++)
//	{
//		printf("%d %d\n",dis1[i],dis2[i]);
//	}
	printf("%d\n",dis1[op]+dis2[ed]);
	return 0;
}
