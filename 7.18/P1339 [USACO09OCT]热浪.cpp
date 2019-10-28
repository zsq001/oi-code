#include<iostream>
#include<queue>
#define inf 2147483647
using namespace std;
queue<int>q;
int hl[70000],vis[30000],dis[30000],head,i,tt,cc,ttss,ttee,cnt;
struct node{
	int v,w,n;
}e[1010101];
void add(int u,int v,int w)
{
	e[++cnt].w=w;
	e[cnt].v=v;
	e[cnt].n=hl[u];
	hl[u]=cnt;
}
void spfa(int s)
{
	for(int i=1;i<=tt;i++)
	dis[i]=inf;
	vis[s]=1;
	dis[s]=0;
	q.push(s);
	while(!q.empty())
	{
		head=q.front();
		for(int i=hl[head];i!=-1;i=e[i].n)
		{
			if(dis[head]+e[i].w<dis[e[i].v])
			{
				dis[e[i].v]=dis[head]+e[i].w;
				if(!vis[e[i].v])
				{
					vis[e[i].v]=1;
					q.push(e[i].v);
				}
			}
		}
		q.pop();
		vis[head]=0;
	}
}
int main()
{
	int u,v,w;
	cin>>tt>>cc>>ttss>>ttee;
	for(int i=1;i<=cc;i++)
	hl[i]=-1;
	for(int i=1;i<=cc;i++)
	{
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	spfa(ttss);
	cout<<dis[ttee];
	return 0;
}
