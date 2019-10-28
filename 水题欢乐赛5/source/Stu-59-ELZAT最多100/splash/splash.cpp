#include<cstdio>
#include<algorithm>
using namespace std;
int a[10][10];
int ans,q;
bool check()
{
	for(int i = 1;i <= 6;i ++)
	for(int j = 1;j <= 6;j ++)
		if(a[i][j] > 0) return false;
	return true;
}

int update(int x,int y)
{
	int ret = 0;
	a[x][y] = 0;
	for(int i = 1;i < y;i ++)
	{
		if(a[x][i] > 0)
		{
			a[x][i] ++;
			if(a[x][i] > 4) ret += update(x,i);
			break;		
		}
	}
	
	for(int i = y+1;i <= 6;i ++)
	{
		if(a[x][i] > 0)
		{
			a[x][i] ++;
			if(a[x][i] > 4) ret += update(x,i);	
			break;		
		}
	}
	
	for(int i = 1;i < x;i ++)
	{
		if(a[i][y] > 0)
		{
			a[i][y] ++;
			if(a[i][y] > 4) ret += update(i,y);	
			break;		
		}
	}
	
	for(int i = x+1;i <= 6;i ++)
	{
		if(a[i][y] > 0)
		{
			a[i][y] ++;
			if(a[i][y] > 4) ret += update(i,y);
			break;
		}
	}
	
	return q == 2?ret+1:0;
}

void dfs(int x,int y,int left)
{
	if(check())
	{
		ans = max(ans,left);
		return ;
	}
	if(!left) return;
	if(y > 6) x ++,y = 1;
	if(x > 6) return;
	
	if(a[x][y] > 0)
	{
		int t[10][10];
		for(int i = 1;i <= 6;i ++)
		for(int j = 1;j <= 6;j ++)
			t[i][j] = a[i][j];
			
		a[x][y] ++;
		int k = 0;
		if(a[x][y] > 4) k += update(x,y)/3;
		dfs(x,y,left-1+k);//点了 
		
		for(int i = 1;i <= 6;i ++)
		for(int j = 1;j <= 6;j ++)
			a[i][j] = t[i][j];
	}
	dfs(x,y+1,left);//没点
}

int main()
{
	freopen("splash.in","r",stdin);
	freopen("splash.out","w",stdout);
	int t;
	scanf("%d%d",&t,&q);
	while(t --)
	{
		ans = 0;
		for(int i = 1;i <= 6;i ++)
		{
			for(int j = 1;j <= 6;j ++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		dfs(1,1,20);
		printf("%d\n",ans);
	}
	return 0;
}
