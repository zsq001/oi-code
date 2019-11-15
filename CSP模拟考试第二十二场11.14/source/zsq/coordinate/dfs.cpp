#include<iostream>
#include<cstdio>
using namespace std;
int ans=0;
int vis[1000][1000];
int lx[4]={0,-1,1};
int ly[4]={1};
void dfs(int x,int y,int le)
{
	if(le<0)
		return;
	if(le==0)
	{
		ans++;
		return ;
	}
	for(int i=0;i<3;i++)
	{
		int xx=x+lx[i];
		int yy=y+ly[i];
		if(vis[xx][yy])
			continue ;
		else
		{
			vis[xx][yy]=1;
			dfs(xx,yy,le-1);
			vis[xx][yy]=0;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	vis[500][500]=1;
	dfs(500,500,n);
	cout<<ans<<endl;
}
