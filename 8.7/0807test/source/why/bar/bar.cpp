#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1010][1010];
int t,n,f;
struct node{
	int x,y;
}b[1010];
void dfs(int t,int x,int y)
{
	if(x==1&&y==n)
	{
		f=1;
		return;
	}
	if(a[x-1][y]==0&&x-1>=1)
	{
		a[n+1-b[t].x][b[t].y]=1;
		dfs(t+1,x-1,y);
	}
	if(a[x][y+1]==0&&y+1<=n)
	{
		a[n+1-b[t].x][b[t].y]=1;
		dfs(t+1,x,y+1);
	}
	return;
}
int main()
{
	freopen("bar.in","r",stdin);
	freopen("bar.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=2*n-2;i++)
		{
			scanf("%d%d",&b[i].x,&b[i].y);
		}
		dfs(1,n,1);
		if(f==1)
		{
			printf("Yes\n");
			f=0;
		}
		else printf("No\n");
	}
}

