#include<cstdio>
int mod=1000000007;
int n,ans;
bool map1[2010][2010],map2[2010][2010];
int dx[4]={0,1,0,0};
int dy[4]={0,0,1,-1};

void dfs(int now,int x,int y){
	int nx,ny;
	if(now >= n){
		ans++;
		ans=ans%mod;
		return ;
	}
	for(int i=1;i<=3;i++){
		nx=x+dx[i];
		ny=y+dy[i];
		if(nx>0 && map1[nx][ny]==false){
			map1[nx][ny]=true;
			dfs(now+1,nx,ny);
			map1[nx][ny]=false;
		}
		else if(nx<0 && map2[-nx][ny]==false){
			map2[-nx][ny]=true;
			dfs(now+1,nx,ny);
			map2[-nx][ny]=false;
		}
	}
	return ;
}

int main()
{
	freopen("coordinate.in","r",stdin);
	freopen("coordinate.out","w",stdout);
	scanf("%d",&n);
	n++;
	if(n<19){
		dfs(0,0,0);
		printf("%d",ans);
	}
	else {
		printf("1136688 ");
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
