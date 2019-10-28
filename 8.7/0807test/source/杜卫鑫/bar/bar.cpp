#include <stdio.h>
#include <string.h>

int dx[5]={0,1,-1,0,0};
int dy[5]={0,0,0,1,-1};
int lz[1005][1005];
int tx,ty,n,flag;
void dfs(int i,int j,int time)
{
	if(i==n&&j==n)
	{
		flag=1;
		return ;
	}
	for(int k=1;k<=4;k++)
	{
		tx=i+dx[k];ty=j+dy[k];
		if(tx<1||tx>n||ty<1||ty>n)continue;
		if(time>=lz[tx][ty]&&lz[tx][ty])continue;
		lz[i][j]=time;
		dfs(tx,ty,time+1);
	}
}
int main()
{
	int T,x,y,nn;
	freopen("bar.in","r",stdin);
	freopen("bar.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		nn=2*n-2;
		memset(lz,0,sizeof(lz));
		flag=0;
		for(int i=1;i<=nn;i++)
		{
			scanf("%d%d",&x,&y);
			lz[x][y]=i;
		}
		dfs(1,1,0);
		if(flag)printf("Yes\n");
		else    printf("No\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
