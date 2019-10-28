#include<iostream>
#include<cstdio>
#define mmm 100
int za[mmm][mmm],rc[mmm][mmm];
int sx,sy,fx,fy,ans=0;
using namespace std;
int a[4]={0,0,1,-1};
int b[4]={-1,1,0,0};
void dfs(int x,int y)
{
	if(x==fx&&y==fy)
	{
		ans++;
		return ;
	}
	else
	{
		for(int i=0;i<=3;i++)
		{
			if(za[x+a[i]][y+b[i]]==1&&rc[x+a[i]][y+b[i]]==0)
			{
				rc[x][y]=1;
				dfs(x+a[i],y+b[i]);
				rc[x][y]=0;
			}
		}
	}
}
int main()
{
	int n,m,t;
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			za[i][j]=1;
	cin>>sx>>sy>>fx>>fy;
	for(int i=1;i<=t;i++)
	{
		int x,y;
		cin>>x>>y;
		za[x][y]=0;
	}
	dfs(sx,sy);
	cout<<ans<<endl;
	return 0;
}
