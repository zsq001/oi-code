#include<iostream>
#include<cstdio>
#define mmm 10001
using namespace std;
struct node{
	int v,next;
}e[mmm];
int dp[mmm][2],cnt=0,z[mmm],head[mmm],vis[mmm];
void add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void dfs(int k)
{
	vis[k]=1;
	for(int i=head[k];i;i=e[i].next)
	{
		if(vis[e[i].v])
			continue;
		dfs(e[i].v);
		dp[k][1]+=dp[e[i].v][0];
		dp[k][0]+=max(dp[e[i].v][0],dp[e[i].v][1]);
	}
	return ;
}
int main(void)
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>dp[i][1];
	for(int i=1,l,k;i<n;i++)
	{
		cin>>l>>k;
		z[l]=1;
		add(k,l);
	}
	for(int i=1;i<=n;i++)
	{
		if(!z[i])
		{
			dfs(i);
			cout<<max(dp[i][0],dp[i][1]);
			return 0;
		}
	}
}
