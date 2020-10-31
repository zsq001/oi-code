#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#define mmm 300000
using namespace std;
struct node{
	int v,next;
}a[mmm];
int dp[mmm],n,m,cnt=0,tot=0,head[mmm],ru[mmm],ts[mmm];//d//rudu
queue<int> q;
void add(int u,int v)
{
	a[++cnt].next=head[u];
	a[cnt].v=v;
	head[u]=cnt;
}
void tpsort()
{
	for(int i=1;i<=n;i++)
	{
		if(ru[i]==0)
		{
			q.push(i);
			ts[++tot]=i;
		}
	}
	while(!q.empty())
	{
		int qwq=q.front();
		q.pop();
		for(int i=head[qwq];i;i=a[i].next)
		{
			int vv=a[i].v;
			ru[vv]--;
			if(ru[vv]==0)
			{
				q.push(vv);
				ts[++tot]=vv;
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		add(u,v);
		ru[v]++;
	}
	tpsort();
	for(int i=1;i<=n;i++)
		dp[i]=1;
	for(int i=1;i<=n;i++)
	{
		int ww=ts[i];
		for(int j=head[ww];j;j=a[j].next)
		{
			int v=a[j].v;
			dp[v]=max(dp[v],dp[ww]+1);
		}
	}
	for(int i=1;i<=n;i++)
		cout<<dp[i]<<endl;
	return 0;
}
