#include<iostream>
#include<cstring>
#define mmm 600
int a[mmm][mmm],l[mmm][mmm],r[mmm][mmm],vis[mmm][mmm];
using namespace std;
int xx[4]={-1,0,1,0};
int yy[4]={0,1,0,-1};
int n,m;
#define nx xx[i]+x
#define ny y+yy[i]
void dfs(int x,int y)
{
	vis[x][y]=1;
	for(int i=0;i<4;i++)
	{
		if(nx<1||nx>n||ny<1||ny>m)
		continue; 
		if(a[nx][ny]>=a[x][y])
		continue;
		if(vis[nx][ny]==0)
		dfs(nx,ny);
		l[x][y]=min(l[x][y],l[nx][ny]);
		r[x][y]=max(r[x][y],r[nx][ny]);
	}
}
int main()
{
	int flag=0,cnt=0;
	memset(l,0x3f,sizeof(l));
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	l[n][i]=r[n][i]=i;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	cin>>a[i][j];
	for(int i=1;i<=m;i++)
	if(!vis[1][i])
	dfs(1,i);
	for(int i=1;i<=m;i++)
	if(!vis[n][i])
	{
		flag=1;
		cnt++;
	}
	if(flag)
	{
		cout<<"0"<<endl<<cnt;
		return 0;
	}
	int left=1;
	while(left<=m)
	{
		int mmmm=0;
		for(int i=1;i<=m;i++)
		if(l[1][i]<=left)
		mmmm=max(mmmm,r[1][i]);
		cnt++;
		left=mmmm+1;
	}
	cout<<"1"<<endl<<cnt;
	return 0;
} 
