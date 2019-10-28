#include<cstdio>
#include<algorithm>
using namespace std;
int kk,n;
bool mapp[110];
long long map[101][101];
long long mm[2510];
long long num=0,minn=21474836478;
bool CMP(int x,int y)
{
	return x<y;
}

int min(int x,int y)
{
	if(x>y)return y;
	return x;
}

void dfs(int x,int now,long long numm)
{
	if(x==kk && numm<minn){
		minn=numm;
		return;
	}
	if(x>=kk || now>n || mapp[now]==1)return;
	int i;
	for(i=1;i<=n;i++)
	{
			mapp[now]=1;
			dfs(x+1,now+i,numm+map[now][now+i]);
			mapp[now]=0;
	}
	return;
}

int main()
{
	int i,j,k;
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d%d",&n,&kk);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			map[i][j]=2147483647;
		}
	}
	if(n<50)
  {
		int nn=n-1;
	for(i=1;i<=nn;i++)
	{
		int x,y;
		long long z;
		scanf("%d%d%lld",&x,&y,&z);
		map[x][y]=z;
		map[y][x]=z;
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
			}
		}
	}
	int ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(map[i][j]!=214748364){
				mm[++ans]=map[i][j];
			}
		}
	}
	kk--;
/*	minn=0;
	sort(mm+1,mm+1+ans,CMP);
	for(i=1;i<=kk;i++)
	{
		minn+=mm[i];
	}*/
	n--;
	for(i=1;i<=n;i++)
	{
		dfs(0,i,0);
	}
	printf("%lld",minn);
  }
	else
	{
		int nn=n-1;
	for(i=1;i<=nn;i++)
	{
		int x,y;
		long long z;
		scanf("%d%d%lld",&x,&y,&z);
		map[x][y]=z;
		map[y][x]=z;
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
			}
		}
	}
	int ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(map[i][j]!=214748364){
				mm[++ans]=map[i][j];
			}
		}
	}
	kk--;
	minn=0;
	sort(mm+1,mm+1+ans,CMP);
	for(i=1;i<=kk;i++)
	{
		minn+=mm[i];
	}
	printf("%d",minn);
	}
	return 0;
}
