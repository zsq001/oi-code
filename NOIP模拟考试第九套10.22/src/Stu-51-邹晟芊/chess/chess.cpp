#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int a[2510][2510],vis[2510][2510];
int ju[27],ans,i,j;
	int n,m;
void dfs(int x,int y,int lx,int ly)
{
	if(vis[x][y]==1)
	{
		cout<<"Yes"<<endl;
		exit(0);
	}
	vis[x][y]=1;
	if(ans>=4 and((x+1==i and y==j) or (x==i and y+1==j) or (x-1==i and y==j) or (x==i and y-1==j)))
	{
		cout<<"Yes"<<endl;
		exit(0);
	}
	if(x+1<=n and x+1!=lx and a[x+1][y]==a[x][y] and vis[x+1][y]==0)
	dfs(x+1,y,x,y),ans++;
	if(y+1<=m and y+1!=ly and a[x][y+1]==a[x][y] and vis[x][y+1]==0)
	dfs(x,y+1,x,y),ans++;
	if(x>=2 and x-1!=lx and a[x-1][y]==a[x][y] and vis[x-1][y]==0)
	dfs(x-1,y,x,y),ans++;
	if(y>=2 and y-1!=ly and a[x][y-1]==a[x][y] and vis[x][y-1]==0)
	dfs(x,y-1,x,y),ans++;
	return ;
}
int main()
{
//	freopen("chess.in","r",stdin);
//	freopen("chess.out","w",stdout);
	cin>>n>>m;
	for( i=1;i<=n;i++)
	for( j=1;j<=m;j++)
	{
		char l;
		cin >>l;
		int w=l-'A';
		a[i][j]=w;
	}
	for( i=1;i<=n;i++)
	for( j=1;j<=m;j++)
	{
		memset(vis,0,sizeof(vis));
		if(ju[a[i][j]]==1)
		continue;
		ju[a[i][j]]=1;
		dfs(i,j,-1,-1);
	}
	cout<<"No"<<endl;
	return 0;
}
