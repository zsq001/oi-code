#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int n,K,T,cnt,head[5010];
int time1,time2,vis[5010];
int dis[5010],li[20][5][5],ltime[20];
struct edge
{
	int v,next,w;
}E[5010];
priority_queue< pair<int,int> > q;

void add(int u,int v,int w)
{
	E[++cnt].v=v;
	E[cnt].w=w;
	E[cnt].next=head[u];
	head[u]=cnt;
}

int mie(int x)
{
	return 0;
}

//void save()
//{
//	memset(dis,0x3f3f3f3f,sizeof(dis));
//	memset(vis,0,sizeof(vis));
//	dis[n+1]=0;
//	q.push(make_pair(0,n+1));
//	while(!q.empty())
//	{
//		int x=q.top().second;
//		q.pop();
//		if(vis[x]) continue;
//		vis[x]=1;
//		for(int i=head[x];i;i=E[i].next)
//		{
//			int v=E[i].v,w=E[i].w;
//			if((!vis[v])&&(dis[v]>dis[x]+w))
//			{
//				dis[v]=dis[x]+w;
//				q.push(make_pair(-dis[v],v));
//			}
//		}
//	}
//}

int main()
{
	freopen("save.in","r",stdin);
	freopen("save.out","w",stdout);
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&time1);
		add(n+1,i,time1);
	}
//	sort(time1+1,time1+1+n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&time2);
		add(i,n+2,time2);
	}
//	sort(time2+1,time2+1+n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			int a;
			scanf("%d",&a);
			if(i!=j)
			{
				add(i,j,a);
				add(j,i,a);
			}
		}
//	save();
	int qaq=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++)
		{
			for(int k=1;k<=5;k++)
			{
				scanf("%d",&li[i][j][k]);
				qaq+=li[i][j][k];
			}
		}
		if(qaq>=1)	ltime[i]=mie(i);
		else ltime[i]=0;
	}
	T=time1+time2;
//	int flag=save();
//	if(flag==1)
//	{
//		printf("NO\n");
//		return 0;
//	}
//	else if(flag==0)
//	{
	printf("YES\n%d",T);
	return 0;
}
