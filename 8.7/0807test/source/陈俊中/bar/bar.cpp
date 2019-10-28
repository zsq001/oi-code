#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
#define maxn 10010
using namespace std;

int zx[maxn],zy[maxn];
int vis[maxn][maxn],mapp[maxn][maxn],flag;
int nx[]={0,0,1,-1},ny[]={1,-1,0,0};
int n,group;
struct node
{
	int x,y,time;
};

void bfs(int x,int y,int time)
{
	queue <node> q;
	node now,next;
	now.x=x;now.y=y;now.time=time;
	q.push(now);
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		int a=now.x,b=now.y,c=now.time;
		if(a==n&&b==n)
		{
			flag=1;
			break;
		}
		mapp[zx[now.time-1]][zy[now.time-1]]=1;
		for(int i=0;i<=3;i++)
		{
			int dx=a+nx[i],dy=b+ny[i];
			if(dx>=1&&dx<=n&&dy>=1&&dy<=n&&mapp[dx][dy]==0)
			{
				next.x=dx;next.y=dy;next.time=c+1;
				vis[dx][dy]=1;
				q.push(next);
			}
		}
	}
}

int main()
{	
	freopen("bar.in ","r",stdin);
	freopen("bar.out","w",stdout);
	scanf("%d",&group);
	while(group--)
	{
		memset(vis,0,sizeof(vis));
		memset(mapp,0,sizeof(mapp));
		flag=0;
		scanf("%d",&n);
		for(int i=1;i<=2*n-2;i++)
		{
			scanf("%d%d",&zx[i],&zy[i]);
		}
		bfs(1,1,0);
		vis[1][1]=1;
		if(flag==1)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
