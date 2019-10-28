#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int n,k;
int re[22],go[22];
int map[22][22],lock[22][10][10],cnt=0,minn=9999999;
bool vis[22];

//struct Maxn
//{
//	int x,y,v;
//}maxn[2];

//void cal(int i,int j,int k)
//{
//	if(j>1&&lock[i][j-1][k]) cnt[i][j][k]++;
//	if(j<5&&lock[i][j+1][k]) cnt[i][j][k]++;
//	if(k<5&&lock[i][j][k+1]) cnt[i][j][k]++;
//	if(k>1&&lock[i][j][k-1]) cnt[i][j][k]++;
//	return ;
//}

void init()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&go[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&re[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&map[i][j]);
//			if(map[i][j]>maxn[2].v)
//			{
//				if(map[i][j]>maxn[1].v)
//				{
//					maxn[1].x=i;
//					maxn[1].y=j;
//					maxn[1].v=map[i][j];
//					continue;
//				}
//				maxn[2].x=i;
//				maxn[2].y=j;
//				maxn[2].v=map[i][j];
//			}
		}
			
	for(int i=1;i<=n;i++)
		for(int j=1;j<=5;j++)
			for(int k=1;k<=5;k++)
				scanf("%d",&lock[i][j][k]);
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=5;j++)
//			for(int k=1;k<=5;k++)
//				cal(i,j,k);
	return ;
}

void dfs_fd(int x,int a)
{
	vis[x]=true;
	if(a>=minn) return ;
	bool jud=false;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]) dfs_fd(i,a+map[x][i]),jud=true;
	}
	if(!jud) 
	{
		minn=min(minn,a+re[x]);
		return ;
	}
}

int main()
{
	freopen("save.in","r",stdin);
	freopen("save.out","w",stdout);
	
	init();
	for(int i=1;i<=n;i++)
	{
		memset(vis,false,sizeof(vis));
		dfs_fd(i,go[i]);
	}
	printf("YES\n");
	printf("%d\n",minn);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
