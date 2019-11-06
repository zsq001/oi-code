#include<iostream>
#include<cstdio>
#include<cstring>
#define mmm 1020
const int inf=2147483647;
using namespace std;
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
int ans=inf,un[mmm][mmm],d[mmm][mmm];
int m,n;
void dfs(int x,int y,int tot,bool magic)
{
	if(x>m or y>m or x<1 or y<1)
		return ;
	if(tot>=d[x][y])
		return ;
	d[x][y]=tot;
	if(x==m and y==m)
	{
		if(ans>tot)
			ans=tot;
//		ans=(ans<tot?ans:tot);
		return;
	}
	for(int i=0;i<4;i++)
	{
		int xa=x+dx[i];
		int ya=y+dy[i];
		if(un[xa][ya])
		{
			if(un[x][y]==un[xa][ya])
				dfs(xa,ya,tot,0);
			else
				dfs(xa,ya,tot+1,0);
		}
		else
		{
			if(!magic)
			{
				un[xa][ya]=un[x][y];
				dfs(xa,ya,tot+2,1);
				un[xa][ya]=0;
			}
		}

	}
}
int main()
{
	memset(d,0x7f,sizeof(d));
	cin>>m>>n;
	int wx,wy,c;
	for(int i=1;i<=n;i++)
	{
		cin>>wx>>wy>>c;
		un[wx][wy]=c+1;//1 red 2 ye
	}
	dfs(1,1,0,0);
//	cout<<ans<<endl;
	cout<<((ans==inf)?-1:ans)<<endl;
	return 0;
}
