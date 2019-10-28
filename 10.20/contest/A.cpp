#include<iostream> 
#include<cstdio>
#define mmm 1000
int a[mmm],n,vis[mmm];
using namespace std;
void dfs(int now,int la,int an)
{
	if(la==0)
	{
		an+=a[now];
		vis[now]=1;
	}
	if(vis[now-1])
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		dfs(i,0);
}
