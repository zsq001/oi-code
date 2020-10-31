#include<cstdio>
int map[1001][1001];
bool mapp[1001][1001],flag;
bool mp[501];
int ii,jj;
int dx[5]={0,1,-1,0,0};
int dy[5]={0,0,0,1,-1};
int n,m;
void dfs(int x,int y,int ans)
{
	int i,j,nx,ny;
	if(flag==true){
		return ;
	}
	for(i=1;i<=4;i++)
	{
		nx=x+dx[i];
		ny=y+dy[i];
		if(nx==ii && ny==jj && ans>3){
			printf("Yes");
			flag=true;
			return ;
		}
		if(nx>0 && nx<=n && ny>0 && ny<=m && mapp[nx][ny]==false && map[x][y]==map[nx][ny])
		{
			mapp[nx][ny]=true;
			dfs(nx,ny,ans+1);
			mapp[nx][ny]=false;
		}
	}
}
int main()
{
	int i,j;
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	getchar();
if(n<=1000 && m<=1000){
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%c",&map[i][j]);
		}
		getchar();
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(mp[map[i][j]]==false){
				ii=i;jj=j;
				mp[map[i][j]]=true;
				dfs(i,j,0);
			}
			if(flag==true){
				return 0;
			}
		}
	}
}
	if(flag==false){
		printf("No");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	return 0;
}
